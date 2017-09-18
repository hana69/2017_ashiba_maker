#pragma once
#include"Scaffold.h"

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
	void Init();
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
	void Init();
	void Update();

	bool DrawFinished() { return drawFinished; };
	NecessaryInfoToMake DrawnScaffold() { return writingObj; };
private:
	void Draw();
		void SetInfo();
	NecessaryInfoToMake writingObj;

	CScaffoldSelector selector;
	
	const int x1, x2, y1, y2;
	
	bool init;
	bool writing;
	bool drawFinished;
	
	CMouse Mouse;
};



//class CScaffoldMaker {
//public:
//	CScaffoldMaker();
//	void Init();
//	void UpDate();
//	NecessaryInfoToMake MakedScaffold() { return drawField.DrawnScaffold(); };
//	bool Maked() { return maked; };
//private:
//	void Make(NecessaryInfoToMake);
//	CDrawField drawField;
//	
//	
//	bool init;
//	bool maked;
//};

