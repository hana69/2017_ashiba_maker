#pragma once

#include<string>
#include"DxLib.h"


//////////////////ライブラリver0

//#define IDI_ICON1 101

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 720

#define RED GetColor( 255 , 0 , 0 )
#define GREEN GetColor( 0 , 255 , 0 )
#define BLUE GetColor( 0 , 0 , 255 )
#define BLACK GetColor( 0 , 0 , 0 )
#define WHITE GetColor( 255 , 255 , 255 )
#define GRAY GetColor( 128 , 128 , 128 )
#define YELLOW GetColor( 255 , 255 , 0)
#define LIGHTBLUE GetColor( 128 , 255 , 255 )
#define PURPLE GetColor( 128 , 0 , 128)
#define BROWN GetColor(128,64,0)

/////エラー時脱出用関数////////


static bool EscapeProgram(bool escapeScene = false) {
	static bool loopEscapeFlag = false;
	if (!escapeScene) {
		loopEscapeFlag = true;
	}
	return loopEscapeFlag;
};
static bool EscapeProgram(const char* _mes,bool escapeScene=false) {
	static bool loopEscapeFlag = false;
	static std::string errorMes = "";
	if (!escapeScene) {
		loopEscapeFlag = true;
	}
	errorMes = _mes;
	return loopEscapeFlag;
};

////////////////////////////////////////////////////////////////

/////ゲーム用定数/////
enum ScaffoldType {
	JUMP,
	SPEED_DOWN,
	SPEED_UP,
	NORMAL,
	ScaffoldTypeNum
};

static int scaffoldGraph(ScaffoldType _type) {
	static int graph[ScaffoldTypeNum] = {};
	if (graph[_type] == 0) {
		LoadDivGraph("noseResource/Scaffold.png", (int)ScaffoldTypeNum, 3, 3, 50, 50, graph);
	}
	return graph[_type];
};

const int DRAW_AREA_TOP = WINDOW_HEIGHT - 50 * 3 - 20 - 1,
		  DRAW_AREA_LEFT = 20,
		  DRAW_AREA_RIGHT = WINDOW_WIDTH - (20 * 2 + 50);