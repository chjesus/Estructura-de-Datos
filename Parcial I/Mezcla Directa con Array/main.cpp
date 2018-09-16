#include <iostream>
 
using namespace std;
 
void mezclar(int arreglo1[], int n1, int arreglo2[], int n2, int arreglo3[]);
void mezcla(int vector[], int n);
  
int main(){
 
    int vector[]={2,3,5,7,2,6,1,5,8,3,2};
 
    cout << "Lista desordenada\n";
  
    for(int i=0;i<11;i++){
        cout<<vector[i]<<" ";  	
	}
    mezcla(vector,11);
    cout<<"\n";
    cout<<"Lista ordenada\n";
  
    for(int i=0;i<11;i++){
        cout<<vector[i]<<" "; 
	}
    cout<<"\n";
    return 0;
}
 
void mezclar(int arreglo1[],int n1,int arreglo2[],int n2,int arreglo3[]){
 
    int x1=0,x2=0,x3=0;
  
    while (x1<n1 && x2<n2) {
        if (arreglo1[x1]<arreglo2[x2]) {
            arreglo3[x3]=arreglo1[x1];
            x1++;
        }else {
            arreglo3[x3]=arreglo2[x2];
            x2++;
        }
    x3++;
    }
 
    while(x1<n1){
        arreglo3[x3]=arreglo1[x1];
        x1++;
        x3++;
    }
 
    while(x2<n2) {
        arreglo3[x3]=arreglo2[x2];
        x2++;
        x3++;
    }
}
 
void mezcla(int vector[],int n){
 
    int *vector1,*vector2,n1,n2,x,y;
 
    if(n>1) {
	    if(n%2==0){
	        n1=n2=(int)n/2;   	
		}else{
	        n1=(int)n/2; 
			n2=n1+1;
	    }
	    vector1 = new int[n1];
	    vector2 = new int[n2];

	        for(x = 0; x < n1; x++){
	            vector1[x] = vector[x];
			}
	        for(y=0; y < n2; x++, y++){
	            vector2[y] = vector[x];
			}
	        mezcla(vector1,n1);
	        mezcla(vector2,n2);
	        mezclar(vector1,n1,vector2,n2,vector);
			 
	        delete vector1;
	        delete vector2;
    }    
}
