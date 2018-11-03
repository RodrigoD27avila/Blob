using System;

public class Null
{
    static void Main()
    {
        Nullable<bool> male = null;
        int? age = null;

        Console.WriteLine(male.HasValue);
        Console.WriteLine(age.HasValue);
    }
}

