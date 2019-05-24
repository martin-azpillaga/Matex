
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#define PRE 1.e-12


//dif div:
      //k=1 de baix a dalt de 2 en 2
      //k=2 fins 2n+1 normal


int difdivherm(double *x, double *f, int n);
double horner(double z, double *x, double *c, int n);


int main(){
	
	int n, i, res;

	double *x,*f, q[2],h,z;
	
	/*dimension del polinomio*/
	printf("Donem el temany dels vectors");
	scanf("%d",&n);


//Direccionem memòria
	x = (double *)malloc( ((2*n) + 2)*sizeof(double) );
	f = (double *)malloc( ((2*n) + 2)*sizeof(double) );

//Demanem les dades
	printf("Donem les dades");
	for(i=0; i < n + 1; i++){
		scanf("%le %le %le", &x[2*i], &f[2*i], &f[2*i + 1]);
		x[2*i + 1] = x[2*i];
		
	}

	
	res = difdivherm(x, f, n);
    if(res==-1){
                 printf("#No s'ha pogut calcular els coeficients del polinomi");
                 return 0;
                 
  
    }else{
		
		z=horner(0.5, x, f, n*2+1);
		printf("z= %le ", z);
		
		for (i=0; i<(2*n) + 2; i++){
		  printf("\n %d   x=%lf  f=%lf", i, x[i], f[i]);
		}
		
	}



//Alliberem memòria

    free(x);
    free(f);
    
     
	return 0;
}


int difdivherm(double *x, double *f, int n){

	int i, k, m;
	m = 2*n + 1;
	

	for(i = m-1; i>=2; i = i - 2){
			if((x[i]-x[i-1])<PRE){
                return  -1;
				
			}
			f[i] = (f[i]-f[i-2])/(x[i]-x[i-1]);
	}

	for(k = 2; k < m+1; k++){
		for(i = m; i >= k; i--){
			if((x[i]-x[i-k])<PRE){
				return  -1;
			}
			f[i] = (f[i]-f[i-1])/(x[i]-x[i-k]);
		}
	}
	return 0;

}

double horner (double z, double *x, double *c, int n){
  double p;
  int i;
  p = c[n];

  for(i = n-1; i >= 0; i--) {
    p = p*(z - x[i]) + c[i];
  }
	
  return p;



}
