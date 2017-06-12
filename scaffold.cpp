#include"scaffold.h"

//////////////////CScaffold//////////////////////////

////////コンストラクタ//////////
CScaffold::CScaffold(int _x1,int _y1,int _x2,int _y2)
:Mouse(_x1,_y1,_x2,_y2)
{
	SetDrawFieldRange(_x1,_y1,_x2,_y2);
	for(int i = 0; i < ScaffoldTypeNum; i++){
		scaffoldGraph[i] = -2;
	}
	for(int i = 0; i < ScaffoldTypeNum; i++){
		graphName[i] = "Scaffold";
		graphName[i] += std::to_string((long long)i+1);//自然数は１から
		graphName[i] += ".png";
	}
}
///////public1関数/////////////
void CScaffold::DrawField(){
	Mouse.SetTemp();
	if(scaffoldGraph[0]==-2){
		LoadScaffoldGraph();
	}

	if(Mouse.GetFlag()==true){
		if(){
			for(int i = Mouse.TempX(); i < Mouse.TempX()+Mouse.GetChangeX() ; i+=50){
				for(int j = Mouse.TempY();j < Mouse.TempY() + Mouse.GetChangeY(); j+=50){
					DrawBox(i , j , i+50 , j+50 , RED , true);
					DrawBox(i , j , i+50 , j+50 , WHITE , false);
				}
			}
		}else{
			for(int i = Mouse.TempX(); i > Mouse.TempX()+Mouse.GetChangeX() ; i-=50){
				for(int j = Mouse.TempY();j < Mouse.TempY() + Mouse.GetChangeY(); j+=50){
					DrawBox(i , j , i+50 , j+50 , RED , true);
					DrawBox(i , j , i+50 , j+50 , WHITE , false);
				}
			}
		}
	}
	
	SelectField();
}

void CScaffold::SelectField(){
	for(int i=0;i<ScaffoldTypeNum;i++){
		DrawGraph( WINDOW_WIDTH-50 , i*70 , scaffoldGraph[i] , true );
	}
}

//////private関数/////////////
void CScaffold::SetDrawFieldRange(int _x1,int _y1,int _x2,int _y2){
	Mouse.SetRange(_x1,_y1,_x2,_y2);
}

void CScaffold::LoadScaffoldGraph(){
	for(int i = 0; i < ScaffoldTypeNum; i++){
		scaffoldGraph[i] = LoadGraph(graphName[i].c_str());
	}
}

