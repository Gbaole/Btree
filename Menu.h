#include <iostream>
using namespace std;
void Menu();		// Ham nay se xuat ra cac danh sach menu
int ChonMenu();		// Ham nay dung de chon 1 menu tuong ung
void XuLyMenu();	// Xu ly menu ung voi menu duoc chon


void Menu() {
	cout << "=================Home Page================\n";
	cout << "1. Tao Trang Moi\n";
	cout << "2. Lich Su\n";
	cout << "3. Dau Trang\n";
	cout << "4. Tim Kiem\n";
	cout << "5. Thoat!!!\n";
	cout << "=====================================\n";
}
int ChonMenu()
{
	int n = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n > 0 || n < 5)
		return n;
	else
		return ChonMenu();
		
}
void XuLyMenu()
{
	int chon = ChonMenu();
	switch (chon)
	{
	case 1:
		cout << "1. Trang Moi Da Duoc Tao.\n";
		break;
	case 2:
		cout << "2. Lich Su Cua Ban\n";
		break;
	case 3:
		cout << "3. Cac Trang Yeu Thich\n";
		break;
	case 4:
		cout << "4. Thong Tin Ban Can Tim\n";
		break;
	case 5:
		cout << "5. Dong Trinh Duyet\n";
		break;
	}
}
