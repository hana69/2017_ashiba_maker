#include "main.h"

CMain::CMain()
	:TITLE_S(&MAIN_S),MAIN_S(&TITLE_S)
{
	frame = tempframe=0;
	scene = &TITLE_S;
}
///////////パブリック関数///////////////
void CMain::Awake(){
//	backPic=LoadGraph("noseResource/haikei_normal.png");
//	titleBGM=LoadSoundMem("noseResource/title.mp3");
//	LoadDivGraph("noseResource/Scaffold.png", (int)ScaffoldTypeNum , 3 , 3 , 50 , 50 , scaffoldGraph );
}

void CMain::GameLoop(){
	
	scene->Update();
	if (scene -> Changed()) {
		scene = (CScene*)scene->Next();
	}
	frame++;
}


//////////プライベート関数/////////////
