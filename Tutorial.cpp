#include"Tutorial.h"
#include<string>
#include"DxLib.h"
#include"mouse.h"
#include"General.h"
#include"ActionField.h"
#include"ScaffoldMaker.h"

int Tutorial::graph[] = {};
Tutorial::Tutorial()
	:state(ExplainState::FIRST),explaining(false),
	field(new CActionField(0)),maker(new CScaffoldMaker()),
	scroll(0),drawFlag(false),meMoveFlag(true),scrollFlag(false),
	backGraph(LoadGraph("noseResource/normalBack.png"))
{
	std::string s;
	if (graph[1]==0) {
		for (int i = 1; i <= 10; i++) {
			s = "noseResource/tutorial/tutorial";
			s += std::to_string(i);
			s += ".png";
			graph[i] = LoadGraph(s.c_str());
		}
	}
	Start();
	SetFontSize(15);
}
Tutorial::~Tutorial() {
	delete field;
	delete maker;
}

void Tutorial::Start() {
	state = ExplainState::FIRST;
	explaining = false;
	scrollFlag = false;
	meMoveFlag = true;
	for (int i = 0; i < 7;i++) {
		maker->AddCoin();
	}
}
void Tutorial::Update() {
	DrawBack();
	
	StateFunc();
	if (meMoveFlag == true) {
		field->Update(scroll);
	}
	else {
		field->OnlyDraw(scroll);
	}
	if (drawFlag == true) {
		DrawExtendGraph(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, graph[(unsigned)state], true);
	}
	if (scrollFlag==true) {
		Scroll();
	}
}
void Tutorial::StateFunc() {
	static CMouse mouse;
	switch (state) {
	case ExplainState::FIRST:
		if (field->MeX()>250) {
			state = ExplainState::ROAD_IS_BROKEN;
			drawFlag = true;
			meMoveFlag = false;
		}
		maker->OnlyDraw();
		break;
	case ExplainState::ROAD_IS_BROKEN:
		if (mouse.LeftReleased()) {
			state = ExplainState::LETS_CLICK;
		}
		maker->OnlyDraw();
		break;
	case ExplainState::LETS_CLICK:
		if(maker->DrawFinished()) {
			field->Make(maker->DrawnSpotX(), maker->DrawnSpotY(), maker->DrawnType(), scroll);
			meMoveFlag = true;
		}
		if (field->MeX() > 700) {
			state = ExplainState::MP_DECREASE;
			meMoveFlag = false;
		}
		maker->Update();
		break;
	case ExplainState::MP_DECREASE:
		if (mouse.LeftReleased()) {
			drawFlag = false;
			meMoveFlag = true;
			scrollFlag = true;
		}
		if (field->MeX() > 750) {
			state = ExplainState::SCROLL;
			meMoveFlag = false;
			drawFlag = true;
		}
		maker->OnlyDraw();
		break;
	case ExplainState::SCROLL:
		if (mouse.LeftReleased()) {
			drawFlag=false;
			meMoveFlag = true;
		}
		if (scroll > 500) {
			state = ExplainState::DISCOVER_COIN;
			drawFlag = true;
			meMoveFlag = false;
			scrollFlag = false;
		}
		maker->OnlyDraw();
		break;
	case ExplainState::DISCOVER_COIN:
		if (mouse.LeftReleased()) {
			drawFlag = false;
			meMoveFlag = true;
		}
		if (field->MeGotCoin()) {
			maker->AddCoin();
			state = ExplainState::MP_GAIN;
			drawFlag = true;
			meMoveFlag = false;
		}
		maker->OnlyDraw();
		break;
	case ExplainState::MP_GAIN:
		if (mouse.LeftReleased()) {
			state = ExplainState::GO_TROUGH_SINLE_HOLE;
			drawFlag = false;
			meMoveFlag = true;
		}
		maker->OnlyDraw();
		break;
	case ExplainState::GO_TROUGH_SINLE_HOLE:
		maker->OnlyDraw();
		break;
	}
}

void Tutorial::Scroll() {
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
	//////マウスが画面外左右にいったらスクロール/////////
	if (mouse.X()<0) {
		a -= 8;
	}
	if (mouse.X()>WINDOW_WIDTH) {
		a += 8;
	}
	/////////////////////////////////////////////////////

	/////////スクロールの左限右限を設定/////////////
	if (scroll<0) {
		scroll = 0;
	}
	if (scroll>field->RightEdge() * 50 - WINDOW_WIDTH) {
		scroll = field->RightEdge() * 50 - WINDOW_WIDTH;
	}
	////////////////////////////////////////////////
}

void Tutorial::DrawBack() {
	DrawGraph(0, 0, backGraph, true);
	///////////ぐりっど////////////////////////
	for (int i = 0; i <= field->RightEdge() * 50; i += 50) {
		DrawLine(i - scroll, 0, i - scroll, WINDOW_HEIGHT, BLUE);
	}
	for (int j = 0; j < WINDOW_HEIGHT; j += 50) {
		DrawLine(0, j, WINDOW_WIDTH, j, BLUE);
	}
	//////////////////////////////////////////
}