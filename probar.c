#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i = 0;
    char bar[102];
    int color[] = {0,1,2,3,4,5,6,7,8,9};
    int j = 0;
    memset(bar,0,sizeof(bar));
    while(i <= 100)
    {
       printf("\033[3%dm[%-100s][%d%%]\r",color[j],bar,i);
        bar[i++] = '*';
        fflush(stdout);//刷新
        if(i % 15 == 0)
        {
            ++j;
        }
        usleep(100000);
    }
    printf("\n");
    return 0;
}
