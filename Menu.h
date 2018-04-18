//#pragma once
//
//#include"mouse.h"
//#include"vector"
//
//enum MENU_RETURN{
//	NO_ACTION_MENU,
//	RESUME,
//	RETURN_TO_TITLE_MENU,
//	RETURN_TO_START_MENU,
//	MENU_STATE_NUM
//};
//
//class Menu_Interface {
//public:
//	Menu_Interface();
//	virtual void Update()=0;
//	struct Selected {
//		bool ReturnToStageStart();
//		bool ReturnToTitle();
//	};
//protected:
//	const int stateMax;
//	std::vector<CMouse> mouses;
//private:
//	const int x, y;
//};
//
//class Pause :public Menu_Interface {
//public:
//	void Update();
//	struct Selected {
//		bool Resume();
//		bool Close();
//	};
//};