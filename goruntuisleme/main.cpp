//GİZEM DOMAÇ -259191

#include <iostream>
#include<fstream>
#include <istream>
#include <string>
#include "goruntu.h"

using namespace std;

string dosya_oku_1();
string dosya_oku_2();

int main()
{
	string first_image_data=dosya_oku_1();
	goruntu image1(first_image_data);

	string second_image_data = dosya_oku_2();
	goruntu image2(second_image_data);

	cout << endl << "BIRINCI RESIM" << endl;
	image1.yazdir();

	cout << endl << "BIRINCI RESIM SOBEL ISLEM SONUCU" << endl;
	image1.sobel();
	image1.yazdir();

	cout << endl << "BIRINCI RESIM THRESHOLD ISLEM SONUCU" << endl;
	image1.threshold(2);
	image1.yazdir();

	cout << endl << "IKINCI RESIM" << endl;
	image2.yazdir();

	cout << endl << "IKINCI RESIM SOBEL ISLEM SONUCU" << endl;
	image2.sobel();
	image2.yazdir();

	cout << endl << "IKINCI RESIM THRESHOLD ISLEM SONUCU" << endl;
	image2.threshold(5);
	image2.yazdir();


	cout << endl << "BIRINCI RESIM" << endl;
	image1.yazdir();
	cout << endl << "IKINCI RESIM" << endl;
	image2.yazdir();

	goruntu image4 = image1 * image2;

	goruntu image5 = image1 + image2;

	cout << endl<<"AND ISLEMI"<<endl;
	image4.yazdir();

	cout << endl << "OR ISLEMI" << endl;
	image5.yazdir();


	getchar();
	return 0;


}


string dosya_oku_1(){
	int counter = 0; //dosyadaki kelime sayisi
	int ara_deger;//dosya okuma sırasında indisin kaldıgı yeri tutan degisken
	ifstream file;
	file.open("goruntu1.txt", ios::in);

	string okunan_veri;
	string tum_veriler;
	int sayac = 0;
	if (file.is_open())
	{
		while (true)
		{
			if (!file.eof())
			{

				getline(file, okunan_veri);//dosyayı satır satır okumak icin
				tum_veriler = tum_veriler +" "+ okunan_veri;

			}
			else
				break;
		}

	}
	else
	{
		cout << "Boyle bir dosya bulunamadı!!!\n";
	}
	file.close();
	return tum_veriler;
}

string dosya_oku_2(){
	int counter = 0; //dosyadaki kelime sayisi
	int ara_deger;//dosya okuma sırasında indisin kaldıgı yeri tutan degisken
	ifstream file;
	file.open("goruntu2.txt", ios::in);

	string okunan_veri;
	string tum_veriler;
	int sayac = 0;
	if (file.is_open())
	{
		while (true)
		{
			if (!file.eof())
			{

				getline(file, okunan_veri);//dosyayı satır satır okumak icin
				tum_veriler = tum_veriler + " " + okunan_veri;

			}
			else
				break;
		}

	}
	else
	{
		cout << "Boyle bir dosya bulunamadı!!!\n";
	}
	file.close();
	return tum_veriler;
}
