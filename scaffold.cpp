#include"scaffold.h"

//////////////////CScaffold//////////////////////////

////////�R���X�g���N�^//////////
CScaffold::CScaffold(int _graph)
	:graph(_graph)
{}
///////public�֐�/////////////
void CScaffold::Draw() {
	DrawGraph(x,y,graph,true);
}

//////private�֐�/////////////
