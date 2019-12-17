#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<error.h>
#include<string.h>
int main()
{
	printf("nihao~~~");
	sleep(3);
	_exit(0);
	_exit (99);
	int i = 0;
	for(; i < 256;i++)	
	{
	printf("err:[%d] = [%s]\n",i,strerror(i));
	}
	return 0;
}
