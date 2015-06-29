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
	len=(lim==1?lim:ceil(log(lim)/log(26)));

	if(errno||lim<=0)
	{
		fprintf(stderr,"error: no usable number found in COUNTER, exiting.\n");
		exit(2);
	}

	prbegin:
	s=(char*)malloc(sizeof(char)*len+1);

	if(!s)
	{
		fprintf(stderr,"error: no memory left, exiting.\n");
		exit(3);
	}

	s[len]='\0';
	for(int c=0; c<len; c++)s[c]='a';

	while(lim?lim-->1:strncmp(s,argv[1],len))
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
