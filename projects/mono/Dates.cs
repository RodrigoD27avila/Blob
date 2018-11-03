using System;

public class Dates
{
    static void Main()
    {
        DateTime today;
        today = DateTime.Now;

        Console.WriteLine(today);
        Console.WriteLine(today.ToShortDateString());
        Console.WriteLine(today.ToShortTimeString());
    }
}
