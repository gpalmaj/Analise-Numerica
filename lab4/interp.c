#include <math.h>

#define PI 3.141592653589793

void regular (int n, double a, double b, double* xi){
    
    // a = x[0]
    //b = x[n-1]

    for(int i=0; i < n; i++){
        xi[i] = a + (i * (b-a)/(n-1));
    }

}

void chebyshev (int n, double a, double b, double* xi){

    int beta = 1;
    for(int i=0; i<n; i++){
        xi[i] = (b-a)/2 * cos(beta*PI/(2*n))+(a+b)/2;
        beta +=2;
    }

}

double cddn(int n, double* xi, double (*f)(double), int i, int j) {
    if (i == j) {
        return f(xi[i]);
    }


    return (cddn(n, xi, f, i+1, j) - cddn(n, xi, f, i, j-1)) / (xi[j] -xi[i]);
}

void coeficientes (int n, double* xi, double (*f) (double), double* bi){
    for (int i = 0; i < n; i++) {
          bi[i] = cddn(n, xi, f, 0, i);  // bi = F[x0...xi]
      }
}

double avalia (int n, double* xi, double* bi, double x){
    double resultado = bi[0];
    
    for (int i=1;i<n;i++){
        double produto = bi[i];
        for (int j=0; j<i; j++){
            produto *= (x-xi[j]);
        }
        resultado +=produto;
    
    }

 


    return resultado;
}




