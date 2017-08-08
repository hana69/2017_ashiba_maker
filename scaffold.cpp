//#include"scaffold.h"
//
////////////////////CScaffold//////////////////////////
//
//////////コンストラクタ//////////
//CScaffold::CScaffold(int _x1,int _y1,int _x2,int _y2)
//:DrawField(_x1,_y1,_x2,_y2)
//{
//	SetDrawFieldRange(_x1,_y1,_x2,_y2);
//	for(int i = 0; i < ScaffoldTypeNum; i++){
//		scaffoldGraph[i] = -2;
//	}
//	for(int i = 0; i < ScaffoldTypeNum; i++){
//		graphName[i] = "Scaffold";
//		graphName[i] += std::to_string((long long)i+1);//自然数は１から
//		graphName[i] += ".png";
//	}
//}
/////////public1関数/////////////
//void CScaffold::Main(){
//	if(scaffoldGraph[0]==-2){
//		LoadScaffoldGraph();
//	}
//	DrawField.Emerge();
//
//	SelectField();
//}
//
//void CScaffold::SelectField(){
//	for(int i=0;i<ScaffoldTypeNum;i++){
//		DrawGraph( WINDOW_WIDTH-50 , i*70 , scaffoldGraph[i] , true );
//	}
//}
//
////////private関数/////////////
//void CScaffold::SetDrawFieldRange(int _x1,int _y1,int _x2,int _y2){
//	DrawField.SetRange(_x1,_y1,_x2,_y2);
//}
//
//void CScaffold::LoadScaffoldGraph(){
//	for(int i = 0; i < ScaffoldTypeNum; i++){
//		scaffoldGraph[i] = LoadGraph(graphName[i].c_str());
//	}
//}
//
