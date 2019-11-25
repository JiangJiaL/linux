#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf("*******\n");
	pid_t pid = fork();
	if(pid  < 0)
	{
		perror("fork");
		return 1;
	}
  else if(pid == 0)
  {
      //这段代码只是子进程进
      printf("I am child ,pid: %d\n",getpid());
      sleep(10);
  }
  else 
  {
      //这段代码只有父进程进
      printf("I am parent ,pid: %d\n",getpid());
      sleep(3);
      exit(0);
  }
	return 0;
}
