#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
     flag=0;
     for(j=0;j<n-1;j++)
     {
         if(A[j]>A[j+1])
         swap(&A[j],&A[j+1]);
         flag=1;
     }
    
    if(flag==0)
    break;
    }
}
int main()
{   
    int A[]={67,55,87,90,21,43,23,89,99,76};
    Bubble(A,10);
    for(int i=0;i<10;i++)
    {
        printf("%d",A[i]);
        printf("\n");
        
    }
    return 0;
}
