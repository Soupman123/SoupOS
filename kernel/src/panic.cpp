#include "panic.h"
#include "drivers/display/Rendering.h"

void Panic(const char* panicMessage){
    renderer->clear(0x1a2040);

    renderer->textCursorPosition = {0, 0};

    renderer->Print("SoupOS has encountered an issue, please restart your machine. :( ERR_CODE: ");
    renderer->Print(panicMessage);
} 