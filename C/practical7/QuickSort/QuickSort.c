#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)
        swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}
void quicksort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        quicksort(A,l,j);
        quicksort(A,j+1,h);
    }
}
int main()
{
    int A[]={11,13,7,56,98,44,89,90,32,14,__INT32_MAX__},n=11,i;
     quicksort(A,0,10);
     for(i=0;i<10;i++)
     {
         printf("%d",A[i]);
         printf("\n");
         
     }
     return 0;

}
