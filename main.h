#pragma once
#include"DxLib.h"
#include"General.h"

class CMain{
public:
	CMain();
	void GameLoop();
	void Awake();
private:
	int frame,tempframe;
	
	enum{
		TITLE,
		MAIN
	}scene;
	
	int backPic;
	int titleBGM;

};