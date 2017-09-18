#include"ScaffoldMaker.h"
#include<math.h>
CScaffoldDrawer::CScaffoldDrawer()
	:selector(WINDOW_WIDTH - (20 * 2 + 50), WINDOW_HEIGHT - (50 * 4 + 20 * 5), WINDOW_WIDTH, WINDOW_HEIGHT),
	x1(20), y1(WINDOW_HEIGHT - 280), x2(WINDOW_WIDTH - (20 * 2 + 50)), y2(WINDOW_HEIGHT - 20),
	init(false), writing(false), drawFinished(false),
	Mouse(x1, y1, x2, y2)
{}

void CScaffoldDrawer::Init(){
	LoadDivGraph("noseResource/Scaffold.png", (int)ScaffoldTypeNum, 3, 3, 50, 50, scaffoldGraph);
	selector.Init();
}

void CScaffoldDrawer::Update() {
	if (!init) {
		Init();
		init = true;
	}
	Draw();
	selector.Update();
}


/////////////publicä÷êî//////////////////////

////////////privateä÷êî//////////////////////

void CScaffoldDrawer::Draw() {
	DrawBox(x1, y1, x2, y2, WHITE, false);

	if (Mouse.Insided()) {
		if (Mouse.LeftPushed() && !writing ) {
			writing = true;
			Mouse.SetTemp();
		}
	}
	
	if (Mouse.LeftReleased() && writing) {
		writing = false;
		drawFinished = true;
		SetInfo();
	}
	
	if (writing) {
		for (int i = Mouse.TempX() + PlusMinus(Mouse.ChangeX()) * 25;
			std::abs(i - (Mouse.TempX() + PlusMinus(Mouse.ChangeX()) * 25)) <= std::abs(Mouse.ChangeX());
			i += PlusMinus(Mouse.ChangeX()) * 50) {
			for (int j = Mouse.TempY() + PlusMinus(Mouse.ChangeY()) * 25;
				std::abs(j - (Mouse.TempY() + PlusMinus(Mouse.ChangeY()) * 25)) <= std::abs(Mouse.ChangeY());
				j += PlusMinus(Mouse.ChangeY()) * 50 ) {
				if (x1 < i - 25  &&  i + 25 < x2 && y1 < j - 25 && j + 25 < y2 ) {
					DrawGraph(i - 25, j - 25, scaffoldGraph[selector.SelectingType()], true);
				}
			}
		}
	}

}
	
	void CScaffoldDrawer::SetInfo() {
		writingObj.width = std::abs(Mouse.ChangeX() / 50 );//êÿÇËéÃÇƒ
		writingObj.height = std::abs(Mouse.ChangeY() / 50);//êÿÇËéÃÇƒ
		writingObj.type = selector.SelectingType();
		if (Mouse.ChangeX() < 0) {
			writingObj.x = Mouse.TempX()+ Mouse.ChangeX() / 50 * 50;
		}
		else {
			writingObj.x = Mouse.TempX();
		}
		if (Mouse.ChangeY() < 0) {
			writingObj.y = Mouse.TempY() + Mouse.ChangeY() / 50 * 50;
		}
		else {
			writingObj.y = Mouse.TempY();
		}
	}
///////////////////////////CSelectField////////////////////////////////////

CScaffoldSelector::CScaffoldSelector(int _x1, int _y1, int _x2, int _y2)
	:x1(_x1), x2(_x2), y1(_y1), y2(_y2),
	init(false),selectingType(NORMAL)
{
	for (int i = 0; i <ScaffoldTypeNum;i++) {
		selectableObj[i].SetPosition(x1+20, y1+20+i*70);
	}
}

void CScaffoldSelector::Init() {
	for (int i = 0; i < ScaffoldTypeNum;i++) {
		selectableObj[i].SetType((ScaffoldType)i);
	}
	selectingType = NORMAL;
}
void CScaffoldSelector::Update() {
	Draw();
	for (auto i :selectableObj) {
		i.Select(&selectingType);
	}
}

void CScaffoldSelector::Draw() {
	for (int i = 0; i < ScaffoldTypeNum; i++) {
		selectableObj[i].Draw();
	}
}

CScaffoldSelector::CSelectableObj::CSelectableObj()
	:x(0), y(0), type(NORMAL)
{}

void CScaffoldSelector::CSelectableObj::Draw() {
	DrawGraph(x, y, scaffoldGraph[type], true);
	if (Mouse.Insided()) {
		DrawBox(x, y, x + 50, y + 50, YELLOW, false);
	}
}

void CScaffoldSelector::CSelectableObj::SetPosition(int _x,int _y) {
	x = _x;
	y = _y;
	Mouse.SetRange(_x, _y, _x + 50, _y + 50);
}

void CScaffoldSelector::CSelectableObj::Select(ScaffoldType* _selectingType ) {
	if (Mouse.Insided() && Mouse.LeftPushed()) {
		*_selectingType = type;
	}
}
