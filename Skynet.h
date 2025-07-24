#include "a.h"
#pragma once
using namespace std;
class Skynet {
public:
	Skynet() {
		cout << "默认使用在地球轨道上的卫星" << endl;
		getType();
		getName();
		getNumber();
	}
	void getName() {
		cout << "请输入要操作的天网卫星的临时名称:";
		string s;
		cin >> s;
		name = s;
	}
	void getNumber() {
		cout << "输入临时编号:";
		string s;
		cin >> s;
		number = s;
	}
	void getType() {
		cout << "输入类型:";
		string s;
		cin >> s;
		if (s != "A00" || s != "A01" || s != "B00" || s != "B01") {
			cout << "不存在的类型" << endl;
		}
		else {
			type = s;
		}
	}
	void getPlace() {
		cout << "输入需要跃迁的位置:" << endl;
		string s;
		cin >> s;
		if (type == "A00" || type == "A01" || type == "B00" || type == "B01") {
			if (s == "A" || s == "B") {
				place = s;
			}
			else {
				cout << "无法跃迁" << endl;
			}
		}
		else if (type == "C00") {
			if (s == "A" || s == "B" || s == "C") {
				place = s;
			}
			else {
				cout << "无法跃迁" << endl;
			}
		}
	}
	void _goto() {
		string s;
		cin >> s;
		if (type == "C00") {
			if (s == "A" || s == "B" || s == "C") {
				place = s;
			}
		}
	}
	
private:
	string name, type, number, now, place;
};