#include "kernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    RealTimeClock rtc;

    GlobalRenderer->Print("Kernel Initialized Successfully");

    uint64_t oldT = 70;
    uint64_t fps = 0;
    uint64_t Rfps = 0;

    while(true){
        ProcessMousePacket();
        GlobalRenderer->CursorPosition = {0, 0};
        GlobalRenderer->Print("Time: ");
        GlobalRenderer->Print(to_string((uint64_t)rtc.readHours()));
        GlobalRenderer->Print(":");
        GlobalRenderer->Print(to_string((uint64_t)rtc.readMinutes()));
        GlobalRenderer->Print(":");
        GlobalRenderer->Print(to_string((uint64_t)rtc.readSeconds()));
        
        GlobalRenderer->Next();
        GlobalRenderer->DrawOverlayMouseCursor(MousePointer, MousePosition, 0xffffffff);
        GlobalRenderer->Print("{");
        GlobalRenderer->Print(to_string((uint64_t)MousePosition.X));
        GlobalRenderer->Print(", ");
        GlobalRenderer->Print(to_string((uint64_t)MousePosition.Y));
        GlobalRenderer->Print("}");

        GlobalRenderer->Next();
        GlobalRenderer->Print("FPS: ");
        GlobalRenderer->Print(to_string(Rfps));
        fps++;

        if((uint64_t)rtc.readSeconds() != oldT){
            Rfps = fps;
            oldT = rtc.readSeconds();
            fps = 0;
        }

        GlobalRenderer->Update();
        GlobalRenderer->Clear();
    }

    while(true);
}