#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    char * env = getenv("MYVAL");
    if(env)
    {
        printf("%s\n",env);
    }
    return 0;
}

  /*
int main(int argc,char *argv[],char *env[])
{
    //通过系统调用获取或设置环境变量
    printf("%s\n",getenv("PATH"));
  //运行下边程序 ，结果是 have no MYVAL 说明环境变量根本不存在
	int i;
	char *ptr = getenv("MYVAL");
	if(ptr == NULL)
	{
		printf("have no MYVAL\n");
	}
	else
	{
		printf("%s\n");
	}
  //获取环境变量
  for(i = 0 ; env[i];i++)
  {
		printf("env[%d] = [%s]\n",i ,env[i]);
  }
    //通过第三方environ获取
	extern char **environ;
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("env[%d] = [%s]\n",i ,environ[i]);
  }
	return 0;

}*/
