#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void strninc(char* s, int len);
int isnum(char* s, int len);
int isname(char* s, int len);

int main(int argc, char** argv)
{
	char* s;

	if(argc!=2)
	{
		fprintf(stderr,"error: no arguments given, expecting something like 'gen COUNTER', exiting.\n");
		exit(1);
	}

	

	while(al?strncmp(s,argv[1],strlen(s)):lim-->1)
	{
		puts(s);
		strninc(s,strlen(s));
	}
	
	puts(s);

	free(s);
	return 0;
}

int isnum(char* s, int len)
{
	char* t=s;
	while(isspace(*s))s++;
	if(!(isdigit(*s)||*s=='-'))return 0;
	while(isdigit(*s++))
		if(!*s||(t-s)>=len)
			return 1;
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
