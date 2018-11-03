using System;
using System.Collections.Generic;

public class Lambda
{
    static void Main()
    {
        List<int> list = new List<int>()
            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        List<int> sublist = list.FindAll(val => val > 3);

        foreach (int i in sublist)
        {
            Console.WriteLine(i);
        }
    }
}
