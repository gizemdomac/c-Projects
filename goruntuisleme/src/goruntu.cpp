#include "goruntu.h"
#include <iostream>
#include<fstream>
#include <istream>
#include <string>
#include <math.h>

using namespace std;


goruntu::goruntu(int h, int w){

	height = h;
	width = w;
	image = new int*[h];//satır sayısını belirledik yani yükseklik
	sobel_imageX = new int*[h];//satır sayısını belirledik
	sobel_imageY = new int*[h];//satır sayisini belirledik
	for (int i = 0; i < h; i++){
		image[i] = new int[w];
		sobel_imageX[i] = new int[w];
		sobel_imageY[i] = new int[w];
	}
}

goruntu::goruntu(string data)
{
	sobelX[0][0] = -1;
	sobelX[0][1] = 0;
	sobelX[0][2] = 1;
	sobelX[1][0] = -2;
	sobelX[1][1] = 0;
	sobelX[1][2] = 2;
	sobelX[2][0] = -1;
	sobelX[2][1] = 0;
	sobelX[2][2] = 1;

	sobelY[0][0] = 1;
	sobelY[0][1] = 2;
	sobelY[0][2] = 1;
	sobelY[1][0] = 0;
	sobelY[1][1] = 0;
	sobelY[1][2] = 0;
	sobelY[2][0] = -1;
	sobelY[2][1] = -2;
	sobelY[2][2] = -1;


	int counter = 0; //dosyadaki kelime sayisi
	int ara_deger;//dosya okuma sýrasýnda indisin kaldýgý yeri tutan degisken
	int sayac_height = 0;
	int sayac_witdh = 0;

	for (int i = 1; i < data.length(); i++) //alýnan satýrlarý parse etmek icin olusturuldu
	{
		if (data[i] == char(32) || i == data.length()-1) //bosluk karakterine kadar i degeri artar
		{
			if (counter == 2)
			{
				image[sayac_height][sayac_witdh] = stoi(data.substr(ara_deger, i - ara_deger));
				ara_deger = i;

				sayac_witdh++;
				if (sayac_witdh == width)
				{
					sayac_height++;
					sayac_witdh = 0;
				}


			}

			if (counter == 1)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				width = stoi(data.substr(ara_deger, i - ara_deger));
				counter++;
				ara_deger = i;
				image = new int*[height];
				sobel_imageX = new int*[height];
				sobel_imageY = new int*[height];
				for (int i = 0; i < height; i++){
					image[i] = new int[width];
					sobel_imageX[i] = new int[width];
					sobel_imageY[i] = new int[width];
				}
			}
			if (counter == 0)  //dosyadaki ilk kelimeyi basar(ilk bosluga kadar )
			{
				height = stoi(data.substr(0, i));
				counter++;
				ara_deger = i;
			}
		}
	}


}



void goruntu::sobel(){
	int toplam;
	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			sobel_imageX[i][j] = image[i][j];
			sobel_imageY[i][j] = image[i][j];
		}
	}

	for (int i = 0; i < height-2; i++)
	{
		for (int j = 0; j < width-2; j++)
		{
			toplam = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					toplam = toplam + image[i + k][j + l] * sobelX[k][l];
				}
			}

			sobel_imageX[i+1][j+1] = toplam;
		}
	}
	for (int i = 0; i < height - 2; i++)
	{
		for (int j = 0; j < width - 2; j++)
		{
			toplam = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					toplam = toplam + image[i + k][j + l] * sobelY[k][l];
				}
			}

			sobel_imageY[i+1][j+1] = toplam;
		}
	}

	for (int i = 1; i < height-1; i++){
		for (int j = 1; j < width-1; j++){
			image[i][j] = sqrt(pow(sobel_imageX[i][j], 2) + pow(sobel_imageY[i][j], 2));
		}
	}


}

void goruntu::threshold(int deger){

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (image[i][j] < deger)
			{
				image[i][j] = 0;
			}
			else
			{
				image[i][j] = 255;
			}

		}
	}
}

goruntu goruntu::operator*(const goruntu& ikinci) const
{

	goruntu temp(height,width);

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){

			temp.image[i][j] = image[i][j] & ikinci.image[i][j];
		}
	}
	return temp;
}

goruntu goruntu::operator+(const goruntu& ikinci)const
{

	goruntu temp2(height, width);

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){

			temp2.image[i][j] = image[i][j] | ikinci.image[i][j];
		}
	}
	return temp2;
}
void goruntu::yazdir(){
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++){
			cout << image[i][j] << "--";
		}
		cout << endl;
	}
}
goruntu::~goruntu()
{


}
