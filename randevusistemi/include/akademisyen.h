#ifndef AKADEMISYEN_H
#define AKADEMISYEN_H
#include<iostream>
#include <cstring>
#include "randevu.h"


using namespace std;


class akademisyen : public randevu
{

 public:
    akademisyen();

	void ekle_aka(string);
	void getir_aka();
	int sicilnumarasigetir();
	virtual ~akademisyen();
    protected:

    private:
        int sicil_numarasi;
	    int yeni_akademisyen;
	    string akademisyen_adi;
	    string akademizyen_soyadi;
	    string anabilim_dali;
	    string e_posta;
	    string telefon_no;
	    string unvan;


};

#endif // AKADEMISYEN_H
