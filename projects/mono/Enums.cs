using System;

public class Enums
{
    enum Days
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    }

    static void Main()
    {
        Days day = Days.Monday;

        if (day == Days.Monday)
            Console.WriteLine("Its Monday");

        foreach (int i in Days.GetValues(typeof(Days)))
            Console.WriteLine(i);
    }
}

