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

	CScene* scene;

	CTitle_S TITLE_S;
	CMain_S MAIN_S;
	//CScaffold Scaffold;
};