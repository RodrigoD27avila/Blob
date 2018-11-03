using System;

public class Arrays
{
    static void Main()
    {
        int[] numbers = new int[5];
        numbers[0] = 4;
        numbers[1] = 3;
        numbers[2] = 2;
        numbers[3] = 1;
        numbers[4] = 0;

        int len = numbers.Length;

        for (int i=0; i < len; i++)
        {
            Console.WriteLine(numbers[i]);
        }
    }
}

