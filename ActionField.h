#pragma once
#include"General.h"
#include<vector>
#include"me.h"

class CActionField{
public:
	CActionField();
	~CActionField();
	void Update(int _scroll);
	void Make(NecessaryInfoToMake _info,int _scroll);
	int RightEdge() { return width; };
private:
	void Collision();
	void Draw(int _scroll);
	void Move();

	std::vector<CScaffold*> sc[500];
	int limit[500];
	int width;
	int height;
	CMe me;
};

