#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double** mat_cria (int m, int n)
{
  double** A = (double**) malloc(m*sizeof(double*));
  for (int i=0; i<m; ++i)
    A[i] = (double*) malloc(n*sizeof(double));
  return A;
}

void mat_libera (int m, double** A)
{
  for (int i=0; i<m; ++i)
    free(A[i]);
  free(A);
}
  
void mat_imprime (int m, int n, double** A)
{
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      printf("%.16g  ", A[i][j]);
    }
    printf("\n");
  }
}

void mat_transposta (int m, int n, double **A, double** T){
	for (int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			T[i][j] = A[j][i];
		}
	}
}

void mat_multv (int m, int n, double** A, double* v, double* w){
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m;j++){
			w[i] = w[i]+ A[i][j] * v[j];
		}
	}
}

void mat_multm (int m, int n, int q, double** A, double** B, double** C){
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; j++){
			C[i][j] = A[i][j] * B[j][i];
		}
	}

}
