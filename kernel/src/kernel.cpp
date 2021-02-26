#include "kernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    RealTimeClock rtc;

    GlobalRenderer->Print("Kernel Initialized Successfully");

    while(true){
        ProcessMousePacket();
        GlobalRenderer->CursorPosition.X = 0;
        GlobalRenderer->Print("Time: ");
        GlobalRenderer->Print(to_string((uint64_t)rtc.readHours()));
        GlobalRenderer->Print(":");
        GlobalRenderer->Print(to_string((uint64_t)rtc.readMinutes()));
        GlobalRenderer->Print(":");
        GlobalRenderer->Print(to_string((uint64_t)rtc.readSeconds()));
        GlobalRenderer->Update();
        GlobalRenderer->Clear();
    }

    while(true);
}