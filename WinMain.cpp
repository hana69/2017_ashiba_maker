#include"key.h"
#include"StageManager.h"

#define FPS 60

#include"ClickObj.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetOutApplicationLogValidFlag(false);//LogÇèoóÕÇµÇ»Ç¢
	SetWindowText("Title");
	//SetWindowIconID(101);
	SetGraphMode(WINDOW_WIDTH , WINDOW_HEIGHT , 16 );
	ChangeWindowMode(true), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );

	ScreenFlip();

	//SetTransColor(155,155,15);
	CMouse mouse;
	StageManager stageManager;
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		mouse.Update();
		stageManager.UpDate();
		/*if (loopEscapeFlag==true) {
			loopEscapeFlag = false;
			break;
		}*/
		if (Key.Pushed(KEYNAME.ESC)) {
			break;
		}
		Sleep(0);
	}
        
	DxLib_End();
	return 0;
} 