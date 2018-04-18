#include"key.h"
#include"StageManager.h"

#define FPS 60

#include"ClickableObj.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetOutApplicationLogValidFlag(false);//LogÇèoóÕÇµÇ»Ç¢
	SetWindowText("Title");
	//SetWindowIconID(101);
	SetGraphMode(WINDOW_WIDTH , WINDOW_HEIGHT , 16 );
	ChangeWindowMode(true), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );

	ScreenFlip();

	//SetTransColor(155,155,15);

	/*CMain Main;
	Main.Awake();*/
	StageManager stageManager;
	int graph[4]; LoadDivGraph("noseResource/ReturnToTitle_4in1.png", 4, 1, 4, 173, 20, graph);
	ClickableObj obj(0, 0, 173, 20, graph);

	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
	//	stageManager.UpDate();
		/*if (loopEscapeFlag==true) {
			loopEscapeFlag = false;
			break;
		}*/
		if (Key.Pushed(KEYNAME.ESC)) {
			break;
		}
		obj.Update();
		Sleep(0);
	}
        
	DxLib_End();
	return 0;
} 