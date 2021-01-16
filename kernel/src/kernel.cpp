#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;

    GlobalRenderer->Print("Kernel Initialized Successfully");

    renderer->line({100,100}, {400, 0}, 0xFFFFFF);
    
    while(true);
}