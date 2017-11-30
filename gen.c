#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

unsigned isname(char* s, size_t len)
{
	char* t=s;
	while(isspace(*s))s++;
	while(islower(*s++))
		if(!*s||(unsigned)(t-s)>=len)
			return 1;
	return 0;
}

void strninc(char* s, size_t len)
{
		char* t=s;
		s+=len-1;
		for(;*s=='z'&&s!=t;s--)
				*s='a';
		++(*s);
}

int main(int argc, char** argv)
{
	char* s;
	unsigned long len, c, lim=0;

	if(argc!=2)
	{
		fprintf(stderr, "gen counter\n");
		exit(1);
	}

	len=strlen(argv[1]);
	errno=0;

	if(!isname(argv[1], len))
	{
		lim=strtol(argv[1], NULL, 10);
		len=(lim==1?lim:ceil(log(lim)/log(26)));

		if(errno||lim<=0)
		{
			fprintf(stderr, "error: no usable number found in counter, exiting.\n");
			exit(2);
		}
	}

	s=(char*)calloc(sizeof(char), len+1);

	if(!s)
	{
		fprintf(stderr, "error: no memory left, exiting.\n");
		exit(3);
	}

	s[len]='\0';

	for(c=0; c<len; c++)s[c]='a';

	while(lim?lim-->1:strncmp(s, argv[1], len))
	{
		puts(s);
		strninc(s, strlen(s));
	}

	puts(s);

	free(s);
	return 0;
}
