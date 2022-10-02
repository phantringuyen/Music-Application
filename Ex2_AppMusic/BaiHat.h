#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class BaiHat
{
protected:
	string tenBaiHat;
	string tenCaSi;
	string theLoai;
	string namSangTac;
	int luotNghe;
	string loiNhac;

public:
	BaiHat();
	virtual string get_TenBaiHat() = 0;
	virtual void set_TenBaiHat(string) = 0;
	virtual void Nhap() = 0;
	virtual void Xuat() = 0;
	~BaiHat();
};