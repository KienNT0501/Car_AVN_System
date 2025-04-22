#pragma once
#include"Setting.h"
#include<regex>
#include<iomanip>
class Sound : public Setting {
public:
	Sound();
	~Sound();
	void nhapThongTin();
	void xuatThongTin();
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();
	void set_media_level();
	void set_media_levelf(int media);
	void set_call_level();
	void set_call_levelf(int call);
	void set_navi_level();
	void set_navi_levelf(int navi);
	void set_notification_level();
	void set_notification_levelf(int noti);
private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
	Setting souSet;
};