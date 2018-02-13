#pragma once
class CTutorial {
public:
	CTutorial();
	void Start();
	void Update(int _scroll,int _x);
	bool Explaining(){return explaining;}
	int State() { return state; };
	void DrawEndEffect();
private:
	void Draw(int _scroll);
	void ExplainingNext(int _scroll);
	void UnExplainingNext(int _scroll,int _x);
	int state;
	bool explaining;
	static int graph[30];
};