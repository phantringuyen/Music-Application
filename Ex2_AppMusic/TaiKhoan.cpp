#include "TaiKhoan.h"

TaiKhoan::TaiKhoan()
{
	tk = "";
	pass = ""; // Mật khẩu cần phải có ít nhất 8 ký tự và không được chứa ký tự khoảng cách
	vip = 1;
	time = 0;
	tien = 0;
}
TaiKhoan::~TaiKhoan()
{
	tk.clear();
	tk = "\0";
	tk.~basic_string();

	pass.clear();
	pass = "\0";
	pass.~basic_string();

	time = 0;
	tien = 0;
}

void TaiKhoan::Nhap(bool& t)
{
	string str[50][2];
	ifstream is;
	is.open("Account.txt");
	int i = 0;
	while (!is.eof()) {
		getline(is, str[i][0], '-');
		getline(is, str[i][1]);
		i++;
	}
	is.close();

	cout << "Choose: ";
	cout << "\n1.Dang nhap";
	cout << "\n2.Dang ki";
	cout << "\n3.Thoat";
	int causo;
	do
	{
		cout << "\n Choose: "; cin >> causo;
		if (causo > 3 || causo < 1)
			cout << " => Hay nhap lua chon hop le !\n";
	} while (causo > 3 || causo < 1);

	if (causo == 1) {
		cout << "Dang nhap\n";
		int check = 0;
		do {
			cout << " - Ten tai khoan: ";
			cin.ignore();
			getline(cin, tk);
			cout << " - Nhap mat khau: ";
			getline(cin, pass);
			for (int i = 0; i < 20; i++) {
				if (str[i][0] == tk && str[i][1] == pass)
					check = 1;
			}
			if (check == 0)
				cout << "\n => Tai khoang hoac mat khau khong dung!\n";
		} while (check == 0);

		cout << " => Dang nhap thanh cong!\n";
	}
	else if (causo == 2) {
		cout << "Dang ki:\n";
		cout << "\n1.Tai khoan thuong";
		cout << "\n2.Tai khoan vip";
		int causo1 = 0;
		do
		{
			cout << "\nNhap vao lua chon: "; cin >> causo1;
			if (causo1 < 1 || causo1 > 2)
				cout << " => Hay nhap lua chon hop le !\n";
		} while (causo1 < 1 || causo1 > 2);

		if (causo1 == 1) vip = 0;
		else if (causo1 == 2) vip = 1;

		bool tem = 0;
		do
		{
			cout << " - Ten tai khoan: ";
			cin.ignore();
			getline(cin, tk);
			for (int i = 0; i < 50; i++) {
				if (str[i][0] == tk) {
					tem = 1;
					break;
				}
			}
			if (tem == 0)
				break;
			else
				cout << "Tai khoan ton tai !\n";
		} while (tem != 0);

		do
		{
			cout << " - Nhap mat khau: ";
			getline(cin, pass);
			if (pass.length() < 8)
				cout << " => Password qua ngan ! Hay nhap lai mat khau manh hon !\n";
		} while (pass.length() < 8);

		if (vip == 1)
			cout << "Tien ban phai tra moi thang la (tai khoang Vip): " << 200000;

		cout << "\n\tDang ki thanh cong!\n";
		ofstream os;
		os.open("Account.txt");
		os << tk << "-" << pass << endl;
		os.close();
	}
	else if (causo == 3)
		t = !t;
}

void TaiKhoan::Xuat()
{
	if (ds_banQuyen.size() == 0 &&
		ds_phoThong.size() == 0)
		cout << " => Danh sach nhac cua ban khong co bai hat nao !\n";
	else
	{
		string _ten;
		int check_1 = 0, check_2 = 0;

		cout << "\nNhap ten bai hat can xuat thong tin: ";
		cin.ignore();
		getline(cin, _ten);
		for (auto& i : ds_banQuyen) {
			if (i.get_TenBaiHat() == _ten)
				check_1 = 1;
		}
		for (auto& i : ds_phoThong) {
			if (i.get_TenBaiHat() == _ten)
				check_2 = 1;
		}

		if (check_1 == 0 && check_2 == 0) {
			cout << "Bai hat khong ton tai!\n";
		}
		//else
		//{
		//	int o = 0;
		//	string ten, casi, theloai, nam, luotnghe, gia, lyric;
		//	if (check_1 > 0) // nhac ban quyen
		//	{
		//		ifstream is;
		//		is.open("DanhSachBaiHat/NhacBanQuyen/DanhSachNhac.txt");
		//		cout << "123a";
		//		while (!is.eof())
		//		{
		//			string t;
		//			cin.ignore();
		//			getline(is, t);
		//			if (t == _ten)
		//			{
		//				is.open("DanhSachBaiHat/NhacBanQuyen/" + _ten + ".txt");
		//				getline(is, ten, '-');
		//				getline(is, casi, '-');
		//				getline(is, theloai, '-');
		//				getline(is, nam, '-');
		//				getline(is, luotnghe, '-');
		//				getline(is, gia);
		//				getline(is, lyric);
		//			}
		//		}
		//		is.close();
		//	}
		//	else if (check_2 > 0) // nhac pho thong
		//	{
		//		ifstream is;
		//		is.open("DanhSachBaiHat/NhacPhoThong/DanhSachNhac.txt");
		//		while (!is.eof())
		//		{
		//			string t;
		//			getline(is, t);
		//			if (t == _ten)
		//			{
		//				is.open("DanhSachBaiHat/NhacPhoThong/" + _ten + ".txt");
		//				getline(is, ten, '-');
		//				getline(is, casi, '-');
		//				getline(is, theloai, '-');
		//				getline(is, nam, '-');
		//				getline(is, luotnghe, '-');
		//				getline(is, gia);
		//				cout << "321a";
		//				lyric = "";
		//				while (!is.eof()) {
		//					string c;
		//					getline(is, c);
		//					lyric += c;
		//					lyric += "\n";
		//				}
		//			}
		//		}
		//		is.close();
		//	}
		else {
			string ten, casi, theloai, nam, luotnghe, gia, lyric;
			ifstream is;
			is.open("DanhSachBaiHat/NhacBanQuyen/DanhSachNhac.txt");
			bool kt = 0;
			while (!is.eof()) {
				string ss;
				getline(is, ss);
				if (ss == _ten) {
					kt = 1;
					is.open("DanhSachBaiHat/NhacBanQuyen/" + _ten + ".txt");
					getline(is, ten, '-');
					getline(is, casi, '-');
					getline(is, theloai, '-');
					getline(is, nam, '-');
					getline(is, luotnghe, '-');
					getline(is, gia);
					getline(is, lyric);
				}
			}
			if (kt == 0) {
				ifstream ik;
				ik.open("DanhSachBaiHat/NhacPhoThong/DanhSachNhac.txt");

				while (!ik.eof())
				{
					string ss;
					getline(ik, ss);
					if (ss == _ten) {

						string temp = _ten + ".txt";
						ik.open("DanhSachBaiHat/NhacPhoThong/" + temp);
						getline(ik, ten, '-');
						getline(ik, casi, '-');
						getline(ik, theloai, '-');
						getline(ik, nam, '-');
						getline(ik, luotnghe, '-');
						getline(ik, gia, '\n');

						cout << ten;

						lyric = "";
						while (!ik.eof()) {

							string c;
							getline(ik, c);
							lyric += c;
							lyric += "\n";
						}
						cout << " abc123";

					}

				}
				ik.close();
			}
			cout << "\n - Ten bai hat: " << ten;
			cout << "\n - Ten ca si: " << casi;
			cout << "\n - The loai nhac: " << theloai;
			cout << "\n - Nam sang tac: " << nam;
			cout << "\n - Luot nghe: " << luotnghe;
			cout << "\n - Gia bai hat: " << gia;
			cout << "\n - Loi bai hat: \n" << lyric;
			is.close();


		}
	}
}

void TaiKhoan::NapTien()
{
	cout << "\tNAP TIEN\n";
	cout << "\t( Menh gia )";
	cout << "\n\t5000";
	cout << "\n\t10000";
	cout << "\n\t20000";
	cout << "\n\t50000";
	cout << "\n\t100000";
	cout << "\n\t200000";
	cout << "\n\t500000";
	float n = 0;
	do 
	{
		cout << "\nChon menh gia ban muon nap: "; cin >> n;
		if ((n != 20000 && n != 50000 && n != 100000 && n != 200000 && n != 500000))
			cout << " => Menh gia khong hop le!" << endl;
	} while ((n != 20000 && n != 50000 && n != 100000 && n != 200000 && n != 500000));
	tien += n;
	cout << " => Nap tien thanh cong !\n";
}

void TaiKhoan::checkTien()
{
	cout << " So tien con lai trong tai khoan quy khach la: " << tien << endl;
}

void TaiKhoan::DanhSach()
{
	cout << " Danh sach bai hat cua ban: \n";
	if (ds_banQuyen.size() == 0 && ds_phoThong.size() == 0)
		cout << " => Danh sach cua ban khong co bai hat nao !\n";
	else {
		for (auto& i : ds_banQuyen) {
			cout << i.get_TenBaiHat();
			cout << endl;
		}
		for (auto& i : ds_phoThong) {
			cout << i.get_TenBaiHat();
			cout << endl;
		}
	}
}

void TaiKhoan::themNhac()
{
	cout << "\n -- Nhac pho thong --\n";
	ifstream is;
	is.open("DanhSachBaiHat/NhacPhoThong/DanhSachNhac.txt");
	while (!is.eof()) {
		string _ten;
		getline(is, _ten);
		cout << "  " << _ten << endl;
	}
	is.close();

	cout << "\n -- Nhac ban quyen --\n";
	ifstream os;
	os.open("DanhSachBaiHat/NhacBanQuyen/DanhSachNhac.txt");
	while (!os.eof()) {
		string _ten;
		getline(os, _ten);
		cout << " " << _ten << endl;
	}
	os.close();

	cout << "\n -- THEM NHAC --\n";
	cout << "\n 1.Nhac Pho Thong";
	cout << "\n 2.Nhac Ban Quyen";
	int causo2;
	cout << "\n - Nhap vao lua chon: "; cin >> causo2;
	if (causo2 == 1)
	{
		int temp = 0;
		BaiHatPhoThong song_phoThong;
		string _ten;
		ifstream is;
		cin.ignore();
		do {
			cout << "Nhap ten bai hat: ";
			getline(cin, _ten);
			is.open("DanhSachBaiHat/NhacPhoThong/DanhSachNhac.txt");
			while (!is.eof()) {
				string t;
				getline(is, t);
				if (t == _ten) {
					temp = 1;
					break;
				}
			}
			if (temp == 0)
				cout << "Bai hat khong ton tai!\n";
		} while (temp == 0);

		song_phoThong.set_TenBaiHat(_ten);
		ds_phoThong.push_back(song_phoThong);
		cout << " => Them bai " << _ten << " vao danh sach thanh cong!\n";
		is.close();
	}
	else if (causo2 == 2)
	{
		int temp = 0;
		BaiHatBanQuyen song_banQuyen;
		string _ten;
		ifstream is;
		do {
			cout << " - Nhap ten bai hat: ";
			cin.ignore();
			getline(cin, _ten);
			is.open("DanhSachBaiHat/NhacBanQuyen/DanhSachNhac.txt");
			while (!is.eof())
			{
				string t;
				getline(is, t);
				if (t == _ten)
				{
					temp = 1;
					break;
				}
				if (temp == 0)
					cout << "Bai hat khong ton tai!\n";
			}
		} while (temp == 0);

		// trả tiền mua bài hát
		song_banQuyen.set_TenBaiHat(_ten);
		float giaTien = 0.0;
		if (vip == true)
		{
			cout << "Gia phai tra (giam 50% gia tien khi tai khoan vip): " << 0.5 * song_banQuyen.get_Price(_ten);
			giaTien = (float)0.5 * song_banQuyen.get_Price(_ten);
		}
		else
		{
			cout << "Gia phai tra: " << song_banQuyen.get_Price(_ten);
			giaTien = song_banQuyen.get_Price(_ten);
		}

		if (tien >= giaTien)
		{
			cout << "\n => Mua thanh cong!\n";
			tien -= giaTien;
			ds_banQuyen.push_back(song_banQuyen);
			cout << " => Them bai " << _ten << " vao danh sach thanh cong!\n";
		}
		else cout << "\n => Tai khoan quy khach khong du ! Vui long nap them\n";
		is.close();
	}
}

void TaiKhoan::xoaNhac()
{
	if (ds_phoThong.size() == 0 && ds_banQuyen.size() == 0)
		cout << "\n => PlayList cua ban khong co bai hat nao!\n";
	else
	{
		string _ten;
		cin.ignore();
		cout << "Nhap ten bai hat can xoa khoi PlayList: ";
		getline(cin, _ten);
		int j = 0;
		bool temp = false;
		for (auto& i : ds_phoThong)
		{
			if (i.get_TenBaiHat() == _ten) {
				temp = true;
				ds_phoThong.erase(ds_phoThong.begin() + j);
			}
			j++;
		}

		int k = 0;
		for (auto& i : ds_banQuyen) {
			if (i.get_TenBaiHat() == _ten) {
				temp = true;
				ds_banQuyen.erase(ds_banQuyen.begin() + k);
			}
			k++;
		}
		if (temp == false)
			cout << " => Bai hat khong ton tai !\n";
		else
			cout << " => Bai hat da duoc xoa thanh cong !\n";
	}
}