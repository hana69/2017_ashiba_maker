#include "main.h"

CMain::CMain()
{
	frame = tempframe=0;
	scene = MAIN;
}
///////////�p�u���b�N�֐�///////////////
void CMain::Awake(){
//	backPic=LoadGraph("noseResource/haikei_normal.png");
//	titleBGM=LoadSoundMem("noseResource/title.mp3");
}

void CMain::GameLoop(){
	
	switch (scene) {
	case TITLE:

		break;
	case MAIN:
		DrawBox(0,0,50,50,RED,true);
		break;
	}
	frame++;
}


//////////�v���C�x�[�g�֐�/////////////
