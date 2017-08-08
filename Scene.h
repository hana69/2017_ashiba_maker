#pragma once
#include"key.h"
#include"MakeScaffold.h"

class CScene {
public:
	CScene(const CScene*);
	virtual void Update()=0;
	virtual bool Changed()=0;
	const CScene* Next();
private:
	const CScene* next;
};

class CTitle_S :public CScene {
public:
	CTitle_S(const CScene*);
	void Update();
	bool Changed();
private:
};

class CMain_S :public CScene {
public:
	CMain_S(const CScene*);
	void Update();
	bool Changed();
private:
	CMakeScaffold scaffoldMaker;
};




