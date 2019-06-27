#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin_1;
	fin_1.open("data_v24.bin",ios::binary);
	if(!fin_1.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	} else {
		cout << "Файл подтвержден" <<endl;
		double d;
		int num = 0;
		while (fin_1.read((char*)&d, sizeof(d))) {
			num++;
		}
		fin_1.close();
		cout << "Количество чисел: " << num << endl;
		double * f = new double [num];
		ifstream fin_2;
		fin_2.open("data_v24.bin",ios::binary);
		for (int i = 0; i < num; i++) {
			fin_2.read((char*)&f[i], sizeof(f[i]));
			f[i]=1/f[i];
			//cout << f[i] << endl;
			
		}
		fin_2.close();

		float * mas = new float[num];
		ofstream fout;
		fout.open("file1.bin",ios::binary);
		for (int i = 0; i < num; i++) {
			mas[i]=f[i
			];
			fout.write((char*)&mas[i], sizeof(mas[i]));
			
			cout << mas[i] << endl;
		}
		fout.close();
		return 0;
	}
}
