#pragma once
#include"Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
using namespace std;
template<class T>
class List {
private:
	T elements_[100];
	int index = 0;
public:
	List();
	virtual ~List();
	void add(T& item, int count);
	T get(int& pos);
	int size(int count);
	void Sap_Xep(int i, int j);
	void override(T& setting, int i);
};
template <class T>
List<T>::List()
{
	for (int i = 0;i < 100;i++) {
		elements_[i] = T();
	}
}

template <typename T>
List<T>::~List()
{
}

template<class T>
void List<T>::add(T& item, int count)
{
	if (count < 99) {
		elements_[count] = item;
	}
	else {
		cout << "Ko the them du lieu, so luong qua cho phep!" << endl;
		system("pause");
	}
}

template<class T>
T List<T>::get(int& pos)
{
	for (int i = 0;i < pos;i++) {

		if (elements_[pos] == nullptr) {
			return nullptr;
		}

	}
	return elements_[pos];
}
template<class T>
void List<T>::override(T& setting, int i)
{
	elements_[i] = setting;
}

template<class T>
int List<T>::size(int count)
{
	return count;
}

template<class T>
void List<T>::Sap_Xep(int i, int j)
{

}
class MENU :public Setting {
private:
	// Kiểu dữ liệu List (class List) lưu trữ mảng kiểu setting, với List là kiểu dữ liệu là con trỏ kiểu setting
	List<Display*> display;
	List<Sound*> sound;
	List<General*> general;
	List<Setting*> listInfo;
	int dispCnt = 0;
	int soundCnt = 0;
	int generalCnt = 0;
	int settingCnt = 0;
	int check = 0;
	Setting* info = new Setting();
public:
	inline int MAX()const;
	void filesetting();
	void readSetting();
	void addSetting(Setting* setting);
	template<typename T1, typename T2, typename T3>
	void override(T1* info, T2* setting, List<T3>& listst, int i);
	template<typename T1, typename T2, typename T3>
	void checkInfo(T1* inf, T2* set, List<T3>& list, int& cnt);
	void MH1();
	void MH2();
	void MH3();
	void NhapThongTinCaiDat_Display();
	void NhapThongTinCaiDat_Sound();
	void NhapThongTinCaiDat_General();
	void XuatThongTinCaiDat_Display();
	void XuatThongTinCaiDat_General();
	void XuatThongTinCaiDat_Sound();
	void XuatThongTatCaTinCaiDat();
};