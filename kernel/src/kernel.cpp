#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;

    GlobalRenderer->Print("Kernel Initialized Successfully");

    int* test = (int*)0x80000000000;
    *test = 2;

    while(true);
}