#pragma once
#include <stdint.h>
#include "Framebuffer.h"
#include "../math.h"
#include "../memory.h"

class Renderer{
    public:
    Renderer(Framebuffer* framebufferArg);
    void set_at(Point point, unsigned int color);
    unsigned int get_at(Point point);
    void rect(Point StartPoint, Point EndPoint, unsigned int color);
    void line(Point StartPoint, Point EndPoint, unsigned int color);
    void clear(unsigned int color=0);
    void quadBezier(Point Start, Point Control, Point End, unsigned int color);
    void cubeBezier(Point Start, Point Control1, Point Control2, Point End, unsigned int color);
    void update();
    Framebuffer* framebuffer;
    void InitDoubleBuffer(Framebuffer* f);
    private:
    Framebuffer* PriFramebuffer;
    int getPt(int n1,int n2,float perc);
};

extern Renderer* renderer;