#pragma once
#include <stdint.h>
#include "Framebuffer.h"
#include "../../math.h"

class Renderer{
    public:
    Renderer(Framebuffer* framebufferArg);
    void set_at(Point point, unsigned int color);
    unsigned int get_at(Point point);
    void rect(Point StartPoint, Point EndPoint, unsigned int color);
    private:
    Framebuffer* framebuffer;
    int gcd(int a, int b);
};

extern Renderer* renderer;