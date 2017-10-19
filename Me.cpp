#include "Me.h"
#include"key.h"

CMe::CMe() 
	:x(0),y(0),
	vx(0),vy(0),
	gameOver(false),
	graph(LoadGraph("noseResource/me.png"))
{}
void CMe::SetV() {
	vx = 1;
	vy += 0.3;
}

void CMe::Move()
{
	/*if (vx>=50) {
		vx = 0;
		x ++;
	}*/
	x += vx;
	y += vy;
	if (y>550) {
		gameOver = true;
	}
}

void CMe::ResetV() {
	vx = 0;
	//vy = 0;
}

void CMe::Draw(int _scroll)
{
	//DrawGraph(x,y,graph,true);
	//DrawBox(x*50-_scroll,y*50,x*50+50-_scroll,y*50+50,RED,true);
	DrawBox(x - _scroll,y,x+50-_scroll,y+50,RED,true);
}

bool CMe::CollidedWith(CScaffold* _sc) {
	if (_sc->Y() * 50 < y + 50 && _sc->Y() * 50 + 50 > y) {
		if (x+50 <= _sc->X() * 50 && x + vx+50 >= _sc->X() * 50) {
			vx = 0;
			x = _sc->X() * 50-50;
			return true;
		}
	}

	if (_sc->X() * 50 <= x + 50 && _sc->X() * 50 + 50 >= x) {
		if (_sc->Y() * 50 < y + 50 + vy && _sc->Y() * 50 + 50 > y + vy) {
			if (y > _sc->Y()*50) {
				gameOver = true;
				return true;
			}
			y = _sc->Y() * 50 - 50;
			vy = 0;
			HitEffect(_sc->Type());
			return true;
		}
	}
	
	return false;
}

void CMe::HitEffect(ScaffoldType _type) {
	switch (_type) {
	case JUMP:
		vy -= 10;
		break;
	case SPEED_UP:
		vx = 3;
		break;
	case SPEED_DOWN:
		vx = 0.5;
		break;
	}
}