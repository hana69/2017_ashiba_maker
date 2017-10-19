#include"ScaffoldDrawer.h"
#include<math.h>

CScaffoldDrawer::CScaffoldDrawer()
	:selector(WINDOW_WIDTH - (20 * 2 + 50), WINDOW_HEIGHT - (50 * 4 + 20 * 5), WINDOW_WIDTH, WINDOW_HEIGHT),
	x1(DRAW_AREA_LEFT), y1(DRAW_AREA_TOP), x2(DRAW_AREA_RIGHT), y2(DRAW_AREA_TOP+50*3+1),
	writing(false), drawFinished(false),
	Mouse(x1, y1, x2, y2)
{}
/////////////publicä÷êî//////////////////////

void CScaffoldDrawer::Update() {
	Draw();
	selector.Update();
}

bool CScaffoldDrawer::DrawFinished() {
	if (drawFinished) {
		drawFinished = false;
		return true;
	}
	return false;
}

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
		const int tX = Mouse.TempX(), X = Mouse.X(), cX = Mouse.ChangeX(),
				  tY = Mouse.TempY(), Y = Mouse.Y(), cY = Mouse.ChangeY();
		/*for (int i = tX / 50 + (tX % 50) / 25,nowCX=0; abs(nowCX) <= cX; i += PlusMinus(Mouse.ChangeX()), nowCX += PlusMinus(Mouse.ChangeX()) ) {
			for (int j = tY / 50 + (tY % 50) / 25,nowCY=0; abs(nowCY) <= cY; j += PlusMinus(Mouse.ChangeY()), nowCY += PlusMinus(Mouse.ChangeY()) ) {
				if (x1 < i*50 && i*50 < x2 && y1 < j*50 && j*50 <y2) {
					DrawGraph(i * 50, j * 50, scaffoldGraph(selector.SelectingType()), true);
				}
			}
		}*/
		if (cX > 0 && cY > 0) {
			for (int i = tX / 50 + tX % 50 / 25; i <= X / 50 + X % 50 / 25 - 1;i++) {
				for (int j = tY / 50 + tY % 50 / 25; j <= Y / 50 + Y % 50 / 25 - 1; j++) {
					if (x1 < i * 50 && i * 50 < x2 && y1 < j * 50 && j * 50 <y2) {
						DrawGraph(i * 50, j * 50, scaffoldGraph(selector.SelectingType()), true);
					}
				}
			}
		}
		else if (cX > 0 && cY < 0) {
			for (int i = tX / 50 + tX % 50 / 25; i <= X / 50 + X % 50 / 25 - 1; i++) {
				for (int j = tY / 50 + tY % 50 / 25 - 1; j >= Y / 50 + Y % 50 / 25;j--) {
					if (x1 < i * 50 && i * 50 < x2 && y1 < j * 50 && j * 50 <y2) {
						DrawGraph(i * 50, j * 50, scaffoldGraph(selector.SelectingType()), true);
					}
				}
			}
		}
		else if (cX < 0 && cY > 0) {
			for (int i = tX / 50 + tX % 50 / 25 - 1; i >= X / 50 + X % 50 / 25; i--) {
				for (int j = tY / 50 + tY % 50 / 25; j <= Y / 50 + Y % 50 / 25 - 1; j++) {
					if (x1 < i * 50 && i * 50 < x2 && y1 < j * 50 && j * 50 < y2) {
						DrawGraph(i * 50, j * 50, scaffoldGraph(selector.SelectingType()), true);
					}
				}
			}
		}
		else {
			for (int i = tX / 50 + tX % 50 / 25 - 1; i >= X / 50 + X % 50 / 25; i--) {
				for (int j = tY / 50 + tY % 50 / 25 - 1; j >= Y / 50 + Y % 50 / 25; j--) {
					if (x1 < i * 50 && i * 50 < x2 && y1 < j * 50 && j * 50 < y2) {
						DrawGraph(i * 50, j * 50, scaffoldGraph(selector.SelectingType()), true);
					}
				}
			}
		}
	}
	

}
	
	void CScaffoldDrawer::SetInfo() {
		writingObj.type = selector.SelectingType();
		
		const int tX = Mouse.TempX(), X = Mouse.X(), cX = Mouse.ChangeX(),
				  tY = Mouse.TempY(), Y = Mouse.Y(), cY = Mouse.ChangeY();
		if (cX > 0) {
			writingObj.x1 = tX/ 50 + tX % 50/ 25;
			writingObj.x2 = X / 50 + X % 50 / 25 - 1;
		}
		else {
			writingObj.x1 = X / 50 + X % 50 / 25;
			writingObj.x2 = tX / 50 + tX % 50 / 25 - 1;
		}
		if (Mouse.ChangeY() > 0) {
			writingObj.y1 = tY / 50 + tY % 50 / 25;
			writingObj.y2 = Y / 50 + Y % 50 / 25 - 1;
		}
		else {
			writingObj.y1 = Y / 50 + Y % 50 / 25;
			writingObj.y2 = tY / 50 + tY % 50 / 25 - 1;
		}
	}
///////////////////////////CSelectField////////////////////////////////////

CScaffoldSelector::CScaffoldSelector(int _x1, int _y1, int _x2, int _y2)
	:x1(_x1), x2(_x2), y1(_y1), y2(_y2),
	init(false),selectingType(NORMAL)
{
	for (int i = 0; i <ScaffoldTypeNum;i++) {
		selectableObj[i].SetPosition(x1+20, y1+20+i*70);
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
	DrawGraph(x, y, scaffoldGraph(type), true);
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
