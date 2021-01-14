#include "interrupts.h"
#include "../panic.h"
#include "../IO.h"
#include "KBScanCodeSet1.cpp"

__attribute__((interrupt)) void PageFault_Handler(struct interrupt_frame* frame){
    Panic("Page_Fault_Detected");
    while(true);
}

__attribute__((interrupt)) void DoubleFault_Handler(struct interrupt_frame* frame){
    Panic("Double_Fault_Detected");
    while(true);
}

__attribute__((interrupt)) void GPFault_Handler(struct interrupt_frame* frame){
    Panic("General_Protection_Fault_Detected");
    while(true);
}

__attribute__((interrupt)) void KeyboardInt_Handler(struct interrupt_frame* frame){
    uint8_t scancode = inb(0x60);
    uint8_t chr = 0;

	if (scancode < 0x3A){
        GlobalRenderer->PutChar(KBSet1::ScanCodeLookupTable[scancode], GlobalRenderer->CursorPosition.X, GlobalRenderer->CursorPosition.Y);
        GlobalRenderer->CursorPosition.X+=8;
        if(GlobalRenderer->CursorPosition.X + 8 > GlobalRenderer->TargetFramebuffer->Width){
            GlobalRenderer->CursorPosition.X = 0;
            GlobalRenderer->CursorPosition.Y += 16;
        }
	}
    PIC_EndMaster();
}

void PIC_EndMaster(){
    outb(PIC1_COMMAND, PIC_EOI);
}

void PIC_EndSlave(){
    outb(PIC2_COMMAND, PIC_EOI);
    outb(PIC1_COMMAND, PIC_EOI);
}
   

void RemapPIC(){
    uint8_t a1, a2; 

    a1 = inb(PIC1_DATA);
    io_wait();
    a2 = inb(PIC2_DATA);
    io_wait();

    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();

    outb(PIC1_DATA, 0x20);
    io_wait();
    outb(PIC2_DATA, 0x28);
    io_wait();

    outb(PIC1_DATA, 4);
    io_wait();
    outb(PIC2_DATA, 2);
    io_wait();

    outb(PIC1_DATA, ICW4_8086);
    io_wait();
    outb(PIC2_DATA, ICW4_8086);
    io_wait();

    outb(PIC1_DATA, a1);
    io_wait();
    outb(PIC2_DATA, a2);

}