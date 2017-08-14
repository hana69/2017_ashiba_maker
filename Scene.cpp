#include"Scene.h"

CScene::CScene(const CScene* _next) 
	:next(_next)
{}

const CScene* CScene::Next() {
	return next;
}
///////////////////////�����Ƃ�/////////////////////////
CTitle_S::CTitle_S(const CScene* _n)
	:CScene(_n)
{}

void CTitle_S::Update() {
	DrawString(0, 0, "�����Ƃ�", RED);
}

bool CTitle_S::Changed(){
	if (Mouse.LeftReleased()) {
		return true;
	}
	return false;
}

///////////////////////�߂���/////////////////////////
CMain_S::CMain_S(const CScene* _n)
	:CScene(_n)
{}

void CMain_S::Update() {
	DrawString(0, 0, "main", RED);
	scaffoldMaker.UpDate();
}

bool CMain_S::Changed() {
	if (Key.Pushed(KEYNAME.ENTER)) {
		return true;
	}
	return false;
}
