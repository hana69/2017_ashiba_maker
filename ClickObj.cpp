#include"ClickableObj.h"
#include<stdlib.h>
ClickableObj::ClickableObj(int _x1,int _y1,int _x2 , int _y2 ,int _graph[]) 
	:x1(_x1),y1(_y1),x2(_x2),y2(_y2),
	clickedFlag(false)
{
	for (int i = 0; i < 4;i++) {
		graph[i] = *(_graph + i);
	}
	//LoadDivGraph("ReturnToTitle_4in1.png", 4, 1, 4, 173, 20, graph);
}

void ClickableObj::Update() {
	SetNowState();
	
	DrawBox(x1, y1, x2, y2,BLUE,true);
	DrawGraph(x1, y1, graph[(int)nowState], true);
}

bool ClickableObj::Clicked() {
	return clickedFlag;
}

void ClickableObj::SetNowState() {
	static CMouse mouse(x1, y1, x2, y2);

	nowState = MOUSE_STATE::NOT_SELECTING;

	if (mouse.Insided()) {
		nowState = MOUSE_STATE::SELCTING;
	}
	if (mouse.LeftPushing()) {
		nowState = MOUSE_STATE::PUSHING;
	}
	if (mouse.LeftReleased()) {
		nowState = MOUSE_STATE::RELEASED;
		clickedFlag = true;
	}
}

