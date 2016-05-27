/*
    Implementaion of Priority Queue using MIN-HEAP
    A priority Queue is a datastructure for maintaining a set of element.
    each with associated with a key
    Following Operations Allowed ::
    1.HEAP-MINIMUM
    2.HEAP-EXTRACT-MIN
    3.HEAP-DECREASE-KEY
    4.MIN-HEAP-INSERT
*/
#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
int heapsize=0;
int heapMin(int *a)
{
    if(heapsize == 0)
        return 0;        
    return a[1];
}
int parent(int l)
{
    return l/2;
}
void swap(int *p,int *q)
{
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}
void heapDecKey(int *a,int k,int val)
{
    if(a[k] < val)
    {
        printf("Error...");
        return;
    }
    a[k] = val;
    while(k > 1 && a[parent(k)] > a[k])
    {
        swap(&a[parent(k)],&a[k]);
        k = parent(k);
    }
} 
void insert(int *a,int val)
{
    heapsize +=1;
    a[heapsize] = INF;
    heapDecKey(a,heapsize,val);
}
int left(int l)
{
    return 2*l;
}
int right(int l)
{
    return 2*l+1;
}
void MinHeapify(int *a,int i)
{
    int l = left(i);
    int r = right(i);
    int smallest=i;
    if(l <= heapsize && a[l] < a[i])
        smallest = l;
    else 
        smallest = i;
    if(r <= heapsize && a[smallest] > a[r])
        smallest = r;
    if(smallest != i) 
    {
        swap(&a[smallest],&a[i]);
        MinHeapify(a,smallest);
    }  
}
void heapExtractMin(int *a)
{
    if(heapsize < 1)
        return;
    a[1] = a[heapsize];
    heapsize -= 1;
    MinHeapify(a,heapsize);
}    
int main()
{
    int tmp,choice,k;
    int arr[100000];
    printf("priority queue\n");
    printf("1.Get the topmost element\n");
    printf("2.Extract min value from a queue\n");
    printf("3.Decrease a particular key \n");
    printf("4.Insert an element \n");
    while(1)
    {
        printf("> "); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : tmp = heapMin(arr);
                     printf("%d\n",tmp);
                     break;
            case 2 : heapExtractMin(arr);
                     break;
            case 3 : printf("Enter a new key : ");
                     scanf("%d",&k);
                     printf("Enter a new Value : ");
                     scanf("%d",&tmp);
                     heapDecKey(arr,k,tmp);
                     break;
            case 4 : printf("Enter an Element to insert : " );
                     scanf("%d",&tmp);
                     insert(arr,tmp);
                     break;
            default : printf("Invalid choice **\n");            
        }
    }
    return 0;
}
