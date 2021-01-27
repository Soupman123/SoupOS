#pragma once
#include <stdint.h>
#include "Framebuffer.h"
#include "../../math.h"
#include "../../memory.h"
#include "../../simpleFonts.h"

class Renderer{
    public:
    Renderer(Framebuffer* framebufferPri, Framebuffer* framebufferSec, PSF1_FONT* psf1_Font);
    void set_at(Point point, unsigned int color);
    unsigned int get_at(Point point);
    void rect(Point StartPoint, Point EndPoint, unsigned int color);
    void line(Point StartPoint, Point EndPoint, unsigned int color);
    void clear(unsigned int color=0);
    void quadBezier(Point Start, Point Control, Point End, unsigned int color);
    void cubeBezier(Point Start, Point Control1, Point Control2, Point End, unsigned int color);
    void ClearChar(unsigned int color=0);
    void Next();
    void PutChar(char chr, unsigned int xOff, unsigned int yOff);
    void PutChar(char chr);
    void Print(const char* str);
    void update();
    unsigned int color = 0xffffff;
    Framebuffer* framebuffer;
    Point textCursorPosition;
    private:
    PSF1_FONT* font;
    Framebuffer* PriFramebuffer;
    int getPt(int n1,int n2,float perc);
};

extern Renderer* renderer;