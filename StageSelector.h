#pragma once
#include"mouse.h"

class StageSelector {
public:
	StageSelector();
	void Update();
	bool SelectFinished();
	int SelectedStage() {
		return selectingStageNum;
	};
private:
	CMouse mouse;
	void SelectStageByMouse();
	int selectingStageNum;
	int nowSelectableStageNumMax;
};
