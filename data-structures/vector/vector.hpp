#pragma once
#include <iostream>
#include "../../helper/print_arr.hpp"

template <typename T>
class Vector
{
public:
    T *data;
    size_t size;
    size_t capacity;

    unsigned closest_non_lesser_power_of_two(unsigned val)
    {
        unsigned res = 1;
        while (val > res)
            res *= 2;

        return res;
    }

    void resize()
    {
        capacity *= 2;
        T *temp = new T[capacity];
        for (unsigned i = 0; i < size; ++i)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

public:
    Vector(std::initializer_list<T> init)
    {
        size = init.size();
        capacity = closest_non_lesser_power_of_two(size);
        data = new T[capacity];
        unsigned i = 0;
        for (const auto &elem : init)
        {
            data[i++] = elem;
        }
    }

    Vector()
    {
        size = 0;
        capacity = 1;
        data = new T[1];
    }

    // Vector(unsigned size)
    // {
    //     this->size = size;
    //     capacity = closest_non_lesser_power_of_two(size);
    //     data = new T[capacity];
    // }

    Vector(const Vector &other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (unsigned i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    Vector &operator=(Vector other)
    {
        size = other.size;
        capacity = other.capacity;
        T *temp = new T[capacity];

        for (unsigned i = 0; i < size; ++i)
            temp[i] = other.data[i];

        delete[] data;
        data = temp;

        return *this;
    }

    Vector &operator=(std::initializer_list<T> init)
    {
        size = init.size();
        capacity = closest_non_lesser_power_of_two(size);
        T *temp = new T[capacity];

        unsigned i = 0;
        for (const auto &elem : init)
            temp[i++] = elem;

        delete[] data;
        data = temp;

        return *this;
    }

    T &operator()(unsigned index)
    {
        return data[index];
    }

    T *operator[](unsigned index)
    {
        return (data + index);
    }

    ~Vector()
    {
        delete[] data;
    }

    void print() const
    {
        print_arr(data, size);
    }

    void push(const T &elem)
    {
        if (size == capacity)
            resize();

        data[size++] = elem;
    }

    unsigned length()
    {
        return size;
    }

    void print_length()
    {
        std::cout << size << std::endl;
    }

    Vector<T> subvector(unsigned start, unsigned end)
    {
        Vector<T> subvec;
        for (int i = start; i < end; ++i)
        {
            subvec.push(this->data[i]);
        }

        return subvec;
    }

    Vector<T> subvector(unsigned start)
    {
        Vector<T> subvec;
        for (int i = start; i < this->length(); ++i)
        {
            subvec.push(this->data[i]);
        }

        return subvec;
    }

    T total()
    {
        T sum = 0;
        for (int i = 0; i < this->length(); ++i)
            sum += this->data[i];

        return sum;
    }

    void pop_back()
    {
        Vector<T> temp(subvector(0, this->length() - 1));
        *this = temp;
    }

    void pop_start()
    {
        Vector<T> temp(subvector(1, this->length()));
        *this = temp;
    }

    // works on integers only
    int max()
    {
        unsigned buff = 0;
        buff -= 1; // UNSIGNED INT_MAX
        buff /= 2; // INT_MAX
        int max = buff;
        max += 1; // INT_MIN

        for (int i = 0; i < this->length(); ++i)
            max < this->data[i] ? max = this->data[i] : max = max;

        return max;
    }

    int min()
    {
        unsigned buff = 0;
        buff -= 1; // UNSIGNED INT_MAX
        buff /= 2; // INT_MAX
        int min = buff;

        for (int i = 0; i < this->length(); ++i)
            min > this->data[i] ? min = this->data[i] : min = min;

        return min;
    }
};