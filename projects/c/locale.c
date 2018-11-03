#include <stdio.h>
#include <locale.h>

int
main ()
{
	if (!setlocale (LC_ALL, ""))
	{
		fprintf(stderr, "Can't set the specified locale! " 
				"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}

	const struct lconv * const currentlocale = localeconv();
	fprintf (stdout, "In the current locale, the default"
			"currency symbol is: %s\n",
				currentlocale->currency_symbol);

	fprintf(stdout, "%ls\n", L"Schöne Grüße");
	fprintf(stdout, "%ls\n", L"日本人");

	return 0;
}
