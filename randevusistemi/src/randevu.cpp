
#include "randevu.h"
#include "ogrenci.h"
#include "akademisyen.h"

randevu::randevu()
{

for (int i = 0; i < 8; i++){
		saatler[i] = i + 10; //randevu saatleri 10 dan ba�lay�p 17 ye kadar
		uygunluk[i] = true; //her saaat i�in uygunluk durumu
	}
}
bool randevu::karsilastir(randevu randevu2)
{
return true;
}
void randevu::uygun_saatler() //bu fonksiyon uygun saatleri ekrana yazmak i�in yap�ld�
{
	cout << "Uygun zamanlar : ";
	for (int i = 0; i < 8; i++){
		if (uygunluk[i] == true)
			cout <<saatler[i]<<"--" ;
	}
	cout << endl;
}
int *randevu::get_uygun_saatler() //uygun olan saatleri d�nd�r�r
{

	for (int i = 0; i < 8; i++){
		if (uygun_saat[i]>0)
			uygun_saat[i] = -1; //eger atanma islemi yap�ld�ysa o ssat dilimini -1 yaptim
	}

	for (int i = 0; i < 8; i++){
		if (uygunluk[i] == true){
			uygun_saat[i] = saatler[i];

		}
	}


	return uygun_saat;
}
void randevu::randevu_ata(int gelen_saat)
{
	for (int i = 0; i < 8; i++){

		if (saatler[i] == gelen_saat)
		{
			uygunluk[i] = false;
			break;
		}
	}

}

randevu::~randevu()
{
    delete uygun_saat;
}
