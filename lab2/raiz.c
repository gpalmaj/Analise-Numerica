#include "raiz.h"
#include <math.h>

#define ERRO_MAX 0.000000005
#define MIN_ABS_FC 0.0000000000001


int bissecao (double a, double b, double (*f) (double x), double* r){
	double fa = f(a);
	double fb = f(b);


	double c = (a+b)/2;

	if(fa*fb>=0)
		return -1;

	int i = 0;

	double e = (b - a)/2;


	double fc = f(c);
	while((e>ERRO_MAX) && (fabs(fc)>= MIN_ABS_FC) ){

		//INVERSAO DE SINAL ENTRE A E O PONTO MEDIO
		if(fc*fa< 0){
			b = c;
			fb = fc;
			

		}
		//INVERSAO DE SINAL ENTRE O PONTO MEDIO E B
		else if(fc*fb<0){
			a = c;
			fa = fc;
			
		}
		
		c = (a+b)/2;
		e = (b-a)/2;

		fc = f(c);
		
		i++;
	}
	
	*r = c;
	return i;

}
