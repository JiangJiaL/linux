//这是一个黄牛抢票的程序---多个黄牛同时从火车站购票系统抢票，从这个程序中体会互斥操作的重要性
//一个黄牛就是一个线程 有一个变量表示当前票数就可以
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int tickets = 100;
pthread_mutex_t mutex;
void *thr_tout(void *arg)
{
    while(1)
    {
        //加锁，一定是再访问临界资源之前加锁
        //pthread_mutex_lock 阻塞加锁
        //pthread_mutex_trylock 非阻塞加锁
        //pthread_mutex_timedlock 限时等待的阻塞加锁
        pthread_mutex_lock(&mutex);
        if(tickets > 0)
        {
            usleep(1000);
            printf("tout:%p - get a ticket:%d\n",pthread_self(),tickets);
            tickets--;
            //解锁一定是放在临界资源访问完毕之后
            pthread_mutex_unlock(&mutex);
        }
        else{
            //加锁之后再任意有可能退出线程的地方都要解锁
            pthread_mutex_unlock(&mutex);
            printf("tout:%p exit\n",pthread_self());
            pthread_exit(NULL);
        }
    }
    return NULL;
}
int main()
{
    int i = 0,ret;
    pthread_t tid[4];
    //互斥锁的初始化,一定要放在创建线程之前
    //pthread_mutex_init()
    //pthread_mutex_t mutex = PTHREAD_MUTEX_INITALIZER;
    pthread_mutex_init(&mutex,NULL);
    for(;i < 4; i++)
    {
        ret = pthread_create(&tid[i],NULL,thr_tout,NULL);
        if(ret != 0)
        {
            printf("thread create error\n");
            return -1;
        }
    }
    for(i = 0; i< 4; i++)
    {
        pthread_join(tid[i],NULL);

    }
    //互斥锁的销毁，一定要放在完全不使用的时候
    pthread_mutex_destroy(&mutex);
    return 0 ;
}
