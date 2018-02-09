
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MAXSIZE  200


int main()
{
	setlocale(LC_CTYPE, "");

	wchar_t string[MAXSIZE];

	fgetws(string, MAXSIZE, stdin);
	(*wcsstr(string, L"\n")) = '\0';
	long size = wcslen(string);
	
	int space_flag = 0;

	for(int i = 0; i < (int)size; ++i)
	{
		if((string[i] == L' ' || string[i] == L',') && !space_flag)
			wprintf(L"\n");
		else if(string[i] == L'-')
			continue;
		else
			wprintf(L"%lc", string[i]);
	}

	return 0;
}
