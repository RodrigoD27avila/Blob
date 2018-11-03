#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    wchar_t str[] = L"同友館 H.ウイリアムデトマ";
    wprintf(L"long string = %ls\n", str);
    return 0;
}
