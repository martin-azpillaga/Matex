#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PRE 1.e-12


//k files
//i col

//Dh
//Dqh
//D(q2)h
//D(q(m-1))h

//entrada: 1,0,0.1,m=8,0.1(anar dividint entre 10)


double fun(double);
double dernum(int ind, double x, double h);
double extrapol(int p, double q, double fh, double fqh);

int main(){

	int ind, m, i, p, k;
	double x, h, q, **f;

	

	//Demanem les dades
	printf("Donem la apoximació voleu ultilitzar\n");
	scanf("%d", &ind);
	
	printf("Donem la abscissa\n");
	scanf("%le", &x);

	printf("Donem pas inicial de discretització\n");
	scanf("%le", &h);

		
	printf("Donem la quantitat d'aproximacio\n");
	scanf("%d", &m);

	printf("Donem el factor de variació de pas \n");
	scanf("%le", &q);

	//Reservem memoria
	f = (double **)malloc( m*sizeof(double *) );
	for(i = 0; i < m; i++){
		f[i] = (double *)malloc(m*sizeof(double) );
	}

	//Emplenam f_0
	
	for(i = 0; i < m; i++){
		
		f[i][0] = dernum(ind, x, h);
		h = h * q;
		printf("f_0=%le \n", f[i][0]);	
	}
	
	//Emplanem f_i
	for(i = 1; i < m; i++){
		printf("Donem la p%d \n",i);
		scanf("%d", &p);

	
		for(k = 0; k < m-i; k++){
			f[k][i] = extrapol(p, q, f[k][i-1], f[k + 1][i-1]);
			printf("f_ %d  "  "%le \n",i,f[k][i]);
		
		}
	}

    getch();
	return 0;
}

double fun(double x){
	return cos(x);
	// exp(c)
	
}

double dernum(int ind, double x, double h){

	double sol;

	switch (ind){

	case 1 :
		sol = (fun(x + h) - fun(x))/h;
		break;
	case 2 :
		sol = (fun(x + h) - fun(x - h))/(2*h);
		break;

	case 3 :
		sol = (fun(x - h) - (2* fun(x)) + fun(x + h))/ (h*h);
	
		break;
	default :
		
		break;
	}

	return sol;

}

/* q és la constant per la que es va dividint el pas h
 * p és el exponent del primer terme de l'error
 * Aquesta funció fa UN pas d'extrapolació per a qualsevol metode
 */

double extrapol(int p, double q, double fh, double fqh){

	return (((pow(q,p)*fh) -fqh))/(pow(q,p) - 1);

}
