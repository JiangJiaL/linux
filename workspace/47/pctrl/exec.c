//程序替换接口
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
  char *env[3] = {NULL};
  env[0] = "MYVAL = 1000";
  env[1] = NULL;
  int i;
  for(i = 0 ; i < argc;i++)
  {
    printf("argv[%d] = [%s]\n",i,argv[i]);
  }
 //execl("/bin/ls","ls","-l",NULL);
  //execlp("myenv","ls","-l",NULL);
  //execle("./myenv","myenv","-l",NULL,env);
  char *arg[3] = {NULL};
  arg[0] = "myenv";
  arg[1] = "-i";
  arg[2] = "NULL";
  execv("./myenv",arg);
    printf("hello\n");



  return 0;
}
