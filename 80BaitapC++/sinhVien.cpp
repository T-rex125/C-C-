#include<iostream>
#include<string.h>
using namespace std;
struct sinhvien
{
	char name[30];
	int tuoi;
	char que[30];
	int mssv;
};
typedef struct sinhvien SinhVien;
void nhap_Mot_Sinh_Vien(SinhVien *x)
{
//	cin.ignore();
	cout<<("\nNhap ten sinh vien : ");
	cin.getline(x->name, 30);
	cout << "\nNhap tuoi sinh vien : ";
	cin >> x->tuoi;
	cin.ignore();
	cout << "\nNhap que sinh vien : ";
	cin.getline(x->que, 30);
	cout << "\nNhap ma so sinh vien : ";
	cin >> x->mssv;
}
void xuat_Mot_Sinh_Vien(SinhVien *x)
{
	cout << "\nTen sinh vien : "<<x->name;
	cout << "\nTuoi :" << x->tuoi;
	cout << "\nQue quan " << x->que;
	cout << "\nMa so sinh vien : " << x->mssv;
}
int main()
{
	SinhVien *a;
	a = new SinhVien();
	nhap_Mot_Sinh_Vien(a);
	xuat_Mot_Sinh_Vien(a);

	delete a;

	return 0;

}