using System;

public class Bool
{
    static void Main()
    {
        bool male = false;

        Random r = new Random();
        male = Convert.ToBoolean(r.Next(0, 2));

        if (male)
            Console.WriteLine("We will use name John");
        else
            Console.WriteLine("We will use name Victoria");
    }
}
