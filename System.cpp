#include "main.h"

#define FPS 60

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

	SetWindowText("Title");
	//SetWindowIconID(101);
	SetGraphMode(WINDOW_WIDTH , WINDOW_HEIGHT , 16 );
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );

	ScreenFlip();

	//SetTransColor(155,155,15);

	CMain Main;
	Main.Awake();

	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Main.GameLoop();
		/*if (loopEscapeFlag==true) {
			loopEscapeFlag = false;
			break;
		}*/
		Sleep(0);
	}
        
	DxLib_End();

//	ShellExecute( GetMainWindowHandle(),"open" ,"Launcher.exe" , NULL , NULL , SW_SHOW );

	return 0;
} 