#include"Stage.h"
#include"General.h"
#include"ActionField.h"
#include"ScaffoldMaker.h"

Stage::Stage(int _stageNum)
	:scroll(0),
	field(new CActionField(_stageNum)),maker(new CScaffoldMaker())
{
	SetFontSize(15);
}

Stage::~Stage() {
	delete field;
	delete maker;
}

void Stage::Update() {
	DrawBack(field->RightEdge());
	if (field->IsTutorial()) {

	}
	else {
		if (!field->MenuOpening()) {
			maker->Update();
		}
		else {
			maker->OnlyDraw();
			if (field->SelectedReturnStart()) {
				scroll = 0;
				field->Restart();
			}
		}
		field->Update(scroll);
		if (field->MeGotCoin()) {
			maker->AddCoin();
		}
		if (!field->MenuOpening()) {
			Scroll();
			if (maker->DrawFinished()) {
				field->Make(maker->DrawnSpotX(), maker->DrawnSpotY(), maker->DrawnType(), scroll);
			}
		}
	}
	
}

bool Stage::SelectedReturnTitle() {
	return field->SelectedReturnTitle();
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

	if (mouse.X()<0) {
		a -= 8;
	}
	if (mouse.X()>WINDOW_WIDTH) {
		a += 8;
	}

	if (scroll<0) {
		scroll = 0;
	}
	if (scroll>field->RightEdge()*50-WINDOW_WIDTH) {
		scroll = field->RightEdge()*50- WINDOW_WIDTH;
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