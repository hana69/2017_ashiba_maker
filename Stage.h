#pragma once

class Stage {
public:
	Stage(int _stageNum);
	void Update();
private:
	void Scroll();
	void DrawBack(int rightEdge);
	const int stageNum;
	int scroll;
};
