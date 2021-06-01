#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void quickSort(int*, int, int);
void intercambio(int*, int, int);

double PCFreq = 0.0;
__int64 CounterStart = 0;
LARGE_INTEGER li;

void Start() {
     LARGE_INTEGER m;
     if(!QueryPerformanceFrequency(&m))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(m.QuadPart)/1000;

    QueryPerformanceCounter(&m);
    CounterStart = m.QuadPart;
}

void Stop() {
    QueryPerformanceCounter(&li);
}

int main(int argc, char** argv) {
    int arraySize;
    int ranX;
	srand(time(NULL));
    do {
       do {
            cout<<"entrada: ";cin>>arraySize;
            if(arraySize<=0) 
                 cout<<"Debe ingresar un valor  mayor a cero "<<endl;
        } while(arraySize<=0);
        
        int A[arraySize];
        for(int i=0;i<arraySize;i++) {
            ranX = rand()%1001;
			A[i]=ranX;
			ranX =0; 
            cout<<A[i]<<"   ";
        }
        Start(); 
        quickSort(A, 0, arraySize - 1);
        Stop();        
        cout<<endl<<"lista ordenada"<<endl;
        for(int i=0;i<arraySize ;i++) {
             cout<<A[i]<<"   ";
        }        
        cout<<endl<<"tiempo: "<<double(li.QuadPart-CounterStart)/PCFreq<<" milisegundos"<<endl;
	    system("pause");
        system("cls");        
    } while(true);
}

void intercambio(int b[], int min, int j){
     int v=b[j];
     b[j]=b[min];
     b[min]=v;
}

void quickSort(int a[], int izq, int der){
     int i, j, v;
     if (der> izq) {
        v= a[der]; i = izq -1; j= der;
        for(;;) {
           while (a[++i]<v);
           while (a[--j] >v);
           if(i>=j) break;
           intercambio(a,i,j);
        }
        intercambio(a, i, der);
        quickSort(a, izq, i-1);
        quickSort(a, i+1,der);
     }
}


