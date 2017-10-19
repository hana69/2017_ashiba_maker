#pragma once
#include"General.h"

struct NecessaryInfoToMake {
	int x1, y1,x2,y2;
	ScaffoldType type;
};

class CScaffold {
	static const int cost[ScaffoldTypeNum];
public:
	CScaffold(ScaffoldType,int _xPlace,int _yPlace);
	void Draw(int _scroll);
	void Move(int _limit);
	void HitEffect();

	ScaffoldType Type() { return type; };
	int Cost() { return cost[type]; };
	float X() { return x; };
	float Y() { return y; };
protected:
	ScaffoldType type;
	float x, y;
};


