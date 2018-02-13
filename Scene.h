#pragma once

#include"ScaffoldDrawer.h"
#include"ActionField.h"
#include"Tutorial.h"

class CTitle_S {
public:
	CTitle_S();
	void Start();
	void Update();
	bool Changed();
	int SelectedStageNum() { return stageNum; };
private:
	CMouse Mouse;
	int graph[2];
	int explainGraph;

	int stageNum;
	int nowSelectableStage;
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




