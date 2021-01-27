#include "keyboard.h"

    bool isLeftShiftPressed;
    bool isRightShiftPressed;

void HandleKeyboard(uint8_t scancode){

    switch (scancode){
        case LeftShift:
            isLeftShiftPressed = true;
            return;
        case LeftShift + 0x80:
            isLeftShiftPressed = false;
            return;
        case RightShift:
            isRightShiftPressed = true;
            return;
        case RightShift + 0x80:
            isRightShiftPressed = false;
            return;
        case Enter:
            renderer->Next();
            return;
        case Spacebar:
            renderer->PutChar(' ');
            return;
        case BackSpace:
           renderer->ClearChar();
           return;
    }

    char ascii = QWERTYKeyboard::Translate(scancode, (isLeftShiftPressed | isRightShiftPressed));

    if (ascii != 0){
        renderer->PutChar(ascii);
    }

} 