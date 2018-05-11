// BurOflow.cpp : For evaluation of Static Analysis buffer overflow check

#include <string.h>
#include <stdio.h>

#define BUFSIZE 16

int main()
{
	int strlength;
	char instring[BUFSIZE], outstring[BUFSIZE];

	while (1) {
		instring[0] = '.';
		rewind(stdin);
		printf("\n\nYour test word (max %d non-whitespace chars; '.' to stop)?  ", BUFSIZE - 1);
		sprintf(outstring, "%%%ds", BUFSIZE - 1);
		scanf(outstring, instring);
		rewind(stdin);
		if (instring[0] == '.') break;
		sprintf(outstring, instring);
		strlength = strlen(outstring);
		if (strlength < BUFSIZE) printf("\n   Your test word is:  %s  (%d chars)", outstring, strlength);
		else printf("\n   *** BUFFER OVERFLOW (by %d chars) ***", strlength - BUFSIZE + 1);
	}
	return 0;
}
