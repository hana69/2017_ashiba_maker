#include"mouse.h"

CMouse::CMouse(int _x1,int _y1,int _x2,int _y2){
	rangeX1 = _x1;
	rangeY1 = _y1;
	rangeX2 = _x2;
	rangeY2 = _y2;

	flag = false;
	rightFlag = false;

	x=y=0;
	tempX=tempY=0;
}

void CMouse::SetRange(int _x1,int _y1,int _x2,int _y2){
	rangeX1 = _x1;
	rangeY1 = _y1;
	rangeX2 = _x2;
	rangeY2 = _y2;
}

bool CMouse::RightReleased(){

	if( rightFlag==false && GetMouseInput() &(MOUSE_INPUT_RIGHT != 0) ){
		rightFlag = true;
	}
	if( rightFlag == true && !(GetMouseInput() &(MOUSE_INPUT_RIGHT != 0) ) ){
		rightFlag = false;
		return true;
	}

	return false;
}
bool CMouse::LeftReleased(){

	if(rightFlag==false && GetMouseInput()&(MOUSE_INPUT_LEFT != 0) ){
		flag=true;
	}
	if(flag==true && !(GetMouseInput()&(MOUSE_INPUT_LEFT != 0) ) ){
		flag = false;
		if(rangeX1 < x && x < rangeX2 && rangeY1 < y &&  y < rangeY2){
			return true;
		}
	}

	return false;
}

void CMouse::SetTemp(){
	GetMousePoint(&x,&y);
	if( Insided() ){
		if(flag == false ){//押されてないとき
			if( GetMouseInput()&(MOUSE_INPUT_LEFT != 0) ){
				flag=true;
				tempX=x;
				tempY=y;
			}
		}else{
			if( !(GetMouseInput() &(MOUSE_INPUT_LEFT!=0) ) ){
				flag=false;
			}
		}
	}

}

int CMouse::GetChangeX(){
	GetMousePoint(&x,&y);
	return x-tempX;
}
int CMouse::GetChangeY(){
	GetMousePoint(&x,&y);
	return y-tempY;
}

bool CMouse::GetFlag(){
	return flag;
}
///////////////////////プライベート関数///////////////////////////////////
bool CMouse::Insided(){
	if(rangeX1 < x && x < rangeX2 && rangeY1 < y &&  y < rangeY2){
		return true;
	}
	return false;
}