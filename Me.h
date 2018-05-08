#pragma once
#include"scaffold.h"
#include"Coin.h"

class CMe {
public:
	CMe();
	void SetV();
	void Move();
	void ResetV();

	void ResetHit() { hitUnderSide = false; };

	void Restart();

	void Draw(int _scroll);
	bool CollidedWith(CScaffold* _sc);

	bool GameOver() { return gameOver; };
	bool GameClear() { return gameClear; };

	int X() { return x; };
	int Y() { return y; };
private:
	void HitEffect(ScaffoldType,int _x,int _y);

	bool hitUnderSide;
	bool hitOverSide;

	int diedScUpY;
	int diedScDownY;
	bool pressedDie;
	
	bool gameOver;
	bool gameClear;

	int graph;
	float x,y;
	float vx, vy;
};