#pragma once
#include"mouse.h"
class ClickableObj {
public:
	ClickableObj(int,int,int,int,int _graph[]);
	void Update();
	bool Clicked();
private:
	void SetNowState();
	enum class MOUSE_STATE :unsigned{
		NOT_SELECTING,
		SELCTING,
		PUSHING,
		RELEASED,
		STATE_NUM
	};
	MOUSE_STATE nowState;
	int graph[(unsigned)MOUSE_STATE::STATE_NUM];
	const int x1, y1,x2, y2;
	bool clickedFlag;
	
};