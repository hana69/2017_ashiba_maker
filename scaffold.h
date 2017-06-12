#pragma once
#include"General.h"
#include"mouse.h"

class CScaffold{
public:
	CScaffold( int _x1,int _y1,int _x2,int _y2);
	void DrawField();
	
private:
	void SelectField();
	
	void LoadScaffoldGraph();	
	
	void SetDrawFieldRange(int _x1,int _y1,int _x2,int _y2);

	std::string graphName[ScaffoldTypeNum];
	int scaffoldGraph[ScaffoldTypeNum];

	CMouse Mouse;

};