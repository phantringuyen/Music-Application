#include "BaiHat.h"
BaiHat::BaiHat()
{
	tenBaiHat = '\0';
	tenCaSi = '\0';
	theLoai = '\0';
	namSangTac = '\0';
	luotNghe = 0;
	loiNhac = '\0';
}
BaiHat::~BaiHat() 
{
	tenBaiHat.clear();
	tenBaiHat = "\0";
	tenBaiHat.~basic_string();

	tenCaSi.clear();
	tenCaSi = "\0";
	tenCaSi.~basic_string();

	theLoai.clear();
	theLoai = "\0";
	theLoai.~basic_string();

	namSangTac.clear();
	namSangTac = "\0";
	namSangTac.~basic_string();

	luotNghe = 0;

	loiNhac.clear();
	loiNhac = "\0";
	loiNhac.~basic_string();
}