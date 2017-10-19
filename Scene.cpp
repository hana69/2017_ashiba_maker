#include"Scene.h"
#include"key.h"

CScene::CScene(const CScene* _next) 
	:next(_next)
{}

const CScene* CScene::Next() {
	return next;
}
///////////////////////‚½‚¢‚Æ‚é/////////////////////////
CTitle_S::CTitle_S(const CScene* _n)
	:CScene(_n)
{}

void CTitle_S::Update() {
	DrawString(0, 0, "‚½‚¢‚Æ‚é", RED);
}

bool CTitle_S::Changed(){
	if (Mouse.LeftReleased()) {
		return true;
	}
	return false;
}

///////////////////////‚ß‚¢‚ñ/////////////////////////
CMain_S::CMain_S(const CScene* _n)
	:CScene(_n),scroll(0)
{}

void CMain_S::Update() {
	DrawString(0, 0, "main", RED);
	Scroll();
	///////////‚®‚è‚Á‚Ç////////////////////////
	for (int i = 0; i <= field.RightEdge()*50; i += 50) {
		DrawLine(i-scroll, 0, i - scroll, WINDOW_HEIGHT, RED);
	}
	for (int j = 0; j < WINDOW_HEIGHT;j+=50) {
		DrawLine(0, j, WINDOW_WIDTH,j, RED);
	}
	//////////////////////////////////////////

	scaffoldDrawer.Update();
	
	if (scaffoldDrawer.DrawFinished()) {
		field.Make(scaffoldDrawer.DrawnScaffold(),scroll);
	}
	field.Update(scroll);
	
}

bool CMain_S::Changed() {
	if (Key.Pushed(KEYNAME.ENTER)) {
		return true;
	}
	return false;
}

void CMain_S::Scroll() {
	static CMouse mouse;
	static int a;
	a+=mouse.Wheel(1)*25;
	if (a>50 ) {
		scroll += 50;
		a = 0;
	}
	else if (a<-50) {
		scroll -= 50;
		a = 0;
	}
	if (scroll<0) {
		scroll = 0;
	}
}