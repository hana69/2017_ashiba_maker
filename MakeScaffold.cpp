#include"MakeScaffold.h"
CMakeScaffold::CMakeScaffold()
	:drawField(20, WINDOW_HEIGHT - 280, WINDOW_WIDTH - (20 * 2 + 50), WINDOW_HEIGHT - 20),
	selectField(WINDOW_WIDTH - (20 * 2 + 50), WINDOW_HEIGHT - (50 * 4 + 20 * 5), WINDOW_WIDTH, WINDOW_HEIGHT),
	init(false)
{}

void CMakeScaffold::Init() {
	for (int i = 0; i < 4; i++) {
		std::string s = "noseResource/scaffold" + std::to_string(i + 1) + ".png";
		scaffoldGraph[i] = LoadGraph(s.c_str());
	}
	selectField.Init(scaffoldGraph);
}

void CMakeScaffold::UpDate() {
	if (!init) {
		Init();
		init = true;
	}
	drawField.Update(selectField.SelectingGraph());
	selectField.Update();
}

///////////////////////////CDrawField////////////////////////////////////

/////////////コンストラクタ///////////////////

CDrawField::CDrawField(int _x1, int _y1, int _x2, int _y2)
	:x1(_x1),x2(_x2),y1(_y1),y2(_y2),
	 Mouse(_x1,_y1,_x2,_y2)
{}
/////////////public関数//////////////////////
void CDrawField::Update(int _selectingGraph) {
	Draw(_selectingGraph);
}

////////////private関数//////////////////////

void CDrawField::Draw(int _selectingGraph) {
	DrawBox(x1, y1, x2, y2, WHITE, false);

	if (Mouse.Insided()) {
		Mouse.SetTemp();
	}
	if (Mouse.LeftPushing()) {
		if (Mouse.ChangeX() > 0) {
			if (Mouse.ChangeY() > 0) {
				for (int i = Mouse.TempX(); i < Mouse.TempX() + Mouse.ChangeX() - 50; i += 50) {
					for (int j = Mouse.TempY(); j < Mouse.TempY() + Mouse.ChangeY() - 50; j += 50) {
						DrawGraph( i , j , _selectingGraph , true );
					}
				}
			}
			else if (Mouse.ChangeY() < 0) {
				for (int i = Mouse.TempX(); i < Mouse.TempX() + Mouse.ChangeX() - 50; i += 50) {
					for (int j = Mouse.TempY(); j > Mouse.TempY() + Mouse.ChangeY() + 50; j -= 50) {
						DrawGraph(i, j, _selectingGraph, true);
					}
				}
			}
		}
		else if (Mouse.ChangeX() < 0) {
			if (Mouse.ChangeY() > 0) {
				for (int i = Mouse.TempX(); i > Mouse.TempX() + Mouse.ChangeX() + 50; i -= 50) {
					for (int j = Mouse.TempY(); j < Mouse.TempY() + Mouse.ChangeY() - 50; j += 50) {
						DrawGraph(i, j, _selectingGraph, true);
					}
				}
			}
			else if (Mouse.ChangeY() < 0) {
				for (int i = Mouse.TempX(); i > Mouse.TempX() + Mouse.ChangeX() + 50; i -= 50) {
					for (int j = Mouse.TempY(); j > Mouse.TempY() + Mouse.ChangeY() + 50; j -= 50) {
						DrawGraph(i, j, _selectingGraph, true);
					}
				}
			}
		}

	}
}

///////////////////////////CSelectField////////////////////////////////////

int CSelectField::selectingGraph = 0;
CSelectField::CSelectField(int _x1, int _y1, int _x2, int _y2)
	:x1(_x1), x2(_x2), y1(_y1), y2(_y2),
	init(false)
{
	for (int i = 0; i <4 ;i++) {
		selectableObj[i].SetRange(x1+20, y1+20+i*70);
	}
}

void CSelectField::Init(int _graph[]) {
	for (int i = 0; i < 4; i++) {
		selectableObj[i].Load(_graph[i]);
	}
	selectingGraph = _graph[0];
}
void CSelectField::Update() {
	Draw();
	for (auto i:selectableObj) {
		i.Select();
	}
}

void CSelectField::Draw() {
	for (int i = 0; i < 4; i++) {
		selectableObj[i].Draw();
	}
}

CSelectField::CSelectableObj::CSelectableObj()
	:graph(0),
	x(0),y(0)
{}

void CSelectField::CSelectableObj::Load(int _graph) {
	if (graph==0) {
		graph = _graph;
	}
}

void CSelectField::CSelectableObj::Draw() {
	DrawGraph(x, y, graph, true);
	if (Mouse.Insided()) {
		DrawBox(x, y, x + 50, y + 50, YELLOW, false);
	}
}

void CSelectField::CSelectableObj::SetRange(int _x,int _y) {
	x = _x;
	y = _y;
	Mouse.SetRange(_x, _y, _x + 50, _y + 50);
}
void CSelectField::CSelectableObj::Select() {
	if (Mouse.Insided() && Mouse.LeftReleased()) {
		selectingGraph = graph;
	}
}
