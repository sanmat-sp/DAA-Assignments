// Name: SANMAT SANJAYAKUMAR PAYAGOUDAR
// SRN: PES1UG20CS385
#include "heap.h"
#include <stdlib.h>



void init_heap(heap_t *heap, int max_size) {
    heap->size = 0;
    heap->max_size = max_size;
    heap->array = (int*)malloc(sizeof(int)*max_size);
}

void heapify(heap_t *heap, int *count_ptr)
{
    int i,c,p,elmt;
    for(i=1;i<heap->size;i++)
    {
        elmt=heap->array[i];
        c=i;
        p=(c-1)/2;
        while(c>0 && heap->array[p]<elmt)
        {
            *count_ptr = *count_ptr+1;
            heap->array[c]=heap->array[p];
            c=p;
            p=(c-1)/2;
        }
        heap->array[c]=elmt;
    }    
}
void insert(heap_t *heap, int key, int *count_ptr) {
    if(heap->size == heap->max_size)
    {
        return;
    }
    heap->size++;
    heap->array[heap->size-1] = key ;
    heapify(heap , count_ptr);
}

int extract_max(heap_t *heap, int *count_ptr) {
    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size];
    heap->size--;
    heapify(heap,count_ptr);
    return max;
}

int search(const heap_t *heap, int key, int *count_ptr) {
    int res=-1;
    for(int i=0;i<heap->size;i++)
    {
        if(heap->array[i]==key)
        {
            res = heap->array[i];
        }   
        *count_ptr=*count_ptr+1;
    }
    return res;
}

int find_max(const heap_t *heap, int *count_ptr) {
    return heap->array[0];
}

int find_min(const heap_t *heap, int *count_ptr) {
    int min = 999999;
    for(int i=(heap->size)/2 ; i < (heap->size) ; i++)
    {
        if(heap->array[i]<min)
        {
            min = heap->array[i];
        }
    *count_ptr = *count_ptr + 1;
    }
    return min;
}

void clear_heap(heap_t *heap) {
    heap->size=0;
}

void free_heap(heap_t *heap) {
    free(heap);
}