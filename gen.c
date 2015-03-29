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
	int al,len,lim;
	char* s;

	if(argc!=2)
	{
		fprintf(stderr,"error: no arguments given, expecting something like 'gen COUNTER', exiting.\n");
		exit(1);
	}

	if(isnum(argv[1],strlen(argv[1])))al=0;
	else if(isname(argv[1],strlen(argv[1])))al=1;
	else
	{
		fprintf(stderr,"error: special characters in the counter, exiting.\n");
		exit(2);
	}

	len=al?strlen(argv[1]):(atoi(argv[1])<=1?1:ceil(log(atoi(argv[1]))/log(26)));
	s=(char*)malloc((sizeof(char)*len)+1);

	if(!s)
	{
		fprintf(stderr,"error: could not allocate any memory, exiting.\n");
		exit(3);
	}

	s[len]='\0';
	lim=al?:atoi(argv[1]);
	while(len-->0)s[len]='a';
	
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
