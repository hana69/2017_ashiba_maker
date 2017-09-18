#include"scaffold.h"

//////////////////CScaffold//////////////////////////

////////コンストラクタ//////////
CScaffold::CScaffold(int _cost)
	:cost(_cost)
{}
int CScaffold::graph = 0;
///////public関数/////////////

//////private関数/////////////

////////////////CNormal///////////////////////
CNormal::CNormal()
	:CScaffold(10)
{}

void CNormal::Draw() {
	DrawGraph(x, y, scaffoldGraph[NORMAL], true);
}

////////////////CSpeedUp///////////////////////
CSpeedUp::CSpeedUp()
	:CScaffold(20)
{}
void CSpeedUp::Draw() {
	DrawGraph(x, y, scaffoldGraph[SPEED_UP], true);
}
////////////////CSpeedDown///////////////////////
CSpeedDown::CSpeedDown()
	:CScaffold(20)
{}
void CSpeedDown::Draw() {
	DrawGraph(x, y, scaffoldGraph[SPEED_DOWN], true);
}
////////////////CJump///////////////////////
CJump::CJump()
	:CScaffold(20)
{}
void CJump::Draw() {
	DrawGraph(x, y, scaffoldGraph[JUMP], true);
}

void CJump::HitEffect() {
	delete this;
}
