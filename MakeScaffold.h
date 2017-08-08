#pragma once
#include"mouse.h"

class CDrawField {
public:
	CDrawField(int _x1, int _y1, int _x2, int _y2);
	void Update(int _selectingGraph);
private:
	void Draw(int _selectingGraph);
	int x1, x2, y1, y2;

	CMouse Mouse;
};

class CSelectField {
public:
	CSelectField(int _x1, int _y1, int _x2, int _y2);
	void Init(int[]);
	void Update();
	int SelectingGraph() {
		return selectingGraph;
	};
private:
	void Draw();
	int x1, y1, x2, y2;
	bool init;//ç≈èâÇÕfalse,InitåƒèoÇµå„true
	static int selectingGraph;
	class CSelectableObj {
	public:
		CSelectableObj();
		void Load(int);
		void Draw();
		void SetRange(int, int);
		void Select();
	private:
		int graph;
		int x, y;
		CMouse Mouse;
	}selectableObj[10];
};


class CMakeScaffold {
public:
	CMakeScaffold();
	void Init();
	void UpDate();
private:
	CDrawField drawField;
	CSelectField selectField;
	
	bool init;
	int scaffoldGraph[5];
};

