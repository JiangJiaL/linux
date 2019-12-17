#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
int main()
{
  //umask设置文件的创建权限掩码，决定了文件的默认权限
  //给定权限 & ~掩码
  umask(0);
  //文件有可能新建文件，则一定要指定文件权限
  int fd = open("./test.txt",O_RDWR | O_CREAT,0777);
  if(fd < 0)
  {
    perror("open error");
    return -1;
  }
  char *ptr = "天已经黑了\n";
  int ret = write(fd,ptr,strlen(ptr));
  if(ret < 0)
  {
    perror("write error");
    return -1;
  }
  printf("write len:%d\n",ret);
  
  lseek(fd,0,SEEK_SET);
  char buf[1024] = {0};
  ret = read(fd,buf,sizeof(buf) -1);
  if(ret < 0)//读取数据出错
  {
    perror("read eroor");
    return -1;
  }else if(ret == 0)//读取数据到文件末尾
  {
    printf("at end od file\n");
    return -1;
  }
  
  printf("read buf:[%s]-[%d]\n",buf,ret);
  close(fd); //关闭文件释放资源
  return 0;

}
