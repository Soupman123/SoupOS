#include "Rendering.h"

Renderer* renderer;

//private
int Renderer::getPt(int n1,int n2,float perc){return n1+((n2-n1)*perc);}

//public
Renderer::Renderer(Framebuffer* framebufferArg){
    PriFramebuffer=framebufferArg;
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
		for(unsigned int y=StartPoint.Y;y<EndPoint.Y;y++){
			for(unsigned int x=StartPoint.X;x<EndPoint.X;x++){
				set_at({x,y},color);
			}
		}
	}
}
 
void Renderer::line(Point StartPoint,Point EndPoint,unsigned int color){
    int x1=StartPoint.X,y1=StartPoint.Y,x2=EndPoint.X,y2=EndPoint.Y;
    const bool steep=(((y2-y1)<0)?(y2-y1)*(-1.0f):(y2-y1)>((x2-x1)<0)?(x2-x1)*(-1.0f):(x2-x1));
    if((unsigned int)x1-(unsigned int)x2==0){
        if(y1<y2){for(unsigned int y=StartPoint.Y;y<EndPoint.Y;y++){set_at({StartPoint.X,y},color);}
        }else{for(unsigned int y=EndPoint.Y;y<StartPoint.Y;y++){set_at({StartPoint.X,y},color);}}
        return;
    }if((unsigned int)y1-(unsigned int)y2==0){
        if(x1<x2){for(unsigned int x=StartPoint.X;x<EndPoint.X;x++){set_at({x,StartPoint.Y},color);}
        }else{for(unsigned int x=EndPoint.X;x<StartPoint.X;x++){set_at({x,StartPoint.Y},color);}}
        return;
    }if(steep){
        x1=x1+y1;y1=x1-y1;x1=x1-y1;
        x2=x2+y2;y2=x2-y2;x2=x2-y2;
    }if(x1>x2){
        x1=x1+x2;x2=x1-x2;x1=x1-x2;
        y1=y1+y2;y2=y1-y2;y1=y1-y2;
    }
    const int dy=((y2-y1)<0)?(y2-y1)*(-1.0f):(y2-y1),dx=x2-x1;
    int error=dx/2;
    const int ystep=(y1<y2)?1:-1;
    int y=y1;
    const int maxX=x2;
    for(int x=x1;x<=maxX;x++){
        if(steep){set_at({y,x},color);}else{set_at({x,y},color);}
        error-=dy;if(error<0){y+=ystep;error+=dx;}   
    }
}

void Renderer::clear(unsigned int color){
    for(unsigned int y=0;y<framebuffer->Height;y++){
        for(unsigned int x=0;x<framebuffer->Width;x++){set_at({x,y},color);}
    }
}

void Renderer::quadBezier(Point Start, Point Control, Point End, unsigned int color){
    Point prev=Start;
    for(float i=0;i<1;i+=0.01){
        // The Green Line
        int xa=getPt(Start.X,Control.X,i);
        int ya=getPt(Start.Y,Control.Y,i);
        int xb=getPt(Control.X,End.X,i);
        int yb=getPt(Control.Y,End.Y,i);

        // The Black Dot
        int x=getPt(xa,xb,i);
        int y=getPt(ya,yb,i);

        line(prev,{x,y},color);
        prev={x,y};
    }
}

void Renderer::cubeBezier(Point Start, Point Control1, Point Control2, Point End, unsigned int color){
    Point prev=Start;
    int xa,ya,xb,yb,xc,yc,xm,ym,xn,yn,x,y;
    for(float i=0;i<1;i+=0.01){
        xa=getPt(Start.X,Control1.X,i);
        ya=getPt(Start.Y,Control1.Y,i);
        xb=getPt(Control1.X,Control2.X,i);
        yb=getPt(Control1.Y,Control2.Y,i);
        xc=getPt(Control2.X,End.X,i);
        yc=getPt(Control2.Y,End.X,i);

        xm=getPt(xa,xb,i);
        ym=getPt(ya,yb,i);
        xn=getPt(xb,xc,i);
        yn=getPt(yb,yc,i);

        x=getPt(xm,xn,i);
        y=getPt(ym,yn,i);

        line(prev,{x,y},color);
        prev={x,y};
    }
}

void Renderer::update() {
	memcpy(PriFramebuffer->BaseAddress,framebuffer->BaseAddress,PriFramebuffer->BufferSize);
}

void Renderer::InitDoubleBuffer(Framebuffer* f) {
	framebuffer = f;
}