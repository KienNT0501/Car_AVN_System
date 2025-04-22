#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<iomanip>
using namespace std;
class Setting {
public:
	Setting();
	explicit Setting(string name, string key, string emal, int udo, int servi);
	virtual ~Setting();
	void nhapThongTin();
	void xuatThongTin();
	void validate(string& name, int signal);
	void setodo();
	void setremind();
public:
	void setCarName();
	void setCarNamef(string carname);
	void setEmail();
	void setEmailf(string email);
	void setKeynumber();
	void setKeynumberf(string key);
	void setodof(int odou);
	void setremindf(int remind);
	string getCarName();
	string getEmail();
	string getPersonalKey();
	int getODO();
	int getServiceRemind();

private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;

};