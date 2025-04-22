#include "Setting.h"
Setting::Setting() :car_name("N/A"), personal_key("N/A"), email("N/A"), odo(100), service_remind(1000) {};
Setting::Setting(string name, string key, string emal, int udo, int servi) : car_name("N/A"), personal_key("N/A"), email("N/A"), odo(100), service_remind(1000) {};
Setting::~Setting() {}
//hàm set car name
void Setting::setCarName() {
	cout << "Owner name: ";
	getline(cin, car_name);
	validate(car_name, 1);
}
// hàm lấy dữ liệu carname từ file
void Setting::setCarNamef(string carname) {
	car_name = carname;
}
//hàm set email
void Setting::setEmail() {
	cout << "Email: ";
	getline(cin, email);
	validate(email, 2);
}
//hàm lấy dữ liệu email từ file
void Setting::setEmailf(string emailu) {
	email = emailu;
}
//hàm set keynumber
void Setting::setKeynumber() {
	cout << "Key number: ";
	getline(cin, personal_key);
	validate(personal_key, 3);
}
//hàm lấy dữ liệu key number từ file
void Setting::setKeynumberf(string key) {
	personal_key = key;
}
//hàm lấy dữ liệu tên chủ xe
string Setting::getCarName() {
	return car_name;
}
//hàm lấy email
string Setting::getEmail() {
	return email;
}
//hàm get personalkey
string Setting::getPersonalKey() {
	return personal_key;
}
//hàm get odo
int Setting::getODO() {
	return odo;
}
//hàm get service_remind
int Setting::getServiceRemind() {
	return service_remind;
}
//hàm validate name, email, và personalkey
void Setting::validate(string& str, int signal) {
	regex ptnName("[A-Za-z\\s]{1,25}");
	regex ptnEmail("([a-z0-9_]{3,}@[a-z]{3,8}[.][a-z]{3,})");
	regex ptnKey("[\\d]{8}");
	if (signal == 1) {
		while (regex_match(car_name, ptnName) == false) {
			cout << "Ten chu xe khong hop le! Moi nhap lai: ";
			getline(cin, car_name);
		};
	}
	if (signal == 2) {
		while (regex_match(email, ptnEmail) == false) {
			cout << "EMAIL khong hop le! Moi nhap lai: ";
			getline(cin, email);
		};
	}
	if (signal == 3) {
		while (regex_match(personal_key, ptnKey) == false) {
			cout << "Personal Key khong hop le! Moi nhap lai : ";
			getline(cin, personal_key);
		};
	}
	if (signal == 4) {
		for (int i = 0;i < str.size();i++) {
			if (str[i] < '0' || str[i]>'9') {
				cout << "ODO number chi duoc nhap vao so nguyen! Moi nhap lai : " << endl;
				cin >> odo;
				string odon = to_string(odo);
				validate(odon, 4);
			}
		}
	}

}
//hàm set odo
void Setting::setodo() {
	cout << "ODO number (km): ";
	cin >> odo;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "ODO number chi duoc nhap vao so nguyen! Moi nhap lai ! " << endl;
		setodo();
	}
}
//hàm lấy odo từ file
void Setting::setodof(int odou) {
	odo = odou;
}
//hàm set remind
void Setting::setremind() {
	cout << "Remind service (km): ";
	cin >> service_remind;
	if (!cin) {
		cin.clear(); cin.ignore(512, '\n');
		cout << "Remind service chi duoc nhap vao so nguyen! Moi nhap lai ! " << endl;
		setremind();
	}
}
//hàm lấy data remind_service từ file
void Setting::setremindf(int remind) {
	service_remind = remind;
}
//code nhập thông tin
void Setting::nhapThongTin() {
	cout << "- Car Info -" << endl;
	setCarName();
	setEmail();
	setKeynumber();
	setodo();
	setremind();
}
//code xuất thông tin
void Setting::xuatThongTin() {
	cout << "- Car Info -" << endl;
	cout << left
		<< setw(25) << "Owner Name"
		<< setw(25) << "Email"
		<< setw(25) << "Key Number"
		<< setw(25) << "ODO number(km)"
		<< setw(25) << "Remind service (km)"
		<< endl;

	cout << setw(25) << car_name
		<< setw(25) << email
		<< setw(25) << personal_key
		<< setw(25) << odo
		<< setw(0) << service_remind
		<< endl;
}