#include "Rendering.h"

Renderer* renderer;
// math functions
int Renderer::gcd(int a, int b){
   if(b==0)
   return a;
   return gcd(b, a % b);
}

// render functions
Renderer::Renderer(Framebuffer* framebufferArg){
    framebuffer=framebufferArg;
}

void Renderer::set_at(Point point, unsigned int color){
    unsigned int* pixPtr=(unsigned int*)framebuffer->BaseAddress;
    *(unsigned int*)(pixPtr+point.X+(point.Y * framebuffer->PixelsPerScanLine))=color;
}

unsigned int Renderer::get_at(Point point){
    unsigned int* pixPtr=(unsigned int*)framebuffer->BaseAddress;
    return *(unsigned int*)(pixPtr+point.X+(point.Y * framebuffer->PixelsPerScanLine));
}

void Renderer::rect(Point StartPoint, Point EndPoint, unsigned int color){
	if(StartPoint.X<EndPoint.X&&StartPoint.Y<EndPoint.Y){
		for(unsigned int y = StartPoint.Y; y<EndPoint.Y; y++){
			for(unsigned int x = StartPoint.X; x<EndPoint.X; x++){
				set_at({x, y}, color);
			}
		}
	}
}