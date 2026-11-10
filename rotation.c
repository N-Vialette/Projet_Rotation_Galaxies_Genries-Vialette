#include <stdio.h>
#include<math.h>

float Vexp(float r){
    float G = 4.3e-6, sigma = 1e10, rc = 1, pi = 3.141592653589793;
    return sqrt(2*pi*G*sigma*rc*rc*(1-exp(-r/rc)*(1+r/rc))/r);
}

float Vgauss(float r){
    float G = 4.3e-6, sigma = 1e10, rc = 1, pi = 3.141592653589793;
    return sqrt(2*pi*G*sigma*rc*rc*(1-exp(-r*r/(2*rc*rc)))/r);
}

float Vkt(float r){
    float G = 4.3e-6, sigma = 1e10,  rc = 1, pi = 3.141592653589793;
    return sqrt(2*pi*G*sigma*rc*rc*(1-1/sqrt(1+r*r/rc*rc))/r);
}

float Vt(float r, int n){
    float G = 4.3e-6, sigma = 1e10, rc = 1, pi = 3.141592653589793;
    return sqrt(2*pi*G*sigma*rc*rc*(1-pow(1+(r*r)/(2*n-1)*rc*rc, -n+0.5))/r);
}

int main(){
    FILE *fich;
	fich = fopen("Approx_gauss.csv","w");
	float r;
    int n;
    for ( r = 0.1; r < 24; r += 0.1){
        fprintf(fich, "%f %f %f %f %f\n", r, Vexp(r), Vgauss(r), Vkt(r), Vt(r, 2));
    }


}