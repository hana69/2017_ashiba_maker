#pragma once
#include"General.h"
#include<vector>

class CMe;
class CCoin;
class Pause;
class GameOverMenu;
class GameClearMenu;
class CScaffold;
class SaveData;


class CActionField{
public:
	CActionField(int _stageNum);
	~CActionField();
	
	void Update(int _scroll);
	void Make( int _x , int _y , ScaffoldType _type , int _scroll );
	void Restart();

	bool IsTutorial() { return isTutorial; };

	bool MeGotCoin() { return coinGotFlag; };
	bool MenuOpening(){ return menuOpening; };

	bool SelectedReturnStart() {return returnStartFlag; };
	bool SelectedReturnTitle() { return returnTitleFlag; };
	bool SelectedGoToNextStage() { return goToNextStageFlag; };

	bool GameOvered();
	bool GameCleared();

	void CloseMenu() { menuOpening = false; };

	void OnlyDraw(int _scroll);

	int RightEdge() { return width; };
	int MeX();
private:
	void MenuButtonUpdate();
	void Draw(int _scroll);
		void DrawLimit(int _scroll);
	void Collision();
		void EraserCollision();
		
	void Move();

	CScaffold* firstSc[500][15];
	bool firstPut[500][15];

	std::vector<CScaffold*> sc[500];
	int limit[500];
	
	int width;
	int height;

	bool isTutorial;
	bool underSea;
	
	bool returnTitleFlag;
	bool returnStartFlag;
	bool goToNextStageFlag;
	bool coinGotFlag;
	bool menuOpening;

	static int limitdata[10];
	static int mapdata[10];

	CMe* me;
	CCoin* coin;
	Pause* pauseMenu;
	GameOverMenu* gameOverMenu;
	GameClearMenu* gameClearMenu;

	void (CActionField::*gameClearFuncs[2])();
	void (CActionField::*gameOverFuncs[2])();
	void (CActionField::*pauseFuncs[3])();
		void ReturnToTitle();
		void ReturnToStart();
		void Resume();	
		void GoToNextStage();
};