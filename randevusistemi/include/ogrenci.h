#ifndef OGRENCI_H
#define OGRENCI_H
#include<iostream>
#include<cstring>
#include "randevu.h"

using namespace std;


class ogrenci: public randevu
{

public:
    ogrenci();
	int okulnumarasigetir();
	void ekle_ogr(string);
	void getir_ogr();
	//void  randevu_atama(akademisyen);

	virtual ~ogrenci();


    protected:

    private:
        int okul_numarasi;
		string ogrenci_adi;
		string ogrenci_soyadi;
		string bolum;
		int kayit_yili;
		string dogum_tarihi;
		string telefon_no;//+ ile baþladýgý için string aldým
		string mail;




};

#endif // OGRENCI_H
