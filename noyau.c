#include <stdio.h>
#include<math.h>

float f(float x, float teta){
    float func,pi = 3.141592653589793;
    func = (1 - x * cos(teta))/pow((1-2*x*cos(teta)+x*x),1.5);
    return func;

}

float K(float x){
    float teta, pi = 3.141592653589793;
    float a=1e-5, b=pi,alpha=0,beta=0,Isim;
    int k,n=1000;
    float h=(b-a)/n;

	for(k=1; k<=n/2; k=k+1){
		alpha=alpha+f(x,a+(2*k-1)*h);
	}

	for(k=1; k<=(n/2-1); k=k+1){
			beta=beta+f(x,a+2*k*h);
	}
	
	Isim=h/3*(f(x,a)+4*alpha +2*beta + f(x,b));

	return 1/pi*Isim;
}

float g(float r_prime, float r){
    float gunc,pi = 3.141592653589793, sigma=1e10, rc=1, x= r_prime/r;
    gunc = sigma/pow(1+(r_prime/rc)*(r_prime/rc),1.5)*r_prime*K(x);
    return gunc;
}

float Meff(float r){
    float teta, pi = 3.141592653589793, rc=1;
    float a=0.001, b=30,alpha=0,beta=0,Isim;
    int k,n=1000;
    float h=(b-a)/n;

	for(k=1; k<=n/2; k=k+1){
		alpha=alpha+g(a+(2*k-1)*h, r);
	}

	for(k=1; k<=(n/2-1); k=k+1){
			beta=beta+g(a+2*k*h, r);
	}
	
	Isim=h/3*(g(a, r)+4*alpha +2*beta + g(b, r));

	return 2*pi*Isim;
}

float v(float r){
    float G = 4.3e-6 ;
    return sqrt(G*Meff(r)/r);
}

float vkt_exact(float r){
    float G = 4.3e-6, rc=1, pi=3.141592653589793, sigma=1e10;
    float Mtot=2*pi*sigma*rc*rc;
    return sqrt(G*Mtot/rc*((r/rc)*(r/rc))/pow(1+(r/rc)*(r/rc),1.5));

}

int main(){
    FILE *fich;
	fich = fopen("noyau.csv","w");
	float x;
    int n;
    for ( x = 0.05; x < 3; x += 0.1){
        fprintf(fich, "%f %f\n", x,K(x));
    }
    fclose(fich);

    FILE *fich2;
	fich2 = fopen("vitesse.csv","w");
	float r;
    for ( r = 0.1; r < 10; r += 0.1){
        fprintf(fich2, "%f %f %f\n", r,v(r),vkt_exact(r));
    }
    fclose(fich2);
}