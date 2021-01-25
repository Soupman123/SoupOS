#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;
    CPU cpu;

    while(true){
        renderer->clear(0x0);
        
        //renderer->rect({100, 100}, {200, 200}, 0xFFFFFF);
        renderer->line({100, 300}, {0, 0}, 0xFF00FF);
        renderer->line({0, 0}, {500, 600}, 0xFF00FF);
        renderer->line({500, 600}, {400, 0}, 0xFF00FF);
        renderer->cubeBezier({100, 300}, {0, 0}, {500, 600}, {400, 0}, 0x00FFFF);
        renderer->update();

        GlobalRenderer->Print("Kernel Initialized Successfully");
        GlobalRenderer->Next();
        GlobalRenderer->Print("CPU NAME: ");
        GlobalRenderer->Print(cpu.getName());
        GlobalRenderer->Next();
        GlobalRenderer->Print("CPU VENDOR: ");
        GlobalRenderer->Print(cpu.getVendor());
        GlobalRenderer->Next();
        GlobalRenderer->Next();
        cpu.getFeatures();
        for(unsigned int i = 0;i<cpu.cpuFeatures;i++){
            GlobalRenderer->Print(cpu.parsedFeatures[i]);
            GlobalRenderer->Next();
        }
    }
    while(true);
}