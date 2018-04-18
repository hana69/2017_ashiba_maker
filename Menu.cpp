//#include"Menu.h"
//#include"General.h"
//
//Menu_Interface::Menu_Interface()
//	:x(WINDOW_WIDTH / 2 - 100),y(WINDOW_HEIGHT / 2 - 75)
//{
//
//}
//
//void Menu_Interface::Update() {
//	for (int i = 1; i < MENU_STATE_NUM; i++) {
//		if (mouse[i].Insided()) {
//			selectingState = (MENU_RETURN)i;
//		}
//	}
//	DrawGraph(x, y, graph[selectingState], true);
//	if (mouse[selectingState].LeftPushed()) {
//
//	}
//}
//
//
//
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