#include"Menu.h"
#include"ClickObj.h"
#include"General.h"

Menu::Menu(int _x,int _y)
	:x(_x),y(_y)
{}

void Menu::Update() {
	DrawBox(x, y, x + 200, y + 150, BLACK, true);
	DrawBox(x, y, x + 200, y + 150, YELLOW, false);
	for (auto i:texts) {
		i->Update();
	}
}
Menu::~Menu() {
	for (auto i : texts) {
		delete i;
	}
}

Pause::Pause()
	:Menu(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 75),selectedText(Texts::RESUME)
{
	int graph[(unsigned)Texts::MAX][4] = {};
	int w = 173;
	LoadDivGraph("noseResource/ReturnToStart_4in1.png", (unsigned)Texts::MAX, 1, (unsigned)Texts::MAX, w, 20, graph[(unsigned)Texts::RETURN_TO_START]);
	LoadDivGraph("noseResource/ReturnToTitle_4in1.png", (unsigned)Texts::MAX, 1, (unsigned)Texts::MAX, w, 20, graph[(unsigned)Texts::RETURN_TO_TITLE]);
	LoadDivGraph("noseResource/CloseMenu_4in1.png", (unsigned)Texts::MAX, 1, (unsigned)Texts::MAX, w, 20, graph[(unsigned)Texts::RESUME] );
	int c = WINDOW_WIDTH / 2;
	for (int i = 0; i < (int)Texts::MAX; i++) {
		if (graph[i][0]!=0) {
			texts.push_back(new ClickObj(c - w / 2, y + 50 + i * 30, c + w / 2, y + 50 + i * 30 + 20, graph[i]));
		}
	}
}

bool Pause::Selected() {
	for (int i = 0; i < /*(int)Texts::MAX*/texts.size();i++ ) {
		if (texts[i]->Clicked()) {
			selectedText = (Texts)i;
			return true;
		}
	}
	return false;
}


//CMenu::CMenu() 
//	:selectingState(RESUME),
//	x(WINDOW_WIDTH / 2 - 100),y(WINDOW_HEIGHT / 2 - 75)
//{
//	mouse[RESUME].SetRange(x+48,y+56,x+157,y+69);
//	mouse[RETURN_TO_START_MENU].SetRange(x+12,y+87,x+190,y+98);
//	mouse[RETURN_TO_TITLE_MENU].SetRange(x+45,y+118,x+155,y+130);
//
//	if (graph[NO_ACTION_MENU] == 0) {
//		graph[NO_ACTION_MENU] = LoadGraph("noseResource/Menu.png");
//	}
//	if (graph[RESUME]==0) {
//		graph[RESUME] = LoadGraph("noseResource/Menu_Resume.png");
//	}
//	if (graph[RETURN_TO_TITLE_MENU] == 0) {
//		graph[RETURN_TO_TITLE_MENU] = LoadGraph("noseResource/Menu_ReturnTitle.png");
//	}
//	if (graph[RETURN_TO_START_MENU] == 0) {
//		graph[RETURN_TO_START_MENU] = LoadGraph("noseResource/Menu_ReturnStart.png");
//	}
//}
//
//MENU_RETURN CMenu::Update() {
//	selectingState = NO_ACTION_MENU;
//
//	for (int i = 1; i < MENU_STATE_NUM;i++ ) {
//		if (mouse[i].Insided()) {
//			selectingState = (MENU_RETURN)i;
//		}
//	}
//	DrawGraph(x, y, graph[selectingState], true);
//	if (mouse[selectingState].LeftPushed()) {
//		return selectingState;
//	}
//
//	return NO_ACTION_MENU;
//	
//}