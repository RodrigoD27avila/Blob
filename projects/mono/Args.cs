using System;

public class Args
{
    static void Main(string[] args)
    {
        int i = 0;
        foreach (string s in args)
        {
            Console.WriteLine("Arg[{0}] = {1}", ++i, s);
        }
    }
}
