using System;

public class Strings
{
    static void Main()
    {
        string str1 = "There are 10";
        string str2 = " apples";

        Console.WriteLine(str1 + str2);
        Console.WriteLine("The length of the first string is " +
                str1.Length.ToString() + " characters");

        Console.WriteLine(str1 == str2);

        string str3 = "Rodrigo";
        string str4 = "rodrigo";

        Console.WriteLine(string.Compare(str3, str4, true));
        Console.WriteLine(string.Compare(str3, str4, false));

        string[] items = new string[] {"C#", "Visual Basic", "Java", "Perl"};

        string langs = string.Join(",", items);
        Console.WriteLine(langs);

        string[] ls = langs.Split(',');

        foreach (string l in ls)
        {
            Console.WriteLine(l);
        }

        String str = "Rodrigo D'avila";
        Console.WriteLine(str.Contains("e"));
        Console.WriteLine(str.IndexOf("e"));
        Console.WriteLine(str.LastIndexOf("e"));
        Console.WriteLine(str.ToLower());
        Console.WriteLine(str.ToUpper());
    }
}
