#include "General.h"
// hàm đi tới một hàng nào đó trong file
std::fstream& GotoLine(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}
//hàm set con trỏ (cursor position) tới tọa độ x, y trên màn hình console
void gotoxy(int x, int y)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdOut, coord);
}
General::General()
{
	timeZone = "N/A";
	language = "N/A";
}
General::~General() {
}
void General::gotoxy(int x, int y)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdOut, coord);
}
// hàm nhập thông tin cho lớp general gồm: timezone và language
void General::nhapThongTin() {
	system("cls");
	fstream timeZoneFile("timezones.txt", ios_base::in);
	fstream languageFile("languages.txt", ios_base::in);
	if (!languageFile || !timeZoneFile) {
		std::cerr << "Error: Unable to open file language.txt and file timezones.txt \n";
	}
	else {
		system("cls");
		cout << "--- SELECT TIME ZONE DATA ---";
		gotoxy(75, 0);
		cout << "--- SELECT LANGUAGE DATA---" << endl;
		if (timeZoneFile.is_open() && languageFile.is_open()) {
			string line1;
			string line2;
			for (int i = 1; i < 33;i++) {
				if (i < 30) {
					GotoLine(timeZoneFile, i);
					getline(timeZoneFile, line1);
					cout << i << ": " << line1;
					gotoxy(78, i);
					GotoLine(languageFile, i);
					getline(languageFile, line2);
					cout << i << ": " << line2 << endl;
				}
				if (i == 30) {
					GotoLine(timeZoneFile, i);
					getline(timeZoneFile, line1);
					cout << i << ": " << line1 << setw(22);
					GotoLine(languageFile, i);
					getline(languageFile, line2);
					cout << i << ": " << line2 << endl;
				}
				if (i > 30) {
					GotoLine(timeZoneFile, i);
					getline(timeZoneFile, line1);
					cout << i << ": " << line1 << endl;
				}
			}
			gotoxy(0, 34);
			cout << "YOUR SELECTION (timezone): ";
			set_timeZone();
			gotoxy(78, 30);
			cout << "YOUR SELECTION (language): ";
			set_language();
		}
	}
}
// xuất thông tin theo yêu cầu
void General::xuatThongTin() {
	cout << left << "General:" << "\t" << "Timezone" << "\t" << "Language" << endl
		<< "\t" << "\t" << setw(16) << timeZone << language << endl;
}

string General::get_language() {
	return language;
}

string General::get_timeZone() {
	return timeZone;
}
// set timezone từ bảng chọn và lưu chuỗi timezone tương ứng vào thuộc tính của lớp
void General::set_timeZone() {
	fstream timeZoneFile("timezones.txt", ios_base::in);
	int count = 0;
	string choice;
	getline(cin, choice);
	if (choice.empty()) {
		cout << "Error: Input cannot be empty!" << endl;
		return; // Handle error
	}
	regex ptnTimezone("^[1-9]||0[1-9]||[12][0-9]||3[0-2]$");
	while (regex_match(choice, ptnTimezone) == false) {
		count++;
		gotoxy(0, 34);
		cout << "Lua chon TIMEZONE khong hop le! Moi nhap lai " << count << " (01-32) : ";
		getline(cin, choice);
	};
	int c = stoi(choice);
	string trans;
	GotoLine(timeZoneFile, c);
	getline(timeZoneFile, trans);
	timeZone = "";
	for (char ch : trans) {
		if (ch == '/') {

			break;
		}
		timeZone += ch;
	}
}
void General::set_timeZonef(string time) {
	timeZone = time;
}
//set language từ bảng chọn và lưu chuỗi language tương ứng vào thuộc tính của lớp
void General::set_language() {
	fstream languageFile("languages.txt", ios_base::in);
	int count = 0;
	string choice;
	getline(cin, choice);
	if (choice.empty()) {
		cout << "Error: Input cannot be empty!" << endl;
		return; // Handle error
	}

	regex ptnLanguage("^(0[1-9]|[1-9]|[12][0-9]|30)$");
	while (regex_match(choice, ptnLanguage) == false) {
		count++;
		gotoxy(72, 30);
		cout << "Lua chon LANGUAGE khong hop le! Moi nhap lai " << count << " (01-30) : ";
		gotoxy(129, 30);
		getline(cin, choice);
	};
	int c = stoi(choice);
	GotoLine(languageFile, c);
	getline(languageFile, language);
}
void General::set_languagef(string lang) {
	language = lang;
}