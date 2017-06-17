#pragma once
#include"General.h"
#include"mouse.h"

class CDrawField{
public:
	CDrawField(int _x1,int _y1,int _x2,int _y2);
	void Emerge();
	void SetRange(int _x1,int _y1,int _x2,int _y2);
private:
	void Draw();

	int x1,x2;
	int y1,y2;
	CMouse Mouse;
};

class CScaffold{
public:
	CScaffold( int _x1,int _y1,int _x2,int _y2);
	void Main();
	
private:
	void SelectField();
	
	void LoadScaffoldGraph();	
	
	void SetDrawFieldRange(int _x1,int _y1,int _x2,int _y2);

	std::string graphName[ScaffoldTypeNum];
	int scaffoldGraph[ScaffoldTypeNum];
	
	CDrawField DrawField;
};




