#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream FileIn;
	FileIn.open("C:\\Users\\Joker's\\Desktop\\hihi.txt", ios_base::in);		//Doc du lieu
	if (FileIn.fail() == true)
	{
		cout << "file cua ban khong ton tai";
		return 0;
	}
	int x, y,z;
	FileIn >> x;		//Lay gia tri dau tien trong file
	FileIn >> y;		//Lay gia tri tiep theo
	FileIn >> z;
	FileIn.close();

	ofstream FileOut;
	FileOut.open("C:\\Users\\Joker's\\Desktop\\hihi.txt", ios_base::out);
	FileOut << x + y;
	FileOut << x + y + z;
	FileOut << 21;
	return 0;
}
