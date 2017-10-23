#include"scaffold.h"

//////////////////CScaffold//////////////////////////
const int CScaffold::cost[ScaffoldTypeNum] = {10,20,10,10};
////////コンストラクタ//////////
CScaffold::CScaffold() 
	:type(NORMAL),x(0),y(0)
{}

CScaffold::CScaffold(ScaffoldType _type,int _xPlace,int _yPlace)
	:type(_type),x(_xPlace),y(_yPlace)
{}
///////public関数/////////////
void CScaffold::Draw(int _scroll) {
	DrawGraph(x*50 - _scroll, y*50, scaffoldGraph(type), true);
	//DrawFormatString(x*50 - _scroll,y*50,PURPLE,"%f",x);
}

void CScaffold::Move(int _limit) {
	y -= 0.2;
	if (y < _limit) {
		y = _limit;
	}
}
//////private関数/////////////

