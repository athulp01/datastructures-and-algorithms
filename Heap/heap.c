
#include <stdio.h>

void max_heapify(int *heap, int node, int heap_size)
{
    if(node <= heap_size)
    {
        int right = 2*node+1;
        int left = 2*node;
        if(heap[node]<(heap[right]<heap[left]?heap[left]:heap[right]))
        {
            int temp = heap[node];
            heap[node] = heap[right];
            heap[right] = temp;
            max_heapify(heap, right, heap_size);
        }
    }
}

int main()
{
   int heap[10] = {16 ,14, 10, 8, 7, 9, 3, 2, 4, 1};
   max_heapify(heap, 2, 10);
   for(int i=0; i< 10; i++)
   {
       printf("%d ", heap[i]);
   }
}



