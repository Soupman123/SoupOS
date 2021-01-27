#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;

    //renderer->rect({100, 100}, {200, 200}, 0xFFFFFF);
    

    renderer->line({100, 300}, {0, 0}, 0xFF00FF);
    renderer->line({0, 0}, {500, 600}, 0xFF00FF);
    renderer->line({500, 600}, {400, 0}, 0xFF00FF);
    renderer->cubeBezier({100, 300}, {0, 0}, {500, 600}, {400, 0}, 0x00FFFF);

    //renderer->PutChar('a'); // broken
    //renderer->Print("abc"); // broken
    //renderer->PutChar('a', 0, 0); // works

    renderer->update();

    //renderer->Print("Kernel Initialized Successfully");
    
    //renderer->Print("CPU NAME: ");
    //renderer->Print(cpu.getName());
    //renderer->update();
    
    while(true);
}