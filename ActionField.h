#pragma once
#include"General.h"
#include<vector>
#include"coin.h"
#include"Me.h"

class CActionField{
public:
	CActionField();
	~CActionField();
	
	void Update(int _scroll);
	void Make(NecessaryInfoToMake _info,int _scroll);
	void Restart();

	bool GameOvered() { return me.GameOver(); };
	int RightEdge() { return width; };
private:
	void Collision();
	void Draw(int _scroll);
	void Move();

	CScaffold firstSc[500][15];
	bool firstPut[500][15];

	std::vector<CScaffold*> sc[500];
	int limit[500];
	
	int width;
	int height;
	
	bool returnTitleFlag;

	CMe me;
	CCoin coin;
};