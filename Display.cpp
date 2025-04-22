#include"Display.h"


Display::Display() : Setting()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display() {
}
//hàm get light level, screen, taplo
int Display::get_light_level() {
	return light_level;
}

int Display::get_screen_light_level() {
	return screen_light_level;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}
//hàm set light level, screen taplo
void Display::set_light_level() {
	cin >> light_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Light level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_light_level();
	}
	if (light_level < 1 || light_level > 5) {
		cout << "Light level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_light_level();
	}
}
void Display::set_light_levelf(int lightlevel) {
	light_level = lightlevel;
}

void Display::set_screen_light_level() {
	cin >> screen_light_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Screen light level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_screen_light_level();
	}
	if (screen_light_level < 1 || screen_light_level > 5) {
		cout << "Screen light level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_screen_light_level();
	}
}
void Display::set_screen_light_levelf(int screenlight) {
	screen_light_level = screenlight;
}
void Display::set_taplo_light_level() {
	cin >> taplo_light_level;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Taplo light level chi duoc nhap vao so nguyen (1~5) ! Moi nhap lai : ";
		set_taplo_light_level();
	}
	if (screen_light_level < 1 || screen_light_level > 5) {
		cout << "Taplo light level chi duoc nhap trong khoang (1~5) ! Moi nhap lai : ";
		set_taplo_light_level();
	}
}
void Display::set_taplo_light_levelf(int taplolight) {
	taplo_light_level = taplolight;
}
//Menu nhập thông tin display
void Display::nhapThongTin() {
	cout << "--DISPLAY SETTING--" << endl;
	cout << "Light level: ";
	set_light_level();
	cout << "Screen light level: ";
	set_screen_light_level();
	cout << "Taplo light level: ";
	set_taplo_light_level();
}
// Giao diện xuất thông tin
void Display::xuatThongTin() {
	cout << "--DISPLAY SETTING--" << endl;
	cout << left
		<< setw(15) << "Light level"
		<< setw(20) << "Screen light level"
		<< setw(20) << "Taplo light level"
		<< endl;
	cout << setw(15) << get_light_level()
		<< setw(20) << get_screen_light_level()
		<< setw(20) << get_taplo_light_level()
		<< endl;
}