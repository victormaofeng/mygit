#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#define width 640
#define height 480
int x=300,y=430,r=20;
int t=1,m=1;
char c;
int bl=100,br=300;
void ball1(){
   setcolor(BLACK);	
   setfillcolor(BLACK);
   fillcircle(x,y,r);
}
void ball2(){
   setcolor(BLACK);
   setfillcolor(BLUE);
   fillcircle(x,y,r);
}
void Drawbackground() {
   setfillcolor(BLACK);	
   fillrectangle(0,0,width,height);	
}
void board1(){
	setcolor(BLACK);
    setfillcolor(BLACK);
    fillrectangle(bl,450,br,470);
	
}
void board2(){
	setcolor(BLACK);
    setfillcolor(RED);
    fillrectangle(bl,450,br,470);

	
}
void setball(){
	if(x<=r||x>=width-r){
	   t=-t;
	}
	if(y<=r){
	   m=-m;
	}
	if(x>=bl&&x<=br&&y>=450-r){
	   m=-m;
	}
	x+=t;
	y+=m;
}
void setboard(){
    if(_kbhit()){
	   c =_getch();
	   switch(c){
	   case 'a' :
		   if(bl<=0){
			   //bl = 0;
		       break;
		   }
		   else{
		   bl-=10;
		   br-=10;
		   break;
		   }
	   case 'd':
		   if(br>=640)
		   {
			   //br = 640;
			   break;
		   }
		   else{
		   br+= 10;
		   bl+=10;
		   break;
		   }
	   }
	   }
}
void main(){
	initgraph(width, height); 
	Drawbackground();
	BeginBatchDraw();
    while(1){
	ball1();
	board1();
    setball();
	setboard();
    ball2();
	board2();
	FlushBatchDraw();
		
	Sleep(10);
	}
    
	 
	_getch();
	closegraph();
}