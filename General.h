#pragma once

#include<string>
/////ゲーム用定数/////
enum ScaffoldType{
	JUMP,
	SPEED_UP,
	SPEED_DOWN,
	NORMAL,
	ScaffoldTypeNum
};

//////////////////鼻ライブラリver0

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

static bool loopEscapeFlag = false;
static std::string errorMes = "";

static void EscapeProgram() {
	loopEscapeFlag = true;
};
static void EscapeProgram(const char* _mes) {
	loopEscapeFlag = true;
	errorMes = _mes;
};

////////////////////////////////////////////////////////////////
