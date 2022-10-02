#pragma once
#include "BaiHat.h"

class BaiHatPhoThong :public BaiHat
{
public:
	BaiHatPhoThong();
	~BaiHatPhoThong();
	string get_TenBaiHat();
	void set_TenBaiHat(string);
	void Nhap();
	void Xuat();
};

