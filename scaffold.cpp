#include"scaffold.h"

CScaffold::CScaffold(int _x1,int _y1,int _x2,int _y2)
:Mouse(_x1,_y1,_x2,_y2)
{
	SetRange(_x1,_y1,_x2,_y2);
}

void CScaffold::DrawField(){
	Mouse.SetTemp();
	for(int i=0;i<;i++){
		DrawBox();
	}
}

void CScaffold::SetRange(int _x1,int _y1,int _x2,int _y2){
	Mouse.SetRange(_x1,_y1,_x2,_y2);
}