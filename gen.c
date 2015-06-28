#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

void strninc(char* s, int len);
int isname(char* s, int len);

int main(int argc, char** argv)
{
	char* s;
	int len, lim=0;

	if(argc!=2)
	{
		fprintf(stderr,"error: no arguments given, expecting something like 'gen COUNTER', exiting.\n");
		exit(1);
	}

	len=strlen(argv[1]);
	errno=0;

	if(isname(argv[1],len))
		goto prbegin;

	lim=strtol(argv[1],NULL,10);
	len=ceil(log(lim)/log(26));

	printf("%i\n", len);

	if(errno)
	{
		fprintf(stderr,"error: no number found in COUNTER, exiting.\n");
		exit(2);
	}

	prbegin:
	s=(char*)malloc(sizeof(char)*len);

	if(!s)
	{
		fprintf(stderr,"error: no memory left, exiting.\n");
		exit(3);
	}

	s[len]='\0';
	while(len-->0)s[len]='a';

	printf("%i\n",lim);

	while(lim?strncmp(s,argv[1],strlen(s)):lim-->1)
	{
		puts(s);
		strninc(s,strlen(s));
	}
	
	puts(s);

	free(s);
	return 0;
}

int isname(char* s, int len)
{
	char* t=s;
	while(isspace(*s))s++;
	while(islower(*s++))
		if(!*s||(t-s)>=len)
			return 1;
	return 0;
}

void strninc(char* s, int len)
{		
		char* t=s;
		s+=len-1;
		for(;*s=='z'&&s!=t;s--)
				*s='a';
		++(*s);
}
