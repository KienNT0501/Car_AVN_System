#include "Sound.h"
Sound::Sound() : Setting()
{
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}
Sound::~Sound() {

}
//input thông tin sound setting
void Sound::nhapThongTin() {
	cout << "--SOUND SETTING--" << endl;
	cout << "Media level: ";
	set_media_level();
	cout << "Call level: ";
	set_call_level();
	cout << "Navi level: ";
	set_navi_level();
	cout << "Notification level: ";
	set_notification_level();

}
//xuất thông tin sound
void Sound::xuatThongTin() {
	cout << "--SOUND SETTING--" << endl;
	cout << left
		<< setw(15) << "Media level"
		<< setw(20) << "Call levell"
		<< setw(20) << "Navi level"
		<< setw(20) << "Notification level"
		<< endl;
	cout << setw(15) << media_level
		<< setw(20) << call_level
		<< setw(20) << navi_level
		<< setw(20) << notification_level
		<< endl;
}
//get media, call, nabigation, notification level
int Sound::get_media_level() {
	return media_level;
}

int Sound::get_call_level() {
	return call_level;
}

int Sound::get_navi_level() {
	return navi_level;
}

int Sound::get_notification_level() {
	return notification_level;
}

// set media level
void Sound::set_media_level() {
	cin >> media_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Media level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_media_level();
	}
	if (media_level < 1 || media_level > 5) {
		cout << "Media level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_media_level();
	}
}
//set media level từ file
void Sound::set_media_levelf(int media) {
	media_level = media;
}
void Sound::set_call_level() {
	cin >> call_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Call level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_call_level();
	}
	if (call_level < 1 || call_level > 5) {
		cout << "Call level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_call_level();
	}
}
// set call level từ file
void Sound::set_call_levelf(int call) {
	call_level = call;
}
// set navi level
void Sound::set_navi_level() {
	cin >> navi_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Navi level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_navi_level();
	}
	if (media_level < 1 || media_level > 5) {
		cout << "Navi level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_navi_level();
	}
}
//set navigation level từ file
void Sound::set_navi_levelf(int navi) {
	navi_level = navi;
}
// set notification level 
void Sound::set_notification_level() {
	cin >> notification_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Notification level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_media_level();
	}
	if (notification_level < 1 || notification_level > 5) {
		cout << "Notification level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_notification_level();
	}
}
//set notification từ file
void Sound::set_notification_levelf(int noti) {
	notification_level = noti;
}