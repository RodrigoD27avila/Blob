using System;

public class Foo
{
    static void Main()
    {
        Bar.Init();
        Console.WriteLine("Foo");
    }
}

public class Bar
{
    public static void Init()
    {
        Console.WriteLine("Bar");
    }
}
