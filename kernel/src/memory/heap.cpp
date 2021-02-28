#include "heap.h"

void* heapStart;
void* heapEnd;
HeapSegHdr* LastHdr;

void InitializeHeap(void* heapAddress, size_t pageCount){
    void* pos = heapAddress;

    for (size_t i = 0; i < pageCount; i++){
        GlobalPTM.MapMemory(pos, GlobalAllocator.RequestPage());
        pos = (void*)((size_t)pos+0x1000);
    }
    
    size_t heapLength = pageCount * 0x1000;

    heapStart = heapAddress;
}

void* malloc(size_t size);
void free(void* address);
void ExpandHeap(size_t length);