#include <windows.h>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int W=400,H=W/4,dH=0,mode;
string s;
SDL_Window*win;
SDL_Renderer*ren;
SDL_Event e;
SDL_DisplayMode dm;
SDL_Texture*bckg, *n[10];
SDL_Rect bckgR={0,0,W,H},nR={0,0,W/12,H/2};
time_t t,was,wait=1605657600,dt;
fstream f;

int readln(){
	char B[1000];
	f.getline(B,1000);
	s=B;
return atoi(s.c_str());
}

void getCfg(){
f.open("cfg.txt");
	mode=readln();
	W=readln();
	dH=readln();
	wait+=readln()*3600;
f.close();
	if((W<60)||(W>1200))
		W=400;
	H=W/4;
	bckgR.w=W;	bckgR.h=W/4;
	nR.w=W/12;	nR.h=W/8;
}

void preload(){
	bckg=SDL_CreateTextureFromSurface(ren,IMG_Load("res/bckg.png"));
	for(int i=0;i<10;++i){
		s="res/"+to_string(i)+".png";
		n[i]=SDL_CreateTextureFromSurface(ren,IMG_Load(s.c_str()));
	}
}

void draw(int d1,int d2,int h1,int h2,int m1,int m2,int s1,int s2){
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren,bckg,NULL,&bckgR);
	nR.x=W/24; nR.y=H/5*2;
	SDL_RenderCopy(ren,n[d1],NULL,&nR);
	nR.x+=H/3;
	SDL_RenderCopy(ren,n[d2],NULL,&nR);
	nR.x+=H-H/3;
	SDL_RenderCopy(ren,n[h1],NULL,&nR);
	nR.x+=H/3;
	SDL_RenderCopy(ren,n[h2],NULL,&nR);
	nR.x+=H-H/3;//sorry 4 this i'll make better later
	SDL_RenderCopy(ren,n[m1],NULL,&nR);
	nR.x+=H/3;
	SDL_RenderCopy(ren,n[m2],NULL,&nR);
	nR.x+=H-H/3;
	SDL_RenderCopy(ren,n[s1],NULL,&nR);
	nR.x+=H/3;
	SDL_RenderCopy(ren,n[s2],NULL,&nR);
	SDL_RenderPresent(ren);
}

void update(){
	was=time(NULL);
	dt=wait-was;
	draw(dt/86400/10,dt/86400%10,dt/3600%24/10,dt/3600%24%10,dt/60%60/10,dt/60%60%10,dt%60/10,dt%60%10);
}

int main(int argc, char *argv[]){
	FreeConsole();
	getCfg();
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	SDL_GetDesktopDisplayMode(0,&dm);
	switch(mode){
		case 1:
			win=SDL_CreateWindow("timeBeforeCyberpunk2077",dm.w-W,0,W,H,SDL_WINDOW_BORDERLESS|SDL_WINDOW_SKIP_TASKBAR);
	break;case 2:
			win=SDL_CreateWindow("timeBeforeCyberpunk2077",dm.w-W,dm.h-dH-H,W,H,SDL_WINDOW_BORDERLESS|SDL_WINDOW_SKIP_TASKBAR);
	break;case 3:
			win=SDL_CreateWindow("timeBeforeCyberpunk2077",0,dm.h-dH-H,W,H,SDL_WINDOW_BORDERLESS|SDL_WINDOW_SKIP_TASKBAR);
	break;case 4:
			win=SDL_CreateWindow("timeBeforeCyberpunk2077",0,0,W,H,SDL_WINDOW_BORDERLESS|SDL_WINDOW_SKIP_TASKBAR);
	break;
	}
	ren=SDL_CreateRenderer(win,0,1);
	SDL_SetWindowGrab(win,SDL_FALSE);
	preload();
	was=time(NULL);
	while(true){
		t=time(NULL);
		if(t!=was)
			update();
		Sleep(50);
		if(SDL_PollEvent(&e))
			if(e.key.keysym.sym==SDLK_ESCAPE)
				break;
	}
return 0;
}
