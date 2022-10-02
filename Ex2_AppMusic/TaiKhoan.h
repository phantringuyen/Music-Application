#pragma once
#include "BaiHat.h"
#include "BaiHatBanQuyen.h"
#include "BaiHatPhoThong.h"

// tên bài hát, lời bài hát, tên ca sỹ, 
// thể loại nhạc, năm sáng tác và lượt nghe hiện tại
// trên trang nghe nhạc đó.

// bài hát: phổ thông và có bản quyền
class TaiKhoan
{
private:
	string tk;
	string pass; // Mật khẩu cần phải có ít nhất 8 ký tự và không được chứa ký tự khoảng cách
	bool vip;
	int time;
	float tien = 0;
	vector<BaiHatBanQuyen> ds_banQuyen;
	vector<BaiHatPhoThong> ds_phoThong;
public:
	TaiKhoan();
	void Nhap(bool&);
	void Xuat();
	void NapTien();
	void checkTien();
	void DanhSach();
	void themNhac();
	void xoaNhac();
	~TaiKhoan();
};