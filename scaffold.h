#pragma once
#include"define.h"
#include"mouse.h"

class CScaffold{
public:
	CScaffold(int _x1,int _y1,int _x2,int _y2);
	void DrawField();
	void SetRange(int _x1,int _y1,int _x2,int _y2);
private: 
	CMouse Mouse;
};