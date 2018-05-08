#pragma once
class CActionField;
class CScaffoldMaker;

class Stage{
public:
	Stage(int _stageNum);
	~Stage();
	void Update();
	bool SelectedReturnTitle();
private:
	void Scroll();
	void DrawBack(int rightEdge);
	int scroll;
	CActionField *field;
	CScaffoldMaker *maker;
};
