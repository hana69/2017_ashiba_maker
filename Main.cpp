#include "main.h"

CMain::CMain()
	:Title_S(&Main_S),
	Main_S(&Title_S)
{
	frame = tempframe=0;
	//scene = TITLE;
	scene = (CScene*)&Title_S;
}
///////////パブリック関数///////////////
void CMain::Awake(){
//	backPic=LoadGraph("noseResource/haikei_normal.png");
//	titleBGM=LoadSoundMem("noseResource/title.mp3");
}

void CMain::GameLoop(){
	
	scene->Update();
	if (scene -> Changed()) {
		scene = (CScene*)scene->Next();
	}
	frame++;
}


//////////プライベート関数/////////////
