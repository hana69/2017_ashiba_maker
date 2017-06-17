#include"scaffold.h"

//////////////////CScaffold//////////////////////////

////////�R���X�g���N�^//////////
CScaffold::CScaffold(int _x1,int _y1,int _x2,int _y2)
:DrawField(_x1,_y1,_x2,_y2)
{
	SetDrawFieldRange(_x1,_y1,_x2,_y2);
	for(int i = 0; i < ScaffoldTypeNum; i++){
		scaffoldGraph[i] = -2;
	}
	for(int i = 0; i < ScaffoldTypeNum; i++){
		graphName[i] = "Scaffold";
		graphName[i] += std::to_string((long long)i+1);//���R���͂P����
		graphName[i] += ".png";
	}
}
///////public1�֐�/////////////
void CScaffold::Main(){
	if(scaffoldGraph[0]==-2){
		LoadScaffoldGraph();
	}
	DrawField.Emerge();

	SelectField();
}

void CScaffold::SelectField(){
	for(int i=0;i<ScaffoldTypeNum;i++){
		DrawGraph( WINDOW_WIDTH-50 , i*70 , scaffoldGraph[i] , true );
	}
}

//////private�֐�/////////////
void CScaffold::SetDrawFieldRange(int _x1,int _y1,int _x2,int _y2){
	DrawField.SetRange(_x1,_y1,_x2,_y2);
}

void CScaffold::LoadScaffoldGraph(){
	for(int i = 0; i < ScaffoldTypeNum; i++){
		scaffoldGraph[i] = LoadGraph(graphName[i].c_str());
	}
}

////////////////CDrawField//////////////////////

/////////////�R���X�g���N�^///////////////////

CDrawField::CDrawField(int _x1,int _y1,int _x2,int _y2)
:Mouse(_x1,_y1,_x2,_y2)
{
	SetRange(_x1,_y1,_x2,_y2);
}
/////////////public�֐�//////////////////////
void CDrawField::Emerge(){
	DrawBox( x1, y1 , x2 , y2 , WHITE , false);
	Draw();
}

void CDrawField::SetRange(int _x1,int _y1,int _x2,int _y2){
	x1 = _x1;
	x2 = _x2;
	y1 = _y1;
	y2 = _y2;
	Mouse.SetRange(_x1,_y1,_x2,_y2);
}

////////////private�֐�//////////////////////

void CDrawField::Draw(){
	Mouse.SetTemp();

	if(Mouse.Flag()==true && Mouse.Insided()){	
		if(Mouse.ChangeX() >= 50 ){
			if(Mouse.ChangeY() >= 50){
				for(int i = Mouse.TempX(); i < Mouse.TempX() + Mouse.ChangeX() ; i += 50 ){
					for(int j = Mouse.TempY();j < Mouse.TempY() + Mouse.ChangeY(); j += 50 ){
						DrawBox(i , j , i + 50 , j + 50 , RED , true);
						DrawBox(i , j , i + 50 , j + 50 , WHITE , false);
					}
				}
			}else if(Mouse.ChangeY() <= -50){
				for(int i = Mouse.TempX(); i < Mouse.TempX() + Mouse.ChangeX() ; i += 50 ){
					for(int j = Mouse.TempY();j > Mouse.TempY() + Mouse.ChangeY(); j -= 50 ){
						DrawBox(i , j , i + 50 , j - 50 , RED , true);
						DrawBox(i , j , i + 50 , j - 50 , WHITE , false);
					}
				}
			}
		}else if(Mouse.ChangeX() <= -50 ){
			if(Mouse.ChangeY() >= 50){
				for(int i = Mouse.TempX(); i > Mouse.TempX() + Mouse.ChangeX() ; i -= 50 ){
					for(int j = Mouse.TempY();j < Mouse.TempY() + Mouse.ChangeY(); j += 50 ){
						DrawBox(i , j , i - 50 , j + 50 , RED , true);
						DrawBox(i , j , i - 50 , j + 50 , WHITE , false);
					}
				}
			}else if(Mouse.ChangeY() <= -50){
				for(int i = Mouse.TempX(); i > Mouse.TempX() + Mouse.ChangeX() ; i -= 50 ){
					for(int j = Mouse.TempY();j > Mouse.TempY() + Mouse.ChangeY(); j -= 50 ){
						DrawBox(i , j , i - 50 , j - 50 , RED , true);
						DrawBox(i , j , i - 50 , j - 50 , WHITE , false);
					}
				}
			}
		}
		
	}
}


