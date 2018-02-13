#pragma once

#include"Scene.h"

class CMain{
public:
	CMain();
	void GameLoop();
	void Awake();
private:
	int frame,tempframe;
	
	int backPic;
	int titleBGM;

	enum {
		TITLE_S,
		MAIN_S
	}scene;

	CTitle_S title;
	CMain_S main;
	//CScaffold Scaffold;
};