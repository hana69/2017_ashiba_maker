#pragma once
#include"mouse.h"

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
