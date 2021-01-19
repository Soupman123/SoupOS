#include "Rendering.h"

Renderer* renderer;

Renderer::Renderer(Framebuffer* framebufferArg){
    framebuffer=framebufferArg;
}

void Renderer::set_at(Point point,unsigned int color){
    unsigned int* pixPtr=(unsigned int*)framebuffer->BaseAddress;
    *(unsigned int*)(pixPtr+point.X+(point.Y*framebuffer->PixelsPerScanLine))=color;
}

unsigned int Renderer::get_at(Point point){
    unsigned int* pixPtr=(unsigned int*)framebuffer->BaseAddress;
    return *(unsigned int*)(pixPtr+point.X+(point.Y*framebuffer->PixelsPerScanLine));
}

void Renderer::rect(Point StartPoint,Point EndPoint,unsigned int color){
	if(StartPoint.X<EndPoint.X&&StartPoint.Y<EndPoint.Y){
		for(unsigned int y=StartPoint.Y; y<EndPoint.Y; y++){
			for(unsigned int x=StartPoint.X; x<EndPoint.X; x++){
				set_at({x,y},color);
			}
		}
	}
}
 
void Renderer::line(Point StartPoint,Point EndPoint,unsigned int color){
    float x1=(float)StartPoint.X,y1=(float)StartPoint.Y,x2=(float)EndPoint.X,y2=(float)EndPoint.Y; 
    const bool steep=(((y2-y1)<0)?(y2-y1)*(-1.0f):(y2-y1)>((x2-x1)<0)?(x2-x1)*(-1.0f):(x2-x1));
    if(steep){
        x1=x1+y1;y1=x1-y1;x1=x1-y1;
        x2=x2+y2;y2=x2-y2;x2=x2-y2;
    } if(x1>x2){
        x1=x1+x2;x2=x1-x2;x1=x1-x2;
        y1=y1+y2;y2=y1-y2;y1=y1-y2;
    }
    const float dy=((y2-y1)<0)?(y2-y1)*(-1.0f):(y2-y1),dx=x2-x1;
    float error=dx/2.0f;
    const int ystep=(y1<y2)?1:-1;
    int y=(int)y1;
    const int maxX=(int)x2;
    for(int x=(int)x1; x<=maxX; x++){
        if(steep){set_at({y,x},color);}else{set_at({x,y},color);}
        error-=dy; if(error<0){y+=ystep;error+=dx;}
    }
}