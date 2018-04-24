#pragma once
#include<vector>

class ClickObj;
class Menu                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
public:
	Menu(int _x,int _y);
	~Menu();
	void Update();
protected:
	std::vector<ClickObj*> texts;
	int x, y;
	int titleGraph;
};

class Pause :public Menu {
public:
	Pause();
	bool Selected();
	enum class Texts {
		RETURN_TO_START,
		RETURN_TO_TITLE,
		RESUME,
		MAX
	} SelectedText() { return selectedText; };
private:
	Texts selectedText;
};