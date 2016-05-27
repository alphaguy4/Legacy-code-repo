/*
    **HEAP SORT**
    Author : alphaguy4  
*/
#include<stdio.h>
#include<stdlib.h>
int left(int l)
{
    return 2*l;
}
int right(int l)
{
    return 2*l+1;
}
void swap(int *p,int *q)
{
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}
void MAX_HEAPIFY(int *arr,int i,int heapsize)
{
    int l = left(i);
    int r = right(i);
    int largest=-1;
    if( l <= heapsize && arr[l] > arr[i] )
        largest = l;
    else
        largest = i;
    if( r <= heapsize && arr[r] > arr[largest])
        largest = r;
    if(largest != i && largest != -1)
    {
        swap(&arr[largest],&arr[i]);
        MAX_HEAPIFY(arr,l,heapsize);
    }
}
void BuildMaxHeap(int *arr,int n)
{
    int i;
//    printf("2\n");
    int heapsize = n;
    for(i = heapsize >> 1;i > 0;i--)
    {
        MAX_HEAPIFY(arr,i,n);
         //for(i=1;i<=n;i++)
        //printf("%d ",*(arr+i));
       // printf("\n");

    }
    return;
}
void HeapSort(int *arr,int n)
{
    int i;    
    BuildMaxHeap(arr,n);
    int heapsize = n;
    while(heapsize > 1) 
    {
        swap(&arr[1],&arr[heapsize]);
        heapsize-=1;
        MAX_HEAPIFY(arr,1,heapsize);
    }
    return;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int *arr = (int *)malloc((n+2)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
    }
    HeapSort(arr,n);
    for(i=1;i<=n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    free(arr);
    return 0;
}

