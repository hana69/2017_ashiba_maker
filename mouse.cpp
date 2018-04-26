#include"mouse.h"
#include"Dxlib.h"


CMouse::CMouse()
:x(0),y(0),
tempX(0),tempY(0)
{
	SetRange(0,0,0,0);
}

bool CMouse::nowLeftPushing = false;
bool CMouse::nowRightPushing = false;
bool CMouse::lastLeftPushing = false;
bool CMouse::lastRightPushing = false;

CMouse::CMouse(int _x1, int _y1, int _x2, int _y2)
	:CMouse()
{
	SetRange(_x1, _y1, _x2, _y2);
}

void CMouse::Update() {
	lastLeftPushing = nowLeftPushing;
	lastRightPushing = nowRightPushing;
	nowLeftPushing = GetMouseInput()&(MOUSE_INPUT_LEFT != 0);
	nowRightPushing = GetMouseInput()&(MOUSE_INPUT_RIGHT != 0);
}

void CMouse::SetRange(int _x1,int _y1,int _x2,int _y2){
	rangeX1 = _x1;
	rangeY1 = _y1;
	rangeX2 = _x2;
	rangeY2 = _y2;
}

bool CMouse::RightPushed() {

	if (!lastRightPushing && nowRightPushing) {
		return true;
	}
	return false;

}
bool CMouse::LeftPushed() {
	if (!lastLeftPushing && nowRightPushing) {
		return true;
	}

	return false;
}

bool CMouse::RightReleased(){
	if (lastRightPushing && !nowRightPushing) {
		return true;
	}
	return false;
}
bool CMouse::LeftReleased(){
	if (lastLeftPushing && nowLeftPushing) {
		return true;
	}
	return false;
}

void CMouse::SetTemp(){
	GetMousePoint(&x,&y);
	tempX=x;
	tempY=y;
}

int CMouse::ChangeX(){
	GetMousePoint(&x,&y);
	return x-tempX;
}
int CMouse::ChangeY(){
	GetMousePoint(&x,&y);
	return y-tempY;
}

bool CMouse::LeftPushing(){	
	return nowLeftPushing;
}

bool CMouse::Insided(){
	GetMousePoint(&x,&y);
	if(rangeX1 < x && x < rangeX2 && rangeY1 < y &&  y < rangeY2){
		return true;
	}
	return false;
}

int CMouse::Wheel(int rate) {
	static int f = 0;
	f++;
	if (f>rate) {
		f = 0;
		return -GetMouseWheelRotVol();
		
	}
	return 0;
	
}