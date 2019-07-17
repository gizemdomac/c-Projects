
#include "ogrenci.h"
#include "akademisyen.h"
#include <fstream>
#include <iostream>
#include "randevu.h"
#include <string>
#define STATUS_STACK_OVERFLOW 0x00402F6E
#define STATUS_STACK_OVERFLOW 0x0040331A

using namespace std;

ogrenci::ogrenci()
{

}
void ogrenci::ekle_ogr(string yeni)
{
	int counter = 0; //dosyadaki kelime sayisi
	int ara_deger=0;//dosya okuma sýrasýnda indisin kaldýgý yeri tutan degisken

	for (int i = 0; i < yeni.length(); i++) //alýnan satýrlarý parse etmek icin olusturuldu
	{
		if (yeni[i] == char(32) || i == yeni.length()-1) //bosluk karakterine kadar i degeri artar
		{
		    if (counter == 6)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				telefon_no =  (yeni.substr(ara_deger, i - ara_deger+1));
				counter++;
				ara_deger = i;
			}
		     if (counter == 5)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				mail = (yeni.substr(ara_deger, i - ara_deger+1));
				counter++;
				ara_deger = i;
			}
            if (counter == 4)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				kayit_yili= stoi(yeni.substr(ara_deger, i - ara_deger+1));
				counter++;
				ara_deger = i;
			}
		    if (counter == 3)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				bolum = (yeni.substr(ara_deger, i - ara_deger+1));
				counter++;
				ara_deger = i;
			}
			if (counter == 2)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				okul_numarasi = stoi(yeni.substr(ara_deger, i - ara_deger+1));
				counter++;
				ara_deger = i;
			}
			if (counter == 1)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				ogrenci_soyadi = yeni.substr(ara_deger, i-ara_deger);
				counter++;
				ara_deger = i;
			}
			if (counter == 0)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
			    ogrenci_adi = yeni.substr(0, i);
				counter++;
				ara_deger = i;
			}
		}
	}
}
void ogrenci::getir_ogr()
{

	cout << ogrenci_adi <<" - " <<ogrenci_soyadi<<" - " <<okul_numarasi<<" - "<<bolum<<" - "<<kayit_yili<<" - "<<mail<<" - "<<telefon_no<<endl<<endl;
	//randevu_ata();
	uygun_saatler();

}
int ogrenci::okulnumarasigetir()
{
	return okul_numarasi;
}
ogrenci::~ogrenci()
{

}



