#include "memory.h"

uint64_t GetMemorySize(EFI_MEMORY_DESCRIPTOR* mMap, uint64_t mMapEntries, uint64_t mMapDescSize){

    static uint64_t memorySizeBytes = 0;
    if (memorySizeBytes > 0) return memorySizeBytes;

    for (int i = 0; i < mMapEntries; i++){
        EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i * mMapDescSize));
        memorySizeBytes += desc->numPages * 4096;
    }

    return memorySizeBytes;

}

void memset(void* start, uint8_t value, uint64_t num){
    for (uint64_t i = 0; i < num; i++){
        *(uint8_t*)((uint64_t)start + i) = value;
    }
}

void memcpy(void *__restrict dst, const void *__restrict src, uint64_t num){
    asm volatile ("cld; rep movsb" : "+c" (num), "+S" (src), "+D" (dst) :: "memory");
}

void* malloc(size_t size) {
    if(size < 4096)
        return GlobalAllocator.RequestPage();
    else {
        void* base = GlobalAllocator.RequestPage();
        GlobalAllocator.LockPages(base,(uint64_t)((size/4096)+1));
        return base;
    }
}