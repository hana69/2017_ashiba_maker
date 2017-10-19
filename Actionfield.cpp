#include"ActionField.h"
#include<algorithm>

CActionField::CActionField() 
	:width(200),height( (WINDOW_HEIGHT-280) / 50 )
{
	int mapdata=LoadSoftImage("noseResource/mapdata.png");
	
	for (int i = 0; i < 500;i++) {
		limit[i] = 0;
	}
	int r, g, b, a;
	for (int i = 0; i < width;i++) {
		for (int j = 0; j < height;j++) {
			GetPixelSoftImage(mapdata,i,j,&r,&g,&b,&a);
			if (r == 255 && g == 0 && b == 0) {
				limit[i] = j;
			}
		}
	}

}
CActionField::~CActionField() {
	for (int i = 0; i < width; i++) {
		for (auto j : sc[i]) {
			delete j;
		}
	}
}

void CActionField::Update(int _scroll){
	if (!me.GameOver()) {
		me.SetV();
		Collision();
		Move();
		me.ResetV();
	}
	else {
		DrawBox(WINDOW_WIDTH/2-100,WINDOW_HEIGHT/2-70, WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT / 2 + 70,BLACK,true );
		DrawBox(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 70, WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT / 2 + 70, WHITE, false);
	}
	Draw(_scroll);
}

void CActionField::Make(NecessaryInfoToMake _info,int _scroll) {
	for (int i = max(DRAW_AREA_LEFT / 50+1 , _info.x1); i <= min(DRAW_AREA_RIGHT/50, _info.x2); i++) {
		int temp = 0;
		if (!sc[i + (_scroll / 50)].empty()) {
			temp = sc[i + (_scroll / 50)].back()->Y();
		}
		for (int j = max((DRAW_AREA_TOP + 1) / 50, _info.y1); j <= min((DRAW_AREA_TOP + 151) / 50 - 1, _info.y2); j++) {
			if (temp <= 9) {
				sc[i + (_scroll / 50)].push_back(new CScaffold(_info.type, i + (_scroll / 50), j));
				temp++;
			}
		}
	}
}

void CActionField::Collision() {
	if (me.X() % 50 == 0) {
		for (int i = 0; i < 2; i++) {
			if (!sc[me.X() / 50+i].empty()) {
				for (auto j : sc[me.X() / 50 + i]) {
					if (me.CollidedWith(j)) {
						//sc[me.X() / 50][0]->HitEffect();
						if (me.GameOver()) {
							break;
						}
					}
				}
			}
			if (me.GameOver()) {
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (!sc[me.X() / 50+i].empty()) {
				for (auto j : sc[me.X() / 50+i]) {
					if (me.CollidedWith(j)) {
						//sc[me.X() / 50 + i][0]->HitEffect();
					}
				}
			}
		}
	}
}
void CActionField::Draw(int _scroll) {
	me.Draw(_scroll);
	for (int i = 0; i < width; i++) {
		for (auto j : sc[i]) {
			j->Draw(_scroll);
		}
	}
}
void CActionField::Move() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < sc[i].size(); j++) {
			if (j == 0) {
				sc[i][j]->Move(limit[i]);
			}
			else {
				sc[i][j]->Move(sc[i][j - 1]->Y() + 1);
			}
		}
	}
	me.Move();
}