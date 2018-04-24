#include"ActionField.h"
#include<algorithm>
#include"mouse.h"
#include"coin.h"
#include"Me.h"
#include"Menu.h"

int CActionField::limitdata[10] = {};
int CActionField::mapdata[10] = {};
CActionField::CActionField(int _stageNum) 
	:width(200),height( (WINDOW_HEIGHT-280) / 50 ),
	 returnTitleFlag(false),menuOpening(false),
	coinGotFlag(false),
	coin(new CCoin(width)),me(new CMe()),pauseMenu(new Pause())
{
	//配列の初期化
	for (int i = 0; i < 500; i++) {
		limit[i] = 0;
		for (int j = 0; j < 15; j++) {
			firstPut[i][j] = false;
		}
	}
	//
	pauseFuncs[(unsigned)Pause::Texts::RETURN_TO_START] = &CActionField::ReturnToStart;
	pauseFuncs[(unsigned)Pause::Texts::RETURN_TO_TITLE] = &CActionField::ReturnToTitle;
	pauseFuncs[(unsigned)Pause::Texts::RESUME] = &CActionField::Resume;


	//////マップ読み込み///////////////
	if (limitdata[_stageNum] == 0) {
		std::string s = "noseResource/limitdata"; 
		s += std::to_string(_stageNum);
		s += ".png";
		limitdata[_stageNum] = LoadSoftImage(s.c_str());
	}
	if (mapdata[_stageNum] == 0) {
		std::string s = "noseResource/mapdata";
		s += std::to_string(_stageNum);
		s += ".png";
		mapdata[_stageNum] = LoadSoftImage(s.c_str());
	}
	//////////////////////////////////////

	int r, g, b, a;
	for (int i = 0; i < width;i++) {
		for (int j = 0; j < height;j++) {
			GetPixelSoftImage( limitdata[_stageNum],i,j,&r,&g,&b,&a);
			if (r == 255 && g == 0 && b == 0) {
				limit[i] = j;
			}
			GetPixelSoftImage(mapdata[_stageNum], i, j, &r , &g , &b, &a);
			if (r == 128 && g == 128 && b == 128) {
				sc[i].push_back(new CScaffold(ScaffoldType::NORMAL,i,j) );
				firstSc[i][j] = new CScaffold(ScaffoldType::NORMAL, i, j);
				firstPut[i][j] = true;
			}
			else if (r == 255 && g == 128 && b == 0) {
				coin->Add(i, j);
			}
			else if (r == 255 && g == 0 && b == 255) {
				sc[i].push_back(new CScaffold(ScaffoldType::GOAL, i, j));
				firstSc[i][j] = new CScaffold(ScaffoldType::GOAL, i, j);
				firstPut[i][j] = true;
			}
			else if (r == 255 && g == 0 && b == 0) {
				sc[i].push_back(new CScaffold(ScaffoldType::JUMP, i, j));
				firstSc[i][j] = new CScaffold(ScaffoldType::JUMP, i, j);
				firstPut[i][j] = true;
			}
			else if (r == 255 && g == 255 && b == 0) {
				sc[i].push_back(new CScaffold(ScaffoldType::SPEED_UP, i, j));
				firstSc[i][j] = new CScaffold(ScaffoldType::SPEED_UP, i, j);
				firstPut[i][j] = true;
			}
			else if (r == 0 && g == 0 && b == 255) {
				sc[i].push_back(new CScaffold(ScaffoldType::SPEED_DOWN, i, j));
				firstSc[i][j] = new CScaffold(ScaffoldType::SPEED_DOWN, i, j);
				firstPut[i][j] = true;
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
	for (int i = 0; i < width;i++) {
		for (auto j : firstSc[i]) {
			delete j;
		}
	}
	delete me;
	delete coin;
	delete pauseMenu;
}

void CActionField::Update(int _scroll){
	coinGotFlag = false;
	static CMouse mouse(WINDOW_WIDTH - (20 * 2 + 50) + 6, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, WINDOW_WIDTH - (20 * 2 + 50) + 83, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 25);
	if ( !me->GameOver() && !me->GameClear() ){
		if (!menuOpening) {
			me->SetV();
			Collision();//ここでcoinGotFlagがtrueになるかも
			Move();
			me->ResetV();
			me->ResetHit();
		}
		Draw(_scroll);
		DrawBox(WINDOW_WIDTH - (20 * 2 + 50) + 6, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, WINDOW_WIDTH - (20 * 2 + 50) + 83, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 25, ORANGE, true);
		DrawBox(WINDOW_WIDTH - (20 * 2 + 50) + 6, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, WINDOW_WIDTH - (20 * 2 + 50) + 83, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 25, WHITE, false);
		if (mouse.Insided()) {
			static int menuGraph = LoadGraph("noseResource/menuBottunPoint.png");
			DrawGraph(WINDOW_WIDTH - (20 * 2 + 50) + 6, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, menuGraph, true);
			if (mouse.LeftPushed()) {
				menuOpening = true;
			}
		}
		else {
			static int menuGraph = LoadGraph("noseResource/menuBottun.png");
			DrawGraph(WINDOW_WIDTH - (20 * 2 + 50) + 10, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, menuGraph, true);
		}
		if (menuOpening) {
			pauseMenu->Update();
			if (pauseMenu->Selected()) {
				(this->*pauseFuncs[(unsigned)pauseMenu->SelectedText()])();
			}
		}
	}
	else {
		Draw(_scroll);
	}
}

void CActionField::OnlyDraw(int _scroll) {
	DrawBox(WINDOW_WIDTH - (20 * 2 + 50) + 6, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, WINDOW_WIDTH - (20 * 2 + 50) + 83, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 25, ORANGE, true);
	DrawBox(WINDOW_WIDTH - (20 * 2 + 50) + 6, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, WINDOW_WIDTH - (20 * 2 + 50) + 83, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 25, WHITE, false);
	DrawLimit(_scroll);
	me->Draw(_scroll);
	for (int i = 0; i < width; i++) {
		for (auto j : sc[i]) {
			j->Draw(_scroll);
		}
	}
	coin->Draw(_scroll);
	static int menuGraph = LoadGraph("noseResource/menuBottun.png");
	DrawGraph(WINDOW_WIDTH - (20 * 2 + 50) + 10, WINDOW_HEIGHT - (50 * 4 + 20 * 5) - 47, menuGraph, true);

}

void CActionField::Make(int _x,int _y,ScaffoldType _type,int _scroll) {
	/*for (int i = max(DRAW_AREA_LEFT / 50+1 , _info.x1); i <= min(DRAW_AREA_RIGHT/50, _info.x2); i++) {
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
	}*/
	if (sc[_x / 50 + (_scroll / 50)].size() <= 9) {
		sc[_x / 50 + (_scroll / 50)].push_back(new CScaffold(_type, _x / 50 + (_scroll / 50), _y / 50));
	}
}

void CActionField::Restart() {
	me->Restart();
	for (int i = 0; i < width; i++) {
		for (auto j : sc[i]) {
			delete j;
		}
		sc[i].clear();
		for (int j = 0; j < 15;j++) {
			if (firstPut[i][j]) {
				sc[i].push_back(new CScaffold(firstSc[i][j]->Type(), i, j));
			}
		}
	}
	menuOpening = false;
	coin->Reset();
	returnTitleFlag = false;
}

bool CActionField::GameOvered() { return me->GameOver(); };
bool CActionField::GameCleared() { return me->GameClear(); };

void CActionField::Collision() {
	if (me->X() % 50 == 0) {
		for (int j = 0; j < 15;j++) {
			for (int i = 0; i < 2; i++) {
				if ( j < sc[me->X() / 50 + i].size()) {
					if (me->CollidedWith(sc[me->X() / 50 + i][j])) {
						//sc[me->X() / 50][0]->HitEffect();
						if (me->GameOver()) {
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
				if (j < sc[me->X() / 50 + i].size()) {
					if (me->CollidedWith(sc[me->X() / 50 + i][j])) {
						//sc[me->X() / 50 + i][0]->HitEffect();
						if (me->GameOver()) {
							break;
						}
					}
				}
			}
		}
	}

	for (int i = (int)(me->X() / 50); i < me->X()/50 + 2; i++) {
		for (int j = (int)(me->Y() / 50); j < me->Y()/50 + 2; j++) {
			if (coin->Valid(i, j)) {
				coin->Delete(i, j);
				coinGotFlag = true;
			}
		}
	}
}
void CActionField::Draw(int _scroll) {
	DrawLimit(_scroll);
	me->Draw(_scroll);
	for (int i = 0; i < width; i++) {	
		for (auto j : sc[i]) {
			j->Draw(_scroll);
		}
	}
	coin->Draw(_scroll);
}
	void CActionField::DrawLimit(int _scroll) {
		static int limitGraph = LoadGraph("noseResource/limit.png");
		
		for (int i = 0; i < width; i++) {
			if (0 < i*50+50-_scroll && i*50-_scroll < WINDOW_WIDTH) {
				DrawGraph(i*50-_scroll,limit[i]*50-5,limitGraph,true);
				//DrawFormatString(0,i*15,YELLOW,"%d",limit[i]);
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
	me->Move();
}


int CActionField::MeX() { return me->X(); };

void CActionField::ReturnToTitle() {
	returnTitleFlag = true;
}
void CActionField::ReturnToStart() {
	Restart();
}
void CActionField::Resume() {
	menuOpening = false;
}
