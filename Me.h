#pragma once
#include"scaffold.h"

class CMe {
public:
	CMe();
	void SetV();
	void Move();
	void ResetV();

	void Draw(int _scroll);
	bool CollidedWith(CScaffold* _sc);

	bool GameOver() { return gameOver; };

	int X() { return x; };
	int Y() { return y; };
private:
	void HitEffect(ScaffoldType);
	bool gameOver;
	int graph;
	float x,y;
	float vx, vy;
};