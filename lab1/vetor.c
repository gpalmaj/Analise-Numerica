#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* vet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}

void vet_libera (double* v)
{
  free(v);
}

void vet_mults (int n, double* v, double s, double* w)
{
  for (int i=0; i<n; ++i)
    w[i] = v[i]*s;
}

void vet_imprime (int n, double* v)
{
  for (int i=0; i<n; ++i)
    printf("%.16g  ",v[i]);
  printf("\n");
}

double vet_escalar (int n, double* v, double* w){
	double esc_prod = 0;
	for (int i = 0; i<n; i++){
		esc_prod = esc_prod+ v[i]*w[i];
		printf("%f * %f\n", v[i], w[i]);
	}
	printf("produto escalar = %f\n", esc_prod);
	return esc_prod; 
}

double vet_norma2 (int n, double* v){
	double norma2 = 0;
	for(int i=0; i<n;i++){
		norma2 = norma2+ (v[i]*v[i]);
	}
	norma2 = sqrt(norma2);
	printf("Norma 2 = %f\n", norma2);
	return sqrt(norma2);
}

int vet_iguais (int n, double* v, double* w, double tol){
	for (int i = 0; i<n; i++){
		if(fabs(v[i]-w[i]) > tol ){

			printf("os vetores NAO sao iguais\n");
			return 0;
		}
	}
	printf("os vetores sao iguais\n");
	return 1;


}
