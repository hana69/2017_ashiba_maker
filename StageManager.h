#pragma once

#include"ScaffoldDrawer.h"
#include"ActionField.h"
#include"Tutorial.h"

const int TUTORIAL = 0;
const int FINALSTAGE_NUM = 8;

class Stage {
public:
	Stage(int stageNum);
	void Update() {};
};

class StageManager {
public:
	StageManager();  
	void UpDate();
private:
	bool stageSelecting;
	Stage* stage;
};

class StageSelector {
public:
	StageSelector();
	bool SelectFinished();
	int SelectedStage() {
		return selectingStageNum;
	};
private:
	static CMouse mouse;
	void SelectStageByMouse();
	int selectingStageNum;
	int nowSelectableStageNumMax;
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




