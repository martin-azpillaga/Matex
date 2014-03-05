#include<stdio.h>
#include<stdlib.h>
#include<math.h>



//Equidistants: h = (b-a)/2         xi = a * i*h amb i=0,..,n

//Txevitxev xi = A + (b-a)/2 * ( 1 + cos( (2i+1)/n+1 * pi/2)
//M_PI


double horner(double z,double *x, double *c, int n);

int difdiv(double *x, double *f, int n,double tol);

void nodes(int n, double a, double b, double *x);

double fun(double z);

int main(void){

   	double a, *x, b, *f, tol, k, max, max_1, zj;
   	int n, i, j, coef;

	
	tol = 1e-12;
	
	printf("#Digues la dimensio \n");
	scanf("%d",&n);
	
	
	
	printf("# a=?, b=? \n");
	scanf("%le %le",&a, &b);

	//Direccionar memoria x i f de n+1

	x = (double *)malloc( (n+1)*sizeof(double) );
	
	f  = (double *)malloc( (n+1)*sizeof(double) );


    //Calculem les absises dinterpolacio
	nodes(n,a,b,x);
	
    //omplim f. fi = fun(xi)
    for(i=0;i<n+1;i++){
                       f[i] = fun(x[i]);
    }
    
    //Calculem els coeficients del polinomi interpolador i es guarden a f, de manera que c[0]=f[0]
    coef = difdiv(x,f,n,tol);
    
    if(coef==-1){
                 printf("#No s'ha pogut calcular els coeficients del polinomi");
                 return 0;
                 
    //Fins aqui tot el k em fet era x calcular el pol interpolador
    }else{
          //Calculem lerror=max
          k = (b - a)/999;
          max_1 = -1;
          for(j=0;j<1000;j++){
                              zj = a + (j * k);
			      printf("%+.8le %+.8le %+.8le \n", zj,fun(zj),horner(zj,x,f,n));
                              max = fabs(fun(zj) - horner(zj,x,f,n));
                              if(max > max_1){
                                     max_1 = max;
                              }                              
          }
          
          //Resultat: max error 
          printf("#L'error maxim comes en el proces d'interpolacio es %le", max_1);
          

	      return 0;
    }

}

double horner(double z, double *x, double *f, int n){//No utilitzem c no?? els c son els fi no?

	double p;
	int i;

	p = f[n];
	
	for(i=n-1;i>=0;i--){
		p = p * (z - x[i]) + f[i];
	}
	return p;

}

int difdiv(double *x, double *f, int n, double tol){

	int i, k;
	double denom;

	
	for(k=1;k<n+1;k++){
	  for(i=n;i>=k;i--){
	    denom = x[i] - x[i-k];
	    if(fabs(denom)<tol){
	      return -1;
	    
	    }else{
	      f[i] = (f[i] - f[i-1])/denom;
	    }
	  }
	}
	
	return 0;	
}	


void nodes(int n, double a, double b, double *x){ //Obtenim les absises
     
     int i;
     
     for(i=0;i<n+1;i++){
                      //x[i] = a + (1./2 * (b-a) * (1 + cos(((2.*i +1.)/(n+1))*M_PI/2)));
		      x[i]= a + (b-a)*(double)i/n;
     }    

}

double fun(double z){//Obtenim les f(z)

       double f;
       
       f = sin(z);
       
       return f;      
}
	
