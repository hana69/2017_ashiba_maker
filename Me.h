#pragma once
#include"scaffold.h"
#include"Coin.h"

//class SaveData;

class CMe {
public:
	CMe(int _stageNum);
	~CMe();
	void SetV(bool);
	void Move();
	void ResetV();

	void ResetHit() { 
		hitUnderSide = false;
		hitOverSide = false;
	};

	void Restart();

	void Draw(int _scroll);
	bool CollidedWith(CScaffold* _sc);

	bool GameOver() { return gameOver; };
	bool GameClear() { return gameClear; };

	int X() { return x; };
	int Y() { return y; };

	int Duration() { return duration; };
private:
	void HitEffect(ScaffoldType,int _x,int _y);

//	SaveData* sd;

	bool hitUnderSide;
	bool hitOverSide;

	int diedScUpY;
	int diedScDownY;
	bool pressedDie;
	
	bool gameOver;
	bool gameClear;

	const int stageNum;
	int startTime;//スタート時の時間を記録
	int duration;

	int graph;
	float x,y;
	float vx, vy;
};