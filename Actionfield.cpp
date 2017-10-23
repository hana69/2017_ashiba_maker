#include"ActionField.h"
#include<algorithm>
#include"mouse.h"

CActionField::CActionField() 
	:width(200),height( (WINDOW_HEIGHT-280) / 50 ),
	 returnTitleFlag(false),coin(200)
{
	//配列の初期化
	for (int i = 0; i < 500; i++) {
		limit[i] = 0;
		for (int j = 0; j < 15; j++) {
			firstPut[i][j] = false;
		}
	}
	//

	//////マップ読み込み///////////////
	int limitdata = LoadSoftImage("noseResource/limitdata.png");
	int mapdata = LoadSoftImage("noseResource/mapdata.png");

	int r, g, b, a;
	for (int i = 0; i < width;i++) {
		for (int j = 0; j < height;j++) {
			GetPixelSoftImage( limitdata,i,j,&r,&g,&b,&a);
			if (r == 255 && g == 0 && b == 0) {
				limit[i] = j;
			}
			GetPixelSoftImage(mapdata, i, j, &r , &g , &b, &a);
			if (r == 128 && g == 128 && b == 128) {
				sc[i].push_back(new CScaffold(NORMAL,i,j) );
				firstSc[i][j] = *(sc[i].back());
				firstPut[i][j] = true;
			}
			else if (r == 255 && g == 255 && b == 0) {
				coin.Add(i, j);
			}
		}
	}
	////////////////////////////////////////
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
		me.ResetHit();
		Draw(_scroll);
	}
	else {
		Draw(_scroll);
	}
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

void CActionField::Restart() {
	me.Restart();
	for (int i = 0; i < width; i++) {
		for (auto j : sc[i]) {
			delete j;
		}
		sc[i].clear();
		for (int j = 0; j < 15;j++) {
			if (firstPut[i][j]) {
				sc[i].push_back(new CScaffold(firstSc[i][j].Type(), i, j));
			}
		}
	}
	returnTitleFlag = false;
}

void CActionField::Collision() {
	if (me.X() % 50 == 0) {
		for (int j = 0; j < 15;j++) {
			for (int i = 0; i < 2; i++) {
				if ( j < sc[me.X() / 50 + i].size()) {
					if (me.CollidedWith(sc[me.X() / 50 + i][j])) {
						//sc[me.X() / 50][0]->HitEffect();
						if (me.GameOver()) {
							break;
						}
					}
				}
			}
		}	
	}
	else {
		for (int j = 0; j < 15; j++) {
			for (int i = 0; i < 3; i++) {
				if (j < sc[me.X() / 50 + i].size()) {
					if (me.CollidedWith(sc[me.X() / 50 + i][j])) {
						//sc[me.X() / 50 + i][0]->HitEffect();
						if (me.GameOver()) {
							break;
						}
					}
				}
			}
		}
	}

	for (int i = (int)(me.X() / 50); i < me.X()/50 + 2; i++) {
		for (int j = (int)(me.Y() / 50); j < me.Y()/50 + 2; j++) {
			if (coin.Valid(i, j)) {
				coin.Delete(i, j);
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
	coin.Draw(_scroll);
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
