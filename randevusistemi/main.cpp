// GİZEM DOMAÇ 259191

#include <iostream>
#include "randevu.h"
#include <istream>;
#include <string>
#include <windows.h>
#include <fstream>
#include "ogrenci.h"
#include "akademisyen.h"
#include "randevu.h"

using namespace std;

ogrenci ogrenciler[100];
akademisyen akademisyenler[100];


void anamenu(); //Ekranda menü oluþturcaz
void dosya_oku_akademisyen(); //akademisyenleri dosyadan okumak için
void dosya_oku_ogrenci(); //öðrencileri dosyadan okumak için

void ogrenci_oku() //okul numarasi ve öðrenci ismini getirmek için yapýlan faonksiyon
{

	for (int i = 0; i < 100; i++){
		if (ogrenciler[i].okulnumarasigetir()>0){
			cout << i << " : ";
			ogrenciler[i].getir_ogr();
		}
	}
	cout << "Ana Menuye donmek icin herhangi bir tusa  basiniz"<<endl;
	string gelen_key;
	cin >> gelen_key;
	anamenu();
}
void akademisyen_oku() //akademisyenlerin sicil numarasýný ve ismini getirir
{
	for (int i = 0; i < 100; i++){
		if (akademisyenler[i].sicilnumarasigetir() > 0)
			akademisyenler[i].getir_aka();
	}
	cout << "Ana Menuye donmek icin herhangi bir tusa  basiniz" << endl;
	string gelen_key;
	cin >> gelen_key;
	anamenu();
}
void randevu_olustur(){
	ogrenci secilen_ogrenci;
	akademisyen secilen_akademisyen;
	cout << "OGRENCILER!" << endl;

	for (int i = 0; i < 100; i++){
		if (ogrenciler[i].okulnumarasigetir()>0){
			cout << i << " : ";
			ogrenciler[i].getir_ogr();
		}
	}
	cout << "Ogrenci seciniz veya ust menuye donmek icin z'ye basiniz" << endl;
	string ogrenci_id;
	cin >> ogrenci_id;

	if (ogrenci_id == "z")
		anamenu();
	else
		secilen_ogrenci = ogrenciler[stoi(ogrenci_id)];

	system("CLS");
	secilen_ogrenci.getir_ogr();
	cout << "-----------------------------------------" << endl;
	cout << "AKADEMISYENLER" << endl;
	for (int i = 0; i < 100; i++){
		if (akademisyenler[i].sicilnumarasigetir() > 0){
			cout << i << " : ";
			akademisyenler[i].getir_aka();
		}
	}


	cout << "Akademisyen seçiniz veya üst menuye donmek icin z'ye basiniz" << endl;
	string akademisyen_id;
	cin >> akademisyen_id;

	if (akademisyen_id == "z")
		anamenu();
	else
		secilen_akademisyen = akademisyenler[stoi(akademisyen_id)];
		system("CLS");
	cout << "SECILEN OGRENCI VE AKADEMISYEN" << endl;
	cout << "Ogrenci : ";
	secilen_ogrenci.getir_ogr();
	cout << "Akademisyen : ";
	secilen_akademisyen.getir_aka();
	cout << "-----------------------------------------" << endl;
//secilen_ogrenci.randevu_atama(secilen_akademisyen);
	int *ogrenci_saatleri = new int[8];
	ogrenci_saatleri = secilen_ogrenci.get_uygun_saatler();
	int *akademisyen_saatleri = new int[8];
	akademisyen_saatleri = secilen_akademisyen.get_uygun_saatler();
	bool kontrol = false;
	for (int i = 0; i < 8; i++) //ogrenci için tüm saat dilimi kontrol ediliyor
	{
	    for (int j = 0; j < 8; j++)
        { //akademisyen için tüm uygun saatler kontrol ediliyor

			if (ogrenci_saatleri[i] == akademisyen_saatleri[j])
			{
				secilen_ogrenci.randevu_ata(ogrenci_saatleri[i]);
				secilen_akademisyen.randevu_ata(akademisyen_saatleri[j]);
				kontrol = true;
				cout << "atandi" << endl;
				ogrenciler[stoi(ogrenci_id)] = secilen_ogrenci;
				akademisyenler[stoi(akademisyen_id)] = secilen_akademisyen;

				ofstream yourfile("randevu.txt", ios::app);
				if(yourfile.is_open()){
				yourfile << secilen_ogrenci.okulnumarasigetir()<<" "<<secilen_akademisyen.sicilnumarasigetir()<<" "<<ogrenci_saatleri[i] << endl;
				yourfile.close();
				break;
				}

			}
		}
            if (kontrol == true){
			break;
		}
	}
	anamenu();
}
	void randevular(){
	ifstream file;
	file.open("randevu.txt", ios::in);

	string okunan_veri;
	int saat = 0;
	int ogrenci_okul_no=0;
	int akademisyen_sicil_no = 0;
	int counter = 0;
	int ara_deger = 0;

	if (file.is_open())
	{
		while (true)
		{
			if (!file.eof())
			{
			    saat = 0;
			    ogrenci_okul_no = 0;
			    akademisyen_sicil_no = 0;
			    getline(file, okunan_veri);//dosyayý satýr satýr okumak icin
				for (int i = 0; i < okunan_veri.length(); i++) //alýnan satýrlarý parse etmek icin olusturuldu
				{
					if (okunan_veri[i] == char(32) || i == okunan_veri.length() - 1) //bosluk karakterine kadar i degeri artar
					{
						if (counter == 2)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
						{
							saat = stoi(okunan_veri.substr(ara_deger, i - ara_deger + 1));
							counter++;
							ara_deger = i;
						}
						if (counter == 1)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
						{
							akademisyen_sicil_no = stoi(okunan_veri.substr(ara_deger, i - ara_deger + 1));
							counter++;
							ara_deger = i;
						}
						if (counter == 0)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
						{
							ogrenci_okul_no = stoi(okunan_veri.substr(0, i));
							counter++;
							ara_deger = i;
						}
					}
				}
				if (ogrenci_okul_no != 0){
					cout << "Ogrenci: " << ogrenci_okul_no;
					cout << " Akademisyen: " << akademisyen_sicil_no;
					cout << " Randevu Saati: " << saat << endl;
				}
				counter = 0;

			}
			else
				break;
		}
	}
	else
	{
		cout << "Boyle bir dosya bulunamadý!!!\n";
	}
	file.close();

	string a;
	cin >> a;
	Sleep(300);
	anamenu();
	}

	void anamenu()
{
	system("CLS");
	cout << "1- Ogrenciler" << endl;;
	cout << "2- Akademisyenler" << endl;
	cout << "3- Randevu Olustur" << endl;
	cout << "4- Randevular" << endl;
	string gelen_key;
	cin >> gelen_key;

	if (gelen_key == "1"){
		system("CLS");
		ogrenci_oku();
	}
	else if (gelen_key == "2")
	{
		system("CLS");
		akademisyen_oku();
	}
	else if (gelen_key == "3"){
		system("CLS");
		randevu_olustur();
	}
	else if (gelen_key == "4"){
		system("CLS");
		randevular();
	}
	else
	{

		cout << endl << "yanlis girdiniz" << endl;
		Sleep(1000);
		anamenu();
	}
}
void dosya_oku_ogrenci()
{

	int counter = 0; //dosyadaki kelime sayisi
	int ara_deger=0;//dosya okuma sýrasýnda indisin kaldýgý yeri tutan degisken
	ifstream files;
	files.open("o.txt", ios::in);

	string okunan_veri;
	ogrenci yeni;
	int sayac = 0;
	if (files.is_open())
	{
		while (true)
		{
			if (!files.eof())
			{
				getline(files, okunan_veri);//dosyayý satýr satýr okumak icin
				yeni.ekle_ogr(okunan_veri);
				for (int i = 0; i < 100; i++)
				{
					ogrenciler[sayac] = yeni;
					sayac++;
					break;
				}
				yeni.~ogrenci();
			}
			else
				break;
		}

	}
	else
	{
		cout << "Boyle bir dosya bulunamadi!!!\n";
	}
	files.close();
}
void dosya_oku_akademisyen()
{

	ifstream file;
	file.open("a.txt", ios::in);

	string okunan_veri;
	akademisyen yeni;
	int sayac = 0;
	if (file.is_open())
	{
		while (true){
			if (!file.eof())
			{
				getline(file, okunan_veri);//dosyayý satýr satýr okumak icin
				yeni.ekle_aka(okunan_veri);
				for (int i = 0; i < 100; i++)
				{
					akademisyenler[sayac] = yeni;
					sayac++;
					break;
				}
				yeni.~akademisyen();


			}
			else
				break;
		}


	}
	else
	{
		cout << "Boyle bir dosya bulunamadý!!!\n";
	}
	file.close();
}


int main()
{
    dosya_oku_ogrenci();
	dosya_oku_akademisyen();
	anamenu();
	getchar();
	getchar();

    return 0;
}
