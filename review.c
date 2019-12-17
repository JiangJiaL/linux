#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  FILE *fp = fopen("./tmp.txt","w+");
  if(fp == NULL)
  {
    perror("fopen error");
    return -1;
  }
  fseek(fp,10,SEEK_END);
  char * ptr = "今天天气很好\n";
 // char ptr[] = "冬天适合睡懒觉\n";
  int ret =  fwrite(ptr,1,strlen(ptr),fp);
  if(ret <= 0)
  {
    perror("fwrite error");
    return -1;
  }
  printf("ret:%d\n",ret);
  printf("\n");
  fseek(fp,0,SEEK_SET);
  char buf[1024] = {0};
  ret = fread(buf,1,1023,fp);
  if(ret == 0)
  {
    perror("fread error");
    return -1;
  }
  printf("read buf:[%s]-[%d]\n",buf+10,ret);
  fclose(fp);
  return 0;
}
