#include <iostream>
#include <string>

using namespace std;
#pragma once

class goruntu
{

private:
	int sobelX[3][3];
	int sobelY[3][3];

	int **sobel_imageX;//sobelX matrisi ile çarpıldıktan sonraki image
	int **sobel_imageY;//sobelY matrisi ile çarpıldıktan sonraki image

public:
	int height;
	int width;
	int **image;//Resmimiz

	goruntu(int,int);//yükseklik ve genişlik
	goruntu(string);//dosyadan veri okurken yükseklik ve genişlik bilgisi
	void sobel();
	goruntu operator* (const goruntu&) const;
	goruntu operator+ (const goruntu&)const ;
	void threshold(int);

	void yazdir();
	~goruntu();
};

