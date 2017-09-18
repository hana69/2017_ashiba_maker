#pragma once
#include"General.h"
#include"scaffold.h"

class CActionField{
public:
	CActionField();
	~CActionField();
	void Update();
	void Make(NecessaryInfoToMake);
private:
	CScaffold* sc[1000][1000];
	int width;
	int height;
};

