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

void Renderer::line(Point StartPoint, Point EndPoint, unsigned int color){
    int run=(EndPoint.X-StartPoint.X); 
	int rise=(EndPoint.Y-StartPoint.Y);
	if(run==0&&rise==0){
        set_at(StartPoint, color);
        return;
    }
    int gcdRun=run/gcd(rise, run);
    int gcdRise=run/gcd(run, rise);

	unsigned int ymin, ymax, xmin, xmax;
    if(((run<0)?run*(-1):run)>((rise<0)?rise*(-1):rise)){
		if(StartPoint.X < EndPoint.X){
			xmin=StartPoint.X;
			xmax=EndPoint.X;
		}else{
			ymin=EndPoint.X;
			ymax=StartPoint.X;
		}
		if(run>0){
			for(unsigned int x=xmin; x <=xmax; x++){
				unsigned int y=StartPoint.Y+((x-StartPoint.X) / gcdRun);
				set_at({x, y}, color);
			}
		}else{
			for(unsigned int x=xmin; x <=xmax; x++){
				unsigned int y=StartPoint.Y+((x-StartPoint.X) / gcdRun);// issue
				set_at({x, y}, color);
			}
		}
	}else{
		if(StartPoint.Y < EndPoint.Y){
			ymin=StartPoint.Y;
			ymax=EndPoint.Y;
		}else{
			ymin=EndPoint.Y;
			ymax=StartPoint.Y;
		}
		if(rise>0){
			for(unsigned int y=ymin; y <=ymax; y++){
				unsigned int x=StartPoint.X+((y-StartPoint.Y) / gcdRise);
				set_at({x, y}, color);
			}
		}else{
			for(unsigned int y=ymin; y <=ymax; y++){
				unsigned int x=StartPoint.X+((y-StartPoint.Y) / gcdRise);// issue
				set_at({x, y}, color);
			}
		}
	}
	set_at(StartPoint, color);
	set_at(EndPoint, color);
}