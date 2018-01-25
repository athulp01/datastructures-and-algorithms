#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <time.h>

int heap_size = 100000;

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void max_heapify(int *heap, int node)
{
    int right = (2*node+1)<=heap_size?(2*node+1):-1;
    int left = (2*node)<=heap_size?(2*node):-1;
    if(node <= heap_size)
    {   
        if(right!=-1 &&  heap[node-1]< heap[right-1])
        {
            swap(&heap[right-1], &heap[node-1]);
            //printf("swaped %d and %d\n", heap[node-1], heap[right-1]);
            max_heapify(heap, right ); 
        }
        if(left!=-1 && heap[node-1]< heap[left-1])
        {
            swap(&heap[left-1], &heap[node-1]);
            //printf("swaped %d and %d\n", heap[node-1], heap[left-1]);
            max_heapify(heap, left );
        }
    }
}

void build_max_heap(int heap[])
{
  for(int i=heap_size/2; i>0;i--)
    max_heapify(heap, i);
}

int find_maximum(int heap[])
{
    swap(&heap[0], &heap[heap_size-1]);
    heap_size -- ;
    max_heapify(heap, 1);
    return heap[heap_size];
}
int main()
{
    srand(time(NULL));
    int heap[heap_size];
    FILE *data;
    data = fopen("/home/athulp/datastructures-and-algorithms/data","r+");
    int i=0;
    while (!feof (data)&& i<heap_size)
    {  
      fscanf (data, "%d ", &heap[i]); 
      i++;
    }
    fclose(data);
    build_max_heap(heap);
    printf("Maximum is %d", find_maximum(heap));
}  
    
  
