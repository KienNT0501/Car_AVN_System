#include <iostream>
#include "Menu.h"
#include"Setting.h"
#include"Display.h"
#include"Sound.h"
#include"General.h"
#include <fstream>
int main() {
	MENU m1;
	m1.readSetting();
	m1.MH1();
}