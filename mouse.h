#pragma once

#include"Dxlib.h"
#include "General.h"

class CMouse{
public:
	CMouse(int _x1,int _y1,int _x2,int _y2);//コンストラクタで範囲の指定を行う

	void SetRange(int _x1,int _y1,int _x2,int _y2);//範囲の指定

	bool LeftReleased();
	bool RightReleased();

	void SetTemp();	//最近左クリックしたときの座標を保存

	int TempX(){return tempX;};
	int TempY(){return tempY;};

	int ChangeX();//SetTempで設定した座標からの変位のＸ成分を返す
	int ChangeY();//SetTempで設定した座標からの変位のＹ成分を返す
		
	bool Flag();
	bool Insided();
private:
	bool flag;
	bool rightFlag;

	int x,y;

	int tempX,tempY;

	int rangeX1,rangeX2,rangeY1,rangeY2;

};