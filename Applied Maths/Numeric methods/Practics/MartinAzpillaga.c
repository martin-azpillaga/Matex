#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define niub 14944926
#define longniub 8
#define dim  4
#define tol 10e-10

void buildMatrix( double** );
void print( double** );
int indmaxabs( double**, int );
int palu( double** , int* );
void separate( double** , double** );
double det( double** );
void solveU( double** , double* );
void solveL( double** , double* );
void permute( int* , double* );
void solve( int , double** , double**, int*, double*);
void invert( double** , double** , int*);

int main()
{
  
  double** A;
  double** U;
  double* b;
  int* P;
  int i,m;
  
  A = (double**) malloc( dim*sizeof(double*));
  U = (double**) malloc( dim*sizeof(double*));
  
  for( i=0; i < dim ; i++)
  {
    A[i] = (double*) malloc( dim*sizeof(double));
    U[i] = (double*) malloc( dim*sizeof(double));
  }
  
  b = (double*) malloc( dim*sizeof(double));
  
  b[0] = 1;
  b[1] = 2;
  b[2] = 3;
  b[3] = 4;
  
  P = (int*) malloc( dim*sizeof(int) );
  
  P[0] = 0;
  P[1] = 1;
  P[2] = 2;
  P[3] = 3;
  
  buildMatrix( A );
  
  print( A );
  
  /* hay un error de ejecucion en la descomposicion palu de A */ 
  /*palu( A , P );*/
  
  separate( A , U );
  
  printf("det( A ) : %g", det(U) );
  
  printf("Introduce el m deseado ( m >= 1 ): ");
  scanf("%d",&m);
  
  /* hay un bucle infinito al intentar resolver el sistema */
  solve( m , A , U , P , b );
  
  for( i=0 ; i < dim ; i++ )
  {
       printf("%g ", b[i]);
  }
  
  invert( A , U , P );

  print( A );
  
  free(A);
  free(b);
  free(P);
  
  return 0;
}

void buildMatrix( double** A )
{
  
  int S,Q,i;
  double R;
  int figures, f, row, col;
  
  S = 1;
  Q = 0;
  figures = niub;
  
  for( i=0 ; i < longniub ; i++ )
  {
    f = ( figures % 10 );
    figures /= 10;
    
    S += f;
    Q += pow(f,2);
    
    row = i/dim;
    col = i%dim;

    A[dim/2-1-row][dim-1-col]=f;
    A[dim/2+row][col] = f;
  }
  
  R = (1.*Q)/S;
  
  for( i=0 ; i < dim ; i++ )
  {
    A[i][i] += R;
  }
}

void print( double** A )
{
  int i,j;
  for( i=0 ; i < dim ; i++ )
  {
    for( j=0 ; j < dim ; j++ )
    {
      printf("%6g ",A[i][j]);
    }
    printf("\n");
  }
}

int pivot( double **A, int k)
{
	int res, row;
    double max;
		
	max = abs(A[k][k]);
	
	for ( row = k+1 ; row < dim ; row++ )
    {
		if(abs( A[row][k] ) > max)
        {
			max = abs( A[row][k] );
			res = row;
		}
	}
    	
	if (max < tol){
		res = -1;
	}
	
	return res;
}

int palu( double** A, int* P )
{ 
	int row, col, k, parity, aux;

	parity = 1;

	for( k=0 ; k < dim-1 ; k++)
    {
		row = pivot( A , k );
	
		if (row == -1)
        {
			return 1;
		
        }else{		
			
            for( col = 0 ; col < dim ; col++ )
            {
                 aux = A[k][col];
                 A[k][col] = A[row][col];
                 A[row][col] = aux;
            }
            
		    aux = P[k];
			P[k] = P[row];
			P[row] = aux;

	        parity *= -1;
		
			
			for( row = k + 1; row < dim ; row++ )
            {
				A[row][k] = A[row][k]/A[k][k];
				
                for( col = k + 1 ; col < dim ; col++ )
                {
					A[row][col] = A[row][col] - A[row][k]*A[k][col];
				}
			}
		} 
	}
	
	return parity;

}

void separate( double** A , double** U )
{
     int row,col;
     
     for( row=0 ; row < dim; row++ )
     {
          for( col=0 ; col < dim; col++ )
          {
               if( col >= row )
               {
                   U[row][col] = A[row][col];
                   A[row][col] = 0;
               }
               else
               {
                   U[row][col] = 0;
               }
          }
     }
     
     for( row=0 ; row < dim ; row++ )
     {
          A[row][row] = 1;
     }
}
                    
double det( double** A )
{
       int i;
       double res = 1;
       
       for( i=0 ; i < dim ; i++)
       {
            res *= A[i][i];
       }
       
       return res;
}

void solveU(double** U, double* b)
{
  int row, col;
  
  b[dim-1] = b[dim-1]/U[dim-1][dim-1];
  
  for ( row=dim-2 ; row>=0 ; row--)
  {
    for ( col=row+1 ; col<dim; col++)
    {
      b[row] -= U[row][col]*b[col];
    }  
    b[row] /= U[row][row];
  }
}

void solveL(double** L, double* b)
{
  int row, col;
  
  for ( row=1 ; row < dim ; row++ )
  {
    for ( col=row-1 ; col >= 0 ; col--)
    {
      b[row] -= L[row][col]*b[col];
    }
  }
}

void permute( int* P , double* b )
{
     double aux;
     int i;
     int row;
     
     for( i=0 ; i < dim ; i++ )
     {
          row = P[i];
          aux = b[i];
          b[i] = b[row];
          b[row] = aux;
     }
}

void solve( int m, double** L, double** U, int* P, double* b)
{
     while( m > 0 )
     {
            permute( P , b );
            solveL( L , b );
            solveU( U , b );

            m -= 1;
     }
}

void invert( double** L , double** U , int* P )
{
     double** A;
     int i,j;
     double* b;
     
     A = (double**) malloc( dim*sizeof(double*));
     
     for( i=0; i < dim ; i++)
     {
          A[i] = (double*) malloc( dim*sizeof(double));
     }
  
     b = (double*) malloc( dim*sizeof(double));
     
     for( i=0 ; i < dim ; i++ )
     {
          for( j=0 ; j < dim ; j++ )
          {
               if( j== i)
               {
                   b[j] = i;
               }
               else
               {
                   b[j] = 0;
               }
          }
          permute( P , b );
          solveL( L , b );
          solveU( U , b );
          
          for( j=0; j< dim; j++ )
          {
               A[j][i] = b[j];
          }
     }
}