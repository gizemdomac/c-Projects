#include "akademisyen.h"


akademisyen::akademisyen()
{
    //ctor
}
int akademisyen::sicilnumarasigetir(){
	return sicil_numarasi;
}
void akademisyen::ekle_aka(string yeni)
{
	int counter = 0; //dosyadaki kelime sayisi
	int ara_deger;//dosya okuma sırasında indisin kaldıgı yeri tutan degisken

	for (int i = 0; i < yeni.length(); i++) //alınan satırları parse etmek icin olusturuldu
	{
		if (yeni[i] == char(32) || i == yeni.length() - 1) //bosluk karakterine kadar i degeri artar
		{
		     if (counter == 7)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				unvan = (yeni.substr(ara_deger, i - ara_deger + 1));
				counter++;
				ara_deger = i;
			}
		     if (counter == 6)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				telefon_no = (yeni.substr(ara_deger, i - ara_deger + 1));
				counter++;
				ara_deger = i;
			}
		     if (counter == 5)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				anabilim_dali = (yeni.substr(ara_deger, i - ara_deger + 1));
				counter++;
				ara_deger = i;
			}
		     if (counter == 4)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				e_posta = (yeni.substr(ara_deger, i - ara_deger + 1));
				counter++;
				ara_deger = i;
			}

		    if (counter == 3)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				anabilim_dali = (yeni.substr(ara_deger, i - ara_deger + 1));
				counter++;
				ara_deger = i;
			}

			if (counter == 2)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				sicil_numarasi = stoi(yeni.substr(ara_deger, i - ara_deger + 1));
				counter++;
				ara_deger = i;
			}
			if (counter == 1)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				akademizyen_soyadi = yeni.substr(ara_deger, i - ara_deger);
				counter++;
				ara_deger = i;
			}
			if (counter == 0)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				akademisyen_adi = yeni.substr(0, i);
				counter++;
				ara_deger = i;
			}
		}
	}
}
void akademisyen::getir_aka()
{
	cout << akademisyen_adi << " - " << akademizyen_soyadi << " - " << sicil_numarasi <<" - " <<anabilim_dali<<" - "<<e_posta<<" - "<<telefon_no<<" - "<<unvan<<endl<<endl;
	//randevu_ata();
	uygun_saatler();
}
akademisyen::~akademisyen()
{
    //dtor
}
