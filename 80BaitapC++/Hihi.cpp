#include<iostream>
#include<math.h>

using namespace std;
int UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int BCNN(int a, int b)
{
	return a * b / UCLN(a, b);
}

struct PhanSo
{
	int tuSo;
	int mauSo;
};
typedef struct PhanSo PhanSo;
void nhap_PS(PhanSo &x)
{ 
	cout << "Nhap tu so : ";
	cin >> x.tuSo;
	cout << endl;
	cout << "Nhap mau so : ";
	cin >> x.mauSo;
	cout << endl;
}
void xuat_PS(PhanSo x)
{
	cout << "\n" << x.tuSo << "/" << x.mauSo;
}

//Khai bao struct danh sach
struct danhsach
{
	PhanSo* arr;
	int n;
};
typedef struct danhsach DanhSach;
//Ham nhap danh sach Phan so
void nhap_Danh_Sach_PS(DanhSach& dS)
{
	for (int i = 0; i < dS.n; i++)
	{
		cout << "\nNhap phan so thu : " << i + 1 << " "<<endl;
		nhap_PS(dS.arr[i]);
	}
}
void xuat_Danh_Sach_PS(DanhSach dS)
{
	for (int i = 0; i < dS.n; i++)
	{
		cout << "\nPhan so thu : " << i + 1;
		xuat_PS(dS.arr[i]);
		cout << endl;
	}
}
void rutGon(PhanSo& x)
{
	int ucln = UCLN(x.tuSo, x.mauSo);
	x.tuSo = (x.tuSo) / ucln;
	x.mauSo = (x.mauSo) / ucln;
}
void rutGon_DS_PhanSo(DanhSach dS)
{
	for (int i = 0; i < dS.n; i++)
	{
		rutGon(dS.arr[i]);
	}
}
PhanSo cong_2PS(PhanSo x, PhanSo y)
{
	PhanSo kq;
	if (x.mauSo != y.mauSo)
	{
		kq.tuSo = x.tuSo * y.mauSo + x.mauSo * y.tuSo;
		kq.mauSo = x.mauSo * y.mauSo;
		rutGon(kq);
	}
	else
	{
		kq.tuSo = x.tuSo + y.tuSo;
		kq.mauSo = x.mauSo;
		rutGon(kq);
	}
	return kq;
}
PhanSo tinh_Tong_Phan_So(DanhSach& ds)
{
	PhanSo ketqua = ds.arr[0];
	for (int i = 1; i < ds.n; i++)
	{
		ketqua = cong_2PS(ketqua, ds.arr[i]);
	}
	return ketqua;
}
PhanSo tim_Max(DanhSach ds)
{
	PhanSo max = ds.arr[0];
	for (int i = 1; i < ds.n; i++)
	{
		if (max.mauSo == ds.arr[i].mauSo)
		{
			if (max.tuSo < ds.arr[i].tuSo)
				max = ds.arr[i];
		}
		else
		{
			if ((max.tuSo * ds.arr[i].mauSo) < (ds.arr[i].tuSo * max.mauSo))
				max = ds.arr[i];
		}
	}
	return max;
}
int main()
{
	DanhSach ds;
	cout << "\nNhap so phan tu cua danh sach : ";
	cin >> ds.n;

	ds.arr = new PhanSo [ds.n];

	cout << "\n\n\tNhap danh sach phan so : \n";
	nhap_Danh_Sach_PS(ds);
	cout << "\n\n\tXuat danh sach phan so : \n";
	xuat_Danh_Sach_PS(ds);

	rutGon_DS_PhanSo(ds);
	printf("\n\n\t\tDanh sach phan so sau khi rut gon : \n");
	xuat_Danh_Sach_PS(ds);

	PhanSo tong;
	tong = tinh_Tong_Phan_So(ds);
	cout << "\n Tong cac phan so trong danh sach : ";
	xuat_PS(tong);

	PhanSo max;
	max = tim_Max(ds);
	cout << "\n\n\t Phan tu max trong danh sach la : ";
	xuat_PS(max);

	delete[] ds.arr;

	return 0;
}
