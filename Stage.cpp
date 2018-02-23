#include"Stage.h"
#include"General.h"
#include"ActionField.h"
#include"ScaffoldDrawer.h"

Stage::Stage(int _stageNum)
	:stageNum(_stageNum),scroll(0)
{
	SetFontSize(15);
}

void Stage::Update() {
	static CActionField field(stageNum);
	static CScaffoldDrawer drawer;
	
	DrawBack(field.RightEdge());
	if (stageNum == TUTORIAL) {

	}
	else {
		drawer.Update();
		field.Update(scroll);
		if (field.MeGotCoin()) {
			drawer.AddCoin();
		}
		if (drawer.DrawFinished()) {
			field.Make(drawer.DrawnScaffold(), scroll);
		}
	}
	Scroll();
}

///////////////privateŠÖ”////////////////////////
void Stage::Scroll() {
	static CMouse mouse;
	static float a;
	a += mouse.Wheel(1) * 50.0;
	if (a>50) {
		scroll += 50;
		a = 0;
	}
	else if (a<-50) {
		scroll -= 50;
		a = 0;
	}
	if (scroll<0) {
		scroll = 0;
	}
}

void Stage::DrawBack(int rightEdge) {
	static int backGraph = LoadGraph("noseResource/main_back.png");
	DrawGraph(0, 0, backGraph, true);
	///////////‚®‚è‚Á‚Ç////////////////////////
	for (int i = 0; i <= rightEdge * 50; i += 50) {
		DrawLine(i - scroll, 0, i - scroll, WINDOW_HEIGHT, BLUE);
	}
	for (int j = 0; j < WINDOW_HEIGHT; j += 50) {
		DrawLine(0, j, WINDOW_WIDTH, j, BLUE);
	}
	//////////////////////////////////////////
}