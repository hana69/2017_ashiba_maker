#include "main.h"

CMain::CMain(){
	frame = tempframe=0;
	scene = TITLE_S;
	title.Start();
}
///////////�p�u���b�N�֐�///////////////
void CMain::Awake(){
//	backPic=LoadGraph("noseResource/haikei_normal.png");
//	titleBGM=LoadSoundMem("noseResource/title.mp3");
//	LoadDivGraph("noseResource/Scaffold.png", (int)ScaffoldTypeNum , 3 , 3 , 50 , 50 , scaffoldGraph );
}

void CMain::GameLoop(){
	switch (scene) {
	case TITLE_S:
		title.Update();
		if (title.Changed()) {
			scene = MAIN_S;
			main.Start(title.SelectedStageNum());
			SetFontSize(15);
		}
		break;
	case MAIN_S:
		main.Update();
		if (main.OperatedReturnTitle()) {
			scene = TITLE_S;
			title.Start();
		}
		break;
	}
	frame++;
}


//////////�v���C�x�[�g�֐�/////////////
