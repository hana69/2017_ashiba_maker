#include "main.h"

CMain::CMain()
	:Scaffold(0,0,WINDOW_HEIGHT,WINDOW_WIDTH)
{
	frame = tempframe=0;
	//scene = TITLE;
	scene = MAIN;
}
///////////パブリック関数///////////////
void CMain::Awake(){
//	backPic=LoadGraph("noseResource/haikei_normal.png");
//	titleBGM=LoadSoundMem("noseResource/title.mp3");
}

void CMain::GameLoop(){
	
	switch (scene) {
	case TITLE:
		DrawString(0,0,"たいとる",RED);
		if(Key.Pushed( KEYNAME.ENTER ) ){
			scene=MAIN;
		}
		
		break;
	case MAIN:
		Scaffold.DrawField();
		break;
	}
	frame++;
}


//////////プライベート関数/////////////
