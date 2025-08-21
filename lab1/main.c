#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

double vet_escalar (int n, double* v, double* w);

int main (void)
{
  /* Exemplo de construção de vetor dinâmico */
  double* v = vet_cria(2);
  v[0] = 1.0;
  v[1] = 2.0;

  /* Exemplo de construção de vetor estático */
  double w[] = {1.0,2.0f};

  /* Imprime vetores (são iguais em conteúdo) */
  //vet_imprime(2,v);
  //vet_imprime(2,w);

  double  produtovw = vet_escalar(2, v, w );
  
  /* Exemplo de construção de matriz dinâmica */
  double** A = mat_cria(3,2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  A[2][0] = 5.0;
  A[2][1] = 6.0;

  /* Exemplo de construção de matriz estática no formato ponteiro para ponteiro */
  double linha1[] = {1.0,2.0};
  double linha2[] = {3.0,4.0};
  double linha3[] = {5.0,6.0};
  double* B[] = {linha1,linha2,linha3};

  /* Imprime matrizes (são iguais em conteúdo) */
  //mat_imprime(3,2,A);
  //mat_imprime(3,2,B);

  /* Apenas objetos dinâmicos podem ser liberados */
  vet_libera(v);
  mat_libera(3,A);

  return 0; 
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
