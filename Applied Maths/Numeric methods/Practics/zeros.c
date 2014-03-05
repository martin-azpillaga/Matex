#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define tol 1e-7

double biseccio( double a ,double b, double precision );
double f( double x );

int main()
{
    double zero = biseccion(-100,100,1e-4);
    
    printf("zero : %.4g" , zero );
    
    return 0;
}

double biseccio( double a, double b, double precision)
{
       double c = (b-a)/2;
       
       if( fabs( b-a ) < precision )
       {
           return c;
       }
       
       if( f(c) *f(a) <= 0 )
       {
           biseccio( a , c , precision );
       }
       else
       {
           biseccio( c , b , precision);
       }
           
}

double f( double x )
{
       return x*x;
}