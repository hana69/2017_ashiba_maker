#include"Scene.h"
#include"key.h"
#include"mouse.h"
#include"DrawGameOver.h"
#include"DrawGameClear.h"
#include"menu.h"


///////////////////////‚½‚¢‚Æ‚é/////////////////////////
CTitle_S::CTitle_S()
	:stageNum(0),nowSelectableStage(8)
{
	graph[0] = LoadGraph("noseResource/title_NoAction.png");
	graph[1] = LoadGraph("noseResource/title_Wheeled.png");
	explainGraph = LoadGraph("noseResource/title_explain.png");
}

void CTitle_S::Start() {
	stageNum = 0;
	SetFontSize(68);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
}

void CTitle_S::Update() {
	static CMouse mouse;
	int wheelNum = mouse.Wheel();
	if (wheelNum!=0) {
		DrawGraph(0, 0, graph[1], true);
		if (wheelNum < 0) {
			stageNum--;
			if (stageNum < 0) {
				stageNum = 0;
			}
		}
		else if (wheelNum > 0) {
			stageNum++;
			if (stageNum > nowSelectableStage) {
				stageNum = nowSelectableStage;
			}
		}
	}
	else {
		DrawGraph(0, 0, graph[0], true);
	}
	DrawGraph(0, 0, explainGraph, true);

	DrawGraph(0, 0, scaffoldGraph(NORMAL), true);
	DrawGraph(WINDOW_WIDTH - 50, 0, scaffoldGraph(SPEED_UP), true);
	DrawGraph(0, WINDOW_HEIGHT - 50, scaffoldGraph(SPEED_DOWN), true);
	DrawGraph(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 50, scaffoldGraph(JUMP), true);

	DrawFormatString(580, 510, RED, "%d", stageNum);
	if (stageNum==0) {
		static int tutorial_graph = LoadGraph("noseResource/tutorial_string.png");
		DrawGraph(WINDOW_WIDTH/2-215,580,tutorial_graph,true);
	}
}

bool CTitle_S::Changed(){
	if (Mouse.LeftPushed()) {
		return true;
	}
	return false;
}

///////////////////////‚ß‚¢‚ñ/////////////////////////
CMain_S::CMain_S()
	:stageNum(1),scroll(0),returnTitleFlag(false)
{}

void CMain_S::Start(int _stageNum) {
	
	field = new CActionField(_stageNum);
	if (_stageNum == 0) {
		tutorial = new CTutorial();
	}
	returnTitleFlag = false;
	scroll = 0;
	scaffoldDrawer.Reset();
	stageNum = _stageNum;
}

void CMain_S::Update() {
	static int backGraph = LoadGraph("noseResource/main_back.png");
	DrawGraph(0,0,backGraph,true);
	///////////‚®‚è‚Á‚Ç////////////////////////
	for (int i = 0; i <= field->RightEdge()*50; i += 50) {
		DrawLine(i-scroll, 0, i - scroll, WINDOW_HEIGHT, BLUE);
	}
	for (int j = 0; j < WINDOW_HEIGHT;j+=50) {
		DrawLine(0, j, WINDOW_WIDTH,j, BLUE);
	}
	//////////////////////////////////////////
	if (stageNum == 0) {	
		if (!tutorial->Explaining()) {
			if (tutorial->State()>=4) {
				Scroll();
			}
			field->Update(scroll);
			if (field->MeGotCoin()) {
				scaffoldDrawer.AddCoin();
			}
			scaffoldDrawer.Update();
			if (scaffoldDrawer.DrawFinished()) {
				field->Make(scaffoldDrawer.DrawnScaffold(), scroll);
				if (tutorial->State()==3) {
					tutorial->DrawEndEffect();
				}
			}
			
			tutorial->Update(scroll, field->MeX());

			if (field->MenuOpening()) {
				static CMenu menu;
				switch (menu.Update()) {
				case RESUME:
					field->CloseMenu();
					break;
				case RETURN_TO_TITLE_MENU:
					returnTitleFlag = true;
					delete field;
					delete tutorial;
					break;
				case RETURN_TO_START_MENU:
					scroll = 0;
					field->Restart();
					scaffoldDrawer.Reset();
					tutorial->Start();
					break;
				}
			}

			if (field->GameCleared()) {
				static CGameClearMenu gameClearMenu;
				switch (gameClearMenu.Update()) {
				case NEXT_STAGE:
					delete field;
					stageNum++;
					field = new CActionField(stageNum);
					scaffoldDrawer.Reset();
					scroll = 0;
					break;
				case CLEARED_RETURN_TO_TITLE:
					returnTitleFlag = true;
					break;
				}
			}

			if (field->GameOvered()) {
				static CGameOverMenu gameOverMenu;
				switch (gameOverMenu.Update()) {
				case RETRY:
					scroll = 0;
					field->Restart();
					scaffoldDrawer.Reset();
					tutorial->Start();
					break;
				case RETURN_TO_TITLE:
					returnTitleFlag = true;
					delete field;
					delete tutorial;
					break;
				}
			}
		}
		else {
			field->OnlyDraw(scroll);
			scaffoldDrawer.OnlyDraw();
			tutorial->Update(scroll, field->MeX());
		}
	}
	else {
		Scroll();
		field->Update(scroll);
		if (field->MeGotCoin()) {
			scaffoldDrawer.AddCoin();
		}

		scaffoldDrawer.Update();
		if (scaffoldDrawer.DrawFinished()) {
			field->Make(scaffoldDrawer.DrawnScaffold(), scroll);
		}

		if (field->MenuOpening()) {
			static CMenu menu;
			switch (menu.Update()) {
			case RESUME:
				field->CloseMenu();
				break;
			case RETURN_TO_TITLE_MENU:
				returnTitleFlag = true;
				break;
			case RETURN_TO_START_MENU:
				scroll = 0;
				field->Restart();
				scaffoldDrawer.Reset();
				break;
			}
		}

		if (field->GameCleared()) {
			static CGameClearMenu gameClearMenu;
			switch (gameClearMenu.Update()) {
			case NEXT_STAGE:
				if (stageNum < 8) {
					delete field;
					stageNum++;
					field = new CActionField(stageNum);
					scaffoldDrawer.Reset();
					scroll = 0;
				}
				break;
			case CLEARED_RETURN_TO_TITLE:
				returnTitleFlag = true;
				break;
			}
		}

		if (field->GameOvered()) {
			static CGameOverMenu gameOverMenu;
			switch (gameOverMenu.Update()) {
			case RETRY:
				scroll = 0;
				field->Restart();
				scaffoldDrawer.Reset();
				break;
			case RETURN_TO_TITLE:
				returnTitleFlag = true;
				break;
			}
		}
	}
	
}

void CMain_S::Scroll() {
	static CMouse mouse;
	static int a;
	a+=mouse.Wheel(1)*35;
	if (a>50 ) {
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