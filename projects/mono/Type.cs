using System;

public class Type
{
    static void Main()
    {
        int   a = 0;
        uint  b = 0;
        byte  c = 0;
        char  d = ' ';
        float e = 0.0f;

        Console.WriteLine(a.GetType());
        Console.WriteLine(b.GetType());
        Console.WriteLine(c.GetType());
        Console.WriteLine(d.GetType());
        Console.WriteLine(e.GetType());
    }
}
