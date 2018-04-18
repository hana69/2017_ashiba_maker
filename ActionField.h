#pragma once
#include"General.h"
#include<vector>
#include"coin.h"
#include"Me.h"

class CActionField{
public:
	CActionField(int _stageNum);
	~CActionField();
	
	void Update(int _scroll);
	void Make( int _x , int _y , ScaffoldType _type , int _scroll );
	void Restart();

	bool MeGotCoin() { return coinGotFlag; };
	bool GameOvered() { return me.GameOver(); };
	bool GameCleared() { return me.GameClear(); };
	bool MenuOpening() { return menuOpening; };

	void CloseMenu() { menuOpening = false; };

	void OnlyDraw(int _scroll);

	int RightEdge() { return width; };
	int MeX() { return me.X(); };
private:
	void Draw(int _scroll);
	void Collision();
	
		void DrawLimit(int _scroll);
	void Move();

	CScaffold firstSc[500][15];
	bool firstPut[500][15];

	std::vector<CScaffold*> sc[500];
	int limit[500];
	
	int width;
	int height;
	
	bool returnTitleFlag;
	bool coinGotFlag;
	bool menuOpening;

	static int limitdata[10];
	static int mapdata[10];

	CMe me;
	CCoin coin;
};