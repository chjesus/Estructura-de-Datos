#include <iostream>
#include <vector>

using namespace std;
void imprimir(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
void insercionDirecta(vector<int> &v,int tam){
//	int inicio = 0,final = 0,cont = 0,aux = -999;
//	int mayor = -999;
//	for(int i=0;i<tam;i++){
//		if(v[i]<v[i+1]){
//			inicio = i-cont;
//			final = i+1;
//			cont++;
//		}else{
//
//				inicio = 0;
//				final = 0;
////				cont = 0;				
//			
//		}
//	}
//	inicio = cont;
//	for(int i = cont;i<tam;i++){
//		if(cont==0){
//			final = i;
//		}
//		cont--;
//	}
//	
//	cout<<"Inicio: "<<inicio<<endl;
//	cout<<"Final: "<<final<<endl;
	
	int auxiliar;
	int centro,izquierda,derecha;
    for (int k=1;k<tam;k++){
        auxiliar = v[k];
        izquierda = 0;
        derecha = k-1;
        while(izquierda <= derecha){
            centro = (int) ((izquierda + derecha)/2);
                if (auxiliar <= v[centro])
                    derecha = centro-1;
                else
                    izquierda = centro+1;
        }
        for (int i=k-1;i>=izquierda;i--)
            v[i+1] = v[i];
        v[izquierda] = auxiliar;
        
        imprimir(v);
        cout<<endl<<endl;
    }
}

int main(int argc, char** argv) {
	vector<int> vec;
	vec.push_back(6);
	vec.push_back(24);
	vec.push_back(12);
	vec.push_back(16);
	vec.push_back(20);
	vec.push_back(17);
	vec.push_back(10);
	vec.push_back(19);
	
	insercionDirecta(vec,vec.size());
//	imprimir(vec);
							
	return 0;
}
