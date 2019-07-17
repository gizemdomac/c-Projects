#ifndef RANDEVU_H
#define RANDEVU_H
#include<iostream>
#include<cstring>

using namespace std;


class randevu
{
    public:
        randevu();

        bool karsilastir(randevu);//randevulari karsilastir
        void uygun_saatler();
	    int *get_uygun_saatler(); //

        void randevu_olustur();

	    void randevu_ata(int);

        virtual ~randevu();
    protected:
    private:

        int *uygun_saat = new int[8];//10 dan 17 ye kadar olan 8 saat dilimini tutar
	    int baslangic_saati;
	    int bitis_saati;
	    int saatler[8]; //8 tane saat deðeri
	    bool uygunluk[8];
	    string tarih;
};

#endif // RANDEVU_H
