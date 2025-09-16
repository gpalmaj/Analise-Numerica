#include "sistlinear.h"
#include <stdlib.h>
#include <math.h>

static void troca_linhas(int n, double **A, double* b, int L0, int L1)
{
    if (L0 == L1) return;
    
    double* temp_row = A[L0];
    A[L0] = A[L1];
    A[L1] = temp_row;
    
    double temp_b = b[L0];
    b[L0] = b[L1];
    b[L1] = temp_b;
}

static int encontra_pivo(int n, double **A, int k)
{
    int pivo = k;
    double max_val = fabs(A[k][k]);
    
    for (int i = k + 1; i < n; i++) {
        if (fabs(A[i][k]) > max_val) {
            max_val = fabs(A[i][k]);
            pivo = i;
        }
    }
    
    return pivo;
}

void gauss(int n, double** A, double* b, double* x)
{
    for (int k = 0; k < n - 1; k++) {
        int pivo = encontra_pivo(n, A, k);
        
        if (pivo != k) {
            troca_linhas(n, A, b, k, pivo);
        }
        
        for (int i = k + 1; i < n; i++) {
            if (A[k][k] != 0.0) {  
                double m = A[i][k] / A[k][k];  
                
                for (int j = k; j < n; j++) {
                    A[i][j] = A[i][j] - m * A[k][j];
                }
                
                b[i] = b[i] - m * b[k];
            }
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        
        if (A[i][i] != 0.0) {  
            x[i] = (b[i] - sum) / A[i][i];
        } else {
            x[i] = 0.0;  
        }
    }
}
