#include "BaiHatPhoThong.h"

BaiHatPhoThong::BaiHatPhoThong() {}
BaiHatPhoThong::~BaiHatPhoThong() {}
string BaiHatPhoThong::get_TenBaiHat() 
{
	return tenBaiHat; 
}
void BaiHatPhoThong::set_TenBaiHat(string song_name)
{
	tenBaiHat = song_name;
}

void BaiHatPhoThong::Nhap()
{
	int temp = 0;
	string _ten;
	do {
		cout << "Nhap ten bai hat: ";
		getline(cin, _ten);
		ifstream is;
		is.open("DanhSachBaiHat/NhacPhoThong/DanhSachNhac.txt");
		while (!is.eof()) {
			string t;
			getline(is, t);
			if (t == _ten) {
				temp = 1;
				break;
			}
		}
		is.close();
		if (temp == 0)
			cout << " => Bai hat khon ton tai!" << endl;
	} while (temp == 0);
	ifstream is;

	is.open("DanhSachBaiHat/NhacPhoThong/" + _ten + ".txt");
	string _loinhac, _gia;
	getline(is, tenBaiHat, '-');
	getline(is, tenCaSi, '-');
	getline(is, theLoai, '-');
	getline(is, namSangTac, '-');
	getline(is, _loinhac, '-');
	getline(is, _gia);
	loiNhac = "";
	while (!is.eof()) {
		string ss;
		getline(is, ss);
		loiNhac += ss;
		loiNhac += "\n";
	}
	luotNghe = atoi(_loinhac.c_str());
	is.close();
}

void BaiHatPhoThong::Xuat()
{
	cout << "\nBai hat: " << tenBaiHat;
	cout << "\nCa si: " << tenCaSi;
	cout << "\nThe loai: " << theLoai;
	cout << "\nNam sang tac: " << namSangTac;
	cout << "\nLuot nghe: " << luotNghe;
	cout << "\nLoi nhac: " << loiNhac;
}