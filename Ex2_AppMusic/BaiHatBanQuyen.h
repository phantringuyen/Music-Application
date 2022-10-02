#pragma once
#include "BaiHat.h"
class BaiHatBanQuyen : public BaiHat
{
	float price;
public:
	BaiHatBanQuyen();
	string get_TenBaiHat();
	void set_TenBaiHat(string);
	void Nhap();
	void Xuat();
	void set_Price(float);
	float get_Price(string);
	~BaiHatBanQuyen();
};