#include <iostream>
#include <string>

using namespace std;
#pragma once

class goruntu
{

private:
	int sobelX[3][3];
	int sobelY[3][3];

	int **sobel_imageX;//sobelX matrisi ile �arp�ld�ktan sonraki image
	int **sobel_imageY;//sobelY matrisi ile �arp�ld�ktan sonraki image

public:
	int height;
	int width;
	int **image;//Resmimiz

	goruntu(int,int);//y�kseklik ve geni�lik
	goruntu(string);//dosyadan veri okurken y�kseklik ve geni�lik bilgisi
	void sobel();
	goruntu operator* (const goruntu&) const;
	goruntu operator+ (const goruntu&)const ;
	void threshold(int);

	void yazdir();
	~goruntu();
};

