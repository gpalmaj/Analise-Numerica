#include "taylor.h"
#include <stdio.h>
#include <stdlib.h>


double factorial (int x){
	if (x<=1){
		return 1;
	}
	else {
		return (x*factorial(x-1));
	}

	
}

double power(double x, int p){
	double ans = 1;
	for(int i=0; i<p; i++){
		ans = ans * x;
	}

	return ans;

}

double avalia_taylor (int n, double* c, double x1, double x){
	double p_tay = 0;
	double fact = 1;
	double pow = 1;
	

	//LOOP INICIAL DO SOMATORIO
	for(int i=0; i<n; i++){
		pow = x*pow;
		fact = (i+1)*fact;
		
		//CONTA RECORRENTE
		p_tay = p_tay + (c[i]/(fact))*(pow);
		
	}

	return p_tay;
}

double avalia_seno (int n, double x){
	double coef[] = {1,0,-1,0};
	
	return avalia_taylor(n, coef, 0, x);

}
