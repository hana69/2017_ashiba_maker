#pragma once

#include"ScaffoldDrawer.h"
#include"ActionField.h"
#include"Tutorial.h"

class StageManager {
public:
	StageManager();  
	void UpDate();
private:
	bool stageSelecting;
	
};

class CMain_S{
public:
	CMain_S();
	void Start(int _stageNum);
	void Update();
	bool OperatedReturnTitle() { return returnTitleFlag; };
private:
	CActionField* field;
	CScaffoldDrawer scaffoldDrawer;
	int stageNum;

	CTutorial* tutorial;
	
	bool returnTitleFlag;

	int scroll;
	void Scroll();
};




