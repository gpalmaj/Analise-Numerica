#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

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
  double norma2v = vet_norma2(2,v);
  printf("Analizando vetores V e W: ");
  vet_iguais(2,v,w, 0.001);
	
  double * u = vet_cria(2);
  u[0] = 1.02;
  u[1] = 2.00;

  printf("Analizando vetores V e U: ");
  vet_iguais(2,v,u, 0.001);
		
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


