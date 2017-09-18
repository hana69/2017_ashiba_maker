#pragma once

#include"Dxlib.h"
#include "General.h"

class CMouse{
public:
	CMouse();
	CMouse(int _x1, int _y1, int _x2, int _y2);//�R���X�g���N�^�Ŕ͈͂̎w����s��

	void SetRange(int _x1,int _y1,int _x2,int _y2);//�͈͂̎w��

	bool LeftPushed();
	bool RightPushed();

	bool LeftReleased();
	bool RightReleased();

	void SetTemp();	//�Ăяo���ꂽ�u�Ԃ̍��W��temp�ɕۑ�

	int X() { return x; };
	int Y() { return y; };

	int TempX(){return tempX;};
	int TempY(){return tempY;};

	int ChangeX();//SetTemp�Őݒ肵�����W����̕ψʂ̂w������Ԃ�
	int ChangeY();//SetTemp�Őݒ肵�����W����̕ψʂ̂x������Ԃ�
		
	bool LeftPushing();
	bool Insided();
private:

	int x,y;

	int tempX,tempY;

	int rangeX1,rangeX2,rangeY1,rangeY2;

};