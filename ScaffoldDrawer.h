#pragma once
#include"Scaffold.h"
#include"mouse.h"

///////�}�E�X�h���b�O���̑���`��Ɏg�p///////////
static int PlusMinus(int _x) {
	if (_x < 0) {
		return -1;
	}
	else if (_x == 0) {
		return 0;
	}
	else {
		return 1;
	}
};
///////////////////////////////////////////////
class CScaffoldSelector {
public:
	CScaffoldSelector(int _x1, int _y1, int _x2, int _y2);
	void Update();
	ScaffoldType SelectingType() { return selectingType; };

private:
	void Draw();

	int x1, y1, x2, y2;
	bool init;//�ŏ���false,Init�ďo����true
	ScaffoldType selectingType;

	class CSelectableObj {
	public:
		CSelectableObj();
		void SetType(ScaffoldType _type) { type = _type; };//�z��̃R���X�g���N�^���Ăяo���Ȃ��̂ŉ��}���u
		void Draw();
		void SetPosition(int, int);
		void Select(ScaffoldType*);
		ScaffoldType Type() { return type; };
	private:
		ScaffoldType type;
		int x, y;
		CMouse Mouse;
	}selectableObj[4];
};

class CScaffoldDrawer {
public:
	CScaffoldDrawer();
	void Update();

	bool DrawFinished() ;
	NecessaryInfoToMake DrawnScaffold() { return writingObj; };
private:
	void Draw();
		void SetInfo();
	NecessaryInfoToMake writingObj;

	CScaffoldSelector selector;
	
	const int x1, x2, y1, y2;
	
	bool writing;
	bool drawFinished;
	
	CMouse Mouse;
};
