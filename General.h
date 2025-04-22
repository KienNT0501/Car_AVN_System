#pragma once
#include"Setting.h"
#define NOMINMAX
#include<windows.h>
#include<memory>
#include<iomanip>
#include<regex>
#include<fstream>
#include<limits>
class General : public Setting {
public:
	General();
	~General();
	void nhapThongTin();
	void xuatThongTin();
	string get_language();
	string get_timeZone();
	void set_timeZone();
	void set_timeZonef(string time);
	void set_language();
	void set_languagef(string lang);
	void gotoxy(int x, int y);
private:
	string timeZone;
	string language;
	Setting genSet;
};