#include"ActionField.h"

CActionField::CActionField() 
	:width(200),height( (WINDOW_HEIGHT-280) / 50 )
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			sc[i][j] = nullptr;
		}
	}
}
CActionField::~CActionField() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			delete sc[i][j];
		}
	}
}
void CActionField::Update(){
	for (int i = 0; i < width;i++) {
		for (int j = 0; j < height; j++) {
			if (sc[i][j] != nullptr) {
				sc[i][j]->Draw();
			}
		}
	}
}

void CActionField::Make(NecessaryInfoToMake _info) {
	for (int i = _info.x; i < _info.width; i++) {
		for (int j = 0; j < _info.height; j++) {
			switch (_info.type) {
			case NORMAL:
				sc[i][j] = new CNormal();
				break;
			case SPEED_UP:
				sc[i][j] = new CSpeedUp();
				break;
			case SPEED_DOWN:
				sc[i][j] = new CSpeedDown();
				break;
			case JUMP:
				sc[i][j] = new CJump();
				break;
			}
		}
	}
}