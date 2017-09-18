#pragma once
#include"General.h"
#include"mouse.h"
struct NecessaryInfoToMake {
	int width;
	int height;
	int x, y;
	ScaffoldType type;
};

class CScaffold {
public:
	CScaffold(int _cost);
	virtual void Draw() = 0;
	virtual void HitEffect() {};
	virtual ScaffoldType Type()=0;
	int Cost() { return cost; };
protected:
	int x, y;
	static int graph;
	const int cost;
};

class CNormal :public CScaffold {
public:
	CNormal();
	void Draw();
	ScaffoldType Type() {
		return NORMAL;
	};
};

class CSpeedUp :public CScaffold {
public:
	CSpeedUp();
	void Draw();
	ScaffoldType Type() {
		return SPEED_UP;
	};
};

class CSpeedDown :public CScaffold {
public:
	CSpeedDown();
	void Draw();
	ScaffoldType Type() {
		return SPEED_DOWN;
	};
};

class CJump :public CScaffold {
public:
	CJump();
	void Draw();
	void HitEffect();
	ScaffoldType Type() {
		return JUMP;
	}
};

