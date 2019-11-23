#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int fun(int arr[],int n)
{
    int i ;
    for ( i = 0;i < n ;i ++)
    {
        arr[i] = i;
        printf("%d\n ",arr[i]);
        
    }
    
}

int main()
{
    int arr[] = {0};
    fun(arr,5);
    return 0;
}
