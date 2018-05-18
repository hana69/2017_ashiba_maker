#pragma once

class CActionField;
class CScaffoldMaker;

class Tutorial {
public:
	Tutorial();
	~Tutorial();
	void Start();
	void Update();
	bool Explaining(){return explaining;}
	enum class ExplainState{
		FIRST,
		ROAD_IS_BROKEN,
		LETS_CLICK,
		MP_DECREASE,
		SCROLL,
		DISCOVER_COIN,
		MP_GAIN,
		GO_TROUGH_SINLE_HOLE,
		HAVETO_JUMP,
		HAVETO_ERASER,
		GOAL
	} State() { return state; };
private:
	void StateFunc();
	bool drawFlag;
	void DrawBack();
	void Scroll();
	int scroll;

	CActionField* field;
	CScaffoldMaker* maker;
	int backGraph;

	ExplainState state;

	bool explaining;
	bool meMoveFlag;
	bool scrollFlag;

	static int graph[30];
};