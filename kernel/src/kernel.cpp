#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;

    GlobalRenderer->Print("Kernel Initialized Successfully");

    renderer->rect({100, 100}, {200, 200}, 0xFFFFFF);
    renderer->line({200, 200}, {300, 600}, 0xFF00FF);
    
    while(true);
}