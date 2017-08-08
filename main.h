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

	const CTitle_S Title_S;
	const CMain_S Main_S;

	//CScaffold Scaffold;
};