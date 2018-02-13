#pragma once

#include"mouse.h"

enum MENU_RETURN{
	NO_ACTION_MENU,
	RESUME,
	RETURN_TO_TITLE_MENU,
	RETURN_TO_START_MENU,
	MENU_STATE_NUM
};

class CMenuState;
class CMenu {
public:
	CMenu();
	MENU_RETURN Update();
private:
	int x, y;
	CMouse mouse[MENU_STATE_NUM];
	MENU_RETURN selectingState;
	static int graph[MENU_STATE_NUM];
};