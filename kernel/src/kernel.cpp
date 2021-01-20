#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;

    renderer->clear();
    GlobalRenderer->Print("Kernel Initialized Successfully");

    renderer->rect({100, 100}, {200, 200}, 0xFFFFFF);

    renderer->line({200, 200}, {200, 600}, 0xFF00FF);

    renderer->line({100, 300}, {300, 10}, 0xFF00FF);
    renderer->line({300, 10}, {600, 400}, 0xFF00FF);
    renderer->quadBezier({100, 300}, {300, 10}, {600, 400}, 0x00FFFF);
    
    while(true);
}