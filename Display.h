#pragma once
#include"Setting.h"
#include<regex>
#include<iomanip>
class Display : public Setting {

public:
	Display();
	~Display();
	void nhapThongTin();
	void xuatThongTin();
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();
	void set_light_level();
	void set_light_levelf(int lightlevel);
	void set_screen_light_level();
	void set_screen_light_levelf(int screenlight);
	void set_taplo_light_level();
	void set_taplo_light_levelf(int taplolight);
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};