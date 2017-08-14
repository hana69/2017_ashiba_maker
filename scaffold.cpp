#include"scaffold.h"

//////////////////CScaffold//////////////////////////

////////コンストラクタ//////////
CScaffold::CScaffold(int _graph)
	:graph(_graph)
{}
///////public関数/////////////
void CScaffold::Draw() {
	DrawGraph(x,y,graph,true);
}

//////private関数/////////////
