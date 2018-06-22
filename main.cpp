#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
//Valores utilizados despues #define NO lleva punto y coma al final
//#define declara los valores como constantes al procesador

#define space 20 
#define tama 60 //distancia entre cada fila  y entre cada columna
#define fil 8 
#define col 8
#define grosor 2

int matriz [fil][col];
Scalar B (255,255,255); // fondo
Scalar N (0,0,0); //bordes de matriz
Scalar Az (231,87,0);
        

int hm=tama*col+space*5;
int bm=tama*fil+space*2;
Mat ventana (hm,bm,CV_8UC3,Az);


void Cuadricula() {
    
    for (int i = 0; i < fil+1; i++)
	{
		Point in1(space, tama * i + space);
		Point fin1(tama*col + space, tama * i + space);
		line(ventana, in1, fin1, Az, grosor);
	}
	
	for (int i = 0; i < fil + 1; i++)
	{
		Point in2(tama * i + space, space);
		Point fin2(tama * i + space, tama*fil + space);
		line(ventana, in2, fin2, Az, grosor);
	}
        

}

void Botones(){
    for (int i=0; i<8; i++)
    {
	for (int j = 0; j < fil ; j++){
                Point circulo(tama-10+60*j, tama-10+60*i);
	        int r= 30;
	        circle(ventana, circulo, r, B, CV_FILLED);}
        
    }
        
}

void onMouse(int event, int x, int y, int, void*){
   if (event == CV_EVENT_LBUTTONUP)
    {
	for (int i = 1; i <= fil; i++)
        {
            int valorX = tama*i + space;
            
            int valorY = 480;
            
            
            
        }
                    
    }
}



int main (void){
    namedWindow("Prototipo");	
    setMouseCallback("Prototipo", onMouse);
        Cuadricula();     
        Botones(); 
        while (true)
	{
		imshow("Prototipo", ventana);
		if (waitKey(10) == 27) break;
	}
        
        
        
  
    return 0;
    
}