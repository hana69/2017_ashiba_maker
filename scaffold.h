#pragma once
#include"General.h"
#include"mouse.h"

class CScaffold {
public:
	CScaffold(int _graph);
	void Draw();
	virtual void HitEffect()=0;
private:
	int x, y;
	int graph;
	const int cost;
};

class CNormal :public CScaffold {
public:
	CNormal();
	void HitEffect();
};

class CSpeedUp :public CScaffold {
	void HitEffect();
};

class CSpeedDown :public CScaffold {
	void HitEffect();
};


