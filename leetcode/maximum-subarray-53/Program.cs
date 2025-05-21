using System;
using System.Linq;
using System.Globalization;

class Program
{
    static public int solution(int[] list)
    {
        if (list.Length == 1) return list[0];

        int max = list[0];
        int sum = list[0];

        for (int i = 1; i < list.Length; ++i)
        {
            if (sum >= 0)
                sum += list[i];

            else
            {
                sum = 0;
                sum += list[i];
            }


            if (sum > max)
                max = sum;
        }
        return max;
    }
    static public void Main(string[] args)
    {
        int[] list = [1, 2, 3];
        Console.WriteLine(solution(list));
    }
}

