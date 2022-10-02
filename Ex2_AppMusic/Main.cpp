#include "BaiHat.h"
#include "BaiHatBanQuyen.h"
#include "BaiHatPhoThong.h"
#include "TaiKhoan.h"
int main()
{
	cout << "\n\n   -- ACCOUNT --\n";
	TaiKhoan acc;
	bool out = 1;
	while (out) {
		acc.Nhap(out);
		while (out) {
			cout << "\n1.Nap tien";
			cout << "\n2.Kiem tra tai khoan";
			cout << "\n3.Them nhac vao danh sach";
			cout << "\n4.Xem danh sach nhac cua ban";
			cout << "\n5.Xuat thong tin bai hat trong danh sach";
			cout << "\n6.Xoa nhac khoi danh sach";
			cout << "\n7.Dang Xuat";
			cout << "\n0.Thoat";
			int choose;
			do
			{
				cout << "\nNhap vao lua chon: "; cin >> choose;
				if (choose > 7 || choose < 0)
					cout << " => nhap lai lua chon hop le !\n";
			} while (choose > 7 || choose < 0);
			
			if (choose == 1) {
				acc.NapTien();
				system("pause");
				system("cls");
			}

			else if (choose == 2) {
				acc.checkTien();
				system("pause");
				system("cls");
			}
			else if (choose == 3) {
				acc.themNhac();
				system("pause");
				system("cls");
			}
			else if (choose == 4) {
				acc.DanhSach();
				system("pause");
				system("cls");
			}
			else if (choose == 5) {
				acc.Xuat();
				system("pause");
				system("cls");
			}
			else if (choose == 6) {
				acc.xoaNhac();
				system("pause");
				system("cls");
			}
			else if (choose == 7)
				break;
			else if (choose == 0) {
				out = 0;
				break;
			}
		}
	}
	cout << " \nThank you for using this example\n";
	cout << "\t Have a nice day !\n";
	return 0;
}