// BurOflow.cpp : For evaluation of Static Analysis buffer overflow check

#include <string.h>
#include <stdio.h>

int main()
{
	int strlength;
	char instring[16], outstring[16];

	while (1) {
		printf("\n\nYour test word (max 15 non-whitespace chars; '.' to stop)?  ");
		scanf("%15s", instring);
		rewind(stdin);
		if (instring[0] == '.') break;
		sprintf(outstring, instring);
		strlength = strlen(outstring);
		if (strlength < 16) printf("\n Your test phrase is:  %s  (%d chars)", outstring, strlength);
		else printf("\n*** BUFFER OVERFLOW (by %d chars) ***", strlength - 15);
	}
	return 0;
}

