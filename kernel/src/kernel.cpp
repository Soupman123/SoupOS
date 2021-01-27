#include "KernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){
    // Run Kernel Utilities
    KernelInfo KernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = KernelInfo.pageTableManager;

    /*renderer->line({100, 300}, {0, 0}, 0xFF00FF);
    renderer->line({0, 0}, {500, 600}, 0xFF00FF);
    renderer->line({500, 600}, {400, 0}, 0xFF00FF);
    renderer->cubeBezier({100, 300}, {0, 0}, {500, 600}, {400, 0}, 0x00FFFF);*/

    char** CPUFeatures = cpu.getFeatures();

    unsigned int frameCount=0;
    unsigned int lastSec=0;
    unsigned int fps=0;

    while(true){
        renderer->clear(0x0);
        renderer->textCursorPosition = {0,0};
        renderer->Print("Kernel Initialized Successfully");
        renderer->Next();
        renderer->Next();

        renderer->Print("Time: ");
        renderer->Print(to_string((uint64_t)rtc.readHours()));
        renderer->Print(":");
        renderer->Print(to_string((uint64_t)rtc.readMinutes()));
        renderer->Print(":");
        renderer->Print(to_string((uint64_t)rtc.readSeconds()));
        renderer->Next();

        renderer->Print("Date: ");
        renderer->Print(to_string((uint64_t)rtc.readMonth()));
        renderer->Print("/");
        renderer->Print(to_string((uint64_t)rtc.readDay()));
        renderer->Print("/");
        renderer->Print(to_string((uint64_t)rtc.readYear()));
        renderer->Next();
        renderer->Next();

        if(lastSec==rtc.readSeconds()){
            frameCount++;
        }else{
            lastSec=rtc.readSeconds();
            fps=frameCount;
            frameCount=0;
        }
        renderer->Print("FPS: ");
        renderer->Print(to_string((uint64_t)fps));
        renderer->Next();
        renderer->Next();

        renderer->Print("CPU NAME: ");
        renderer->Print(cpu.getName());
        renderer->Next();
        renderer->Print("CPU VENDOR: ");
        renderer->Print(cpu.getVendor());
        renderer->Next();
        renderer->Print("CPU FEATURES: ");
        for(unsigned int i = 0;i<cpu.cpuFeatures;i++){
            renderer->Print(CPUFeatures[i]);
            renderer->Print(", ");
        }
        renderer->ClearChar(0);
        renderer->ClearChar(0);
        
        renderer->update();
    }
    while(true);
}