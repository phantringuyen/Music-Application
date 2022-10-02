#include "BaiHatBanQuyen.h"

BaiHatBanQuyen::BaiHatBanQuyen() 
{
	price = 0;
}
BaiHatBanQuyen::~BaiHatBanQuyen() 
{
	price = 0;
}

string BaiHatBanQuyen::get_TenBaiHat() 
{ 
	return tenBaiHat; 
}
void BaiHatBanQuyen::set_TenBaiHat(string song_name)
{ 
	tenBaiHat = song_name; 
}

void BaiHatBanQuyen::set_Price(float gia)
{
	price = gia;
}
float BaiHatBanQuyen::get_Price(string _price) {
	ifstream is;
	is.open("DanhSachBaiHat/NhacBanQuyen/" + _price + ".txt");
	string _loinhac, _gia;
	getline(is, tenBaiHat, '-');
	getline(is, tenCaSi, '-');
	getline(is, theLoai, '-');
	getline(is, namSangTac, '-');
	getline(is, _loinhac, '-');
	getline(is, _gia);
	is.close();
	return atoi(_gia.c_str());
}

void BaiHatBanQuyen::Nhap()
{
	int temp = 0;
	string _ten;
	do {
		cout << "Nhap ten bai hat: ";
		getline(cin, _ten);
		ifstream is;
		is.open("DanhSachBaiHat/NhacBanQuyen/DanhSachNhac.txt");
		while (!is.eof()) {
			string t;
			getline(is, t);
			if (t == _ten) 
			{
				temp = 1;
				break;
			}
		}
		is.close();
		if (temp == 0)
			cout << " => Bai hat khon ton tai!" << endl;
	} while (temp == 0);

	ifstream is;
	is.open("DanhSachBaiHat/NhacBanQuyen/" + _ten + ".txt");
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
	price = atoi(_gia.c_str());
	is.close();
}

void BaiHatBanQuyen::Xuat() {
	cout << "\n\t -- Bai Hat Ban Quyen --";
	cout << "\n - Bai hat: " << tenBaiHat;
	cout << "\n - Ca si: " << tenCaSi;
	cout << "\n - The loai: " << theLoai;
	cout << "\n - Nam sang tac: " << namSangTac;
	cout << "\n - Luot nghe: " << luotNghe;
	cout << "\n - Gia: " << price;
	cout << "\n - Loi nhac: " << loiNhac;
}