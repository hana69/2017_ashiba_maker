#include"Tutorial.h"
#include<string>
#include"DxLib.h"
#include"mouse.h"
#include"General.h"

int CTutorial::graph[] = {};
CTutorial::CTutorial()
	:state(0),explaining(false)
{
	std::string s;
	if (graph[1]==0) {
		for (int i = 1; i <= 30; i++) {
			s = "noseResource/tutorial";
			s += std::to_string(i);
			s += ".png";
			graph[i] = LoadGraph(s.c_str());
		}
	}
}
void CTutorial::Start() {
	state = 0;
	explaining = false;
}
void CTutorial::Update(int _scroll,int _x) {
	if (explaining) {
		Draw(_scroll);
		ExplainingNext(_scroll);
	}
	else {
		UnExplainingNext(_scroll, _x);
	}
//	Draw();
}

void CTutorial::Draw(int _scroll) {
	DrawExtendGraph(0 , 0 , WINDOW_WIDTH,WINDOW_HEIGHT, graph[state], true);
}

void CTutorial::ExplainingNext(int _scroll) {
	static CMouse mouse;
	switch (state) {
	case 1:
		if (mouse.LeftPushed()) {
			explaining = false;
		}
		break;
	case 2:
		if(mouse.LeftPushed()) {
			state = 3;
		}
		break;
	case 3:
		if (mouse.LeftPushed()) {
			explaining = false;
		}
		break;
	case 4:
		if (mouse.LeftPushed()) {
			explaining=false;
		}
		break;
	case 5:
		if (mouse.LeftPushed()) {
			explaining = false;
		}
		break;
	case 6:
		if (mouse.LeftPushed()) {
			state = 7;
		}
		break;
	case 7:
		if (mouse.LeftPushed()) {
			state = 8;
		}
		break;
	case 8:
		if (mouse.LeftPushed()) {
			explaining = false;
		}
		break;
	case 9:
		if (mouse.LeftPushed()) {
			explaining = false;
		}
		break;
	}

}

void CTutorial::UnExplainingNext(int _scroll,int _x) {
	switch (state) {
	case 0:
		state = 1;
		explaining = true;
		break;
	case 1:
		if (_x > 250) {
			state = 2;
			explaining = true;
		}
		break;
	case 4:
		if (_scroll <=50 && _x > 800 ) {
			explaining = true;
			state = 5;
		}
		if (_scroll >= 700) {
			explaining = true;
			state = 6;
		}
		break;
	case 5:
		if (_scroll >= 700) {
			explaining = true;
			state = 6;
		}
		break;
	case 8:
		if (_scroll >= 79*50) {
			explaining = true;
			state = 9;
		}
		break;
	default: break;
	}
}

void CTutorial::DrawEndEffect() {
	explaining = true;
	state = 4;
}