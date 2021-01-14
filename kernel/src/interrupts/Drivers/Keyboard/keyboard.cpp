#include "keyboard.h"

bool upper = false;
uint8_t chr = 0;

void HandleKeyboard(uint8_t scancode) {
    chr = Set1::ScancodeLookupTable[scancode];
    if ((chr != 0 && scancode < 0x3A) && upper) {
        GlobalRenderer->PutChar(chr - 32, GlobalRenderer->CursorPosition.X, GlobalRenderer->CursorPosition.Y);
        GlobalRenderer->CursorPosition.X+=8;
        if(GlobalRenderer->CursorPosition.X + 8 > GlobalRenderer->TargetFramebuffer->Width){
            GlobalRenderer->CursorPosition.X = 0;
            GlobalRenderer->CursorPosition.Y += 16;
        }
    }
	else {
		switch (scancode) {
		case 0x0E:
			GlobalRenderer->ClearChar(0x000000, GlobalRenderer->CursorPosition.X - 8, GlobalRenderer->CursorPosition.Y);
            GlobalRenderer->CursorPosition.X -= 8;
			break;
		case 0x2A:
			if (upper) {upper = false;}
            else {upper = true;}
			break;
		case 0xAA:
			if (upper) {upper = false;}
            else {upper = true;}
            break;
		case 0x36:
			if (upper) {upper = false;}
            else {upper = true;}
			break;
		case 0xB6:
			if (upper) {upper = false;}
            else {upper = true;}
			break;
		case 0x1C:
			GlobalRenderer->Next();
			break;
        case 0x3A:
            if (upper) {upper = false;}
            else {upper = true;}

        default:
            if (scancode < 0x3A){
                GlobalRenderer->PutCharF(chr, 0, GlobalRenderer->CursorPosition.X, GlobalRenderer->CursorPosition.Y);
                GlobalRenderer->CursorPosition.X+=8;
                if(GlobalRenderer->CursorPosition.X + 8 > GlobalRenderer->TargetFramebuffer->Width){
                    GlobalRenderer->CursorPosition.X = 0;
                    GlobalRenderer->CursorPosition.Y += 16;
                }
            }
            break;
		}
	}
}