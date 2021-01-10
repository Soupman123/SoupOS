#include "panic.h"
#include "BasicRenderer.h"

void Panic(const char* panicMessage){
    GlobalRenderer->Clear(0x00ff0000);

    GlobalRenderer->CursorPosition = {0, 0};

    GlobalRenderer->Color = 0;

    GlobalRenderer->Print("SoupOS has encountered an issue, please restart your machine. ERR_CODE: ");
    GlobalRenderer->Print(panicMessage);
} 