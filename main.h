#pragma once
#include"scaffold.h"
#include"key.h"

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

	CScaffold Scaffold;
};