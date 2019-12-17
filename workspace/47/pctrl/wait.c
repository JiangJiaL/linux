#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(-1);
	} else if(pid == 0) {
		sleep(5);
		exit(99);
	}
	int status = -1;
	while(waitpid(-1,&status,WNOHANG)==0)
	{
		printf("等会\n");
		sleep(1);
	}
  if(!(status & 0x7f)){
       printf("child exit retval:%d\n",(status >> 8) & 0xff);       
  }
  else{
    printf("possess error\n");
  }
	//wait(NULL);
	int ret = waitpid(pid,NULL,WNOHANG);
	if(ret < 0){
	perror("waitpid error");
	}else if(ret == 0){
		printf("have no chile exit\n");
	}else {
		printf("pid:%d child exited\n",ret);
	}
	while(1) {
  	 	printf("打麻将~~~\n");
		sleep(1);
	}
	return 0;
}
