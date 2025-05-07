#include <iostream>
#include "../../helper/print_arr.hpp"

template <typename T>
class Vector
{
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
};