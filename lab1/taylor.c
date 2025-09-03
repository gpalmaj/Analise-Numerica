#include "taylor.h"
#include <stdio.h>
#include <stdlib.h>



double avalia_taylor (int n, double* c, double x1, double x){
	double p_tay = 0;
	double fact = 1;
	double pow = 1;

	

	//LOOP INICIAL DO SOMATORIO
	for(int i=1; i<n; i++){
		pow = (x-x1)*pow;
		fact = i*fact;
		
		//CONTA RECORRENTE
		p_tay = p_tay + (c[i-1]/(fact))*(pow);

	}

	return p_tay;
}

double avalia_seno (int n, double x){
	int v_coef[] = {1,0,-1,0};

	double *coef = malloc(n*sizeof(double));
	for (int i=0; i<n ;i++ ){
		coef[i] = v_coef[i%4];

	}
	
	return avalia_taylor(n, coef, 0, x);

}
