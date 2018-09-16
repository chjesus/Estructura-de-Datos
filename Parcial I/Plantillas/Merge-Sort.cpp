#include <iostream>
# define sufpeq 5
using namespace std;
/* Hecho por David Ortiz */

void inter(int &A, int &B){
	int aux=A;
	A=B;
	B=aux;
}

void seledir(int v[], int n){
	int men, pmen, i, j;
	for(int j=1; j<n; j++){		
		men=v[j-1];
		pmen=j-1;
		for(int i=j;i<n;i++){		
			if(v[i] < men){
				men=v[i];
				pmen=i;
			}
		}
		if(pmen != j-1) inter(v[j-1],v[pmen]);
	}//fin de ciclo de fases
}

void imprimir(int v[],int n){
	
	for(int i=0;i<n;i++){
	
	cout<<" "<<v[i]<<" ";		
	}
	cout<<endl;
}

void Partir( int v[], int *x1, int *x2, int n)
{
	int i;
	for (i=0; i<n/2; i++)  x1[i]= v[i];
	for (;i<n; i++)        x2[i-n/2]=v[i];
}

void Fusion(int *x1, int *x2, int *v, int n)
{
	int i,j,k;
	i=j=k=0;
	for (;k<n;k++)
	{
	 if ( i==n/2 && j<n-n/2)
	 {
	    v[k]= x2[j];
	    j++;
     }
     else if ( j==n-n/2 && i<n/2)
	 {
	    v[k]= x1[i];
	    i++;
     }
	  else if (  i<n/2 && j<n-n/2 && x1[i]<x2[j] )
	 { 
	   v[k]=x1[i];
	   i++;
	 }
	 else
	 {
	   v[k]=x2[j];
	   j++;
	 }
    }//fin for k
}

void MergeSort( int v[], int n)
{
	if (n<=sufpeq)
	   seledir(v,n);
	else 
	{
		int *x1, *x2;
		x1= new int[n/2];
		x2= new int [n-n/2];
		Partir(v,x1,x2,n);
		MergeSort(x1,n/2);
		MergeSort(x2,n-n/2);
		imprimir(x1,n/2);
		imprimir(x2,n-n/2);
		Fusion (x1,x2,v,n);
	}
}

int main(int argc, char** argv) {
int v[]= {34,56,11,19,20,21,31,40,18,4,65,22,44,55,86,76,45};
	MergeSort(v,sizeof(v)/sizeof(int));
	imprimir(v,sizeof(v)/sizeof(int));
	return 0;
}
