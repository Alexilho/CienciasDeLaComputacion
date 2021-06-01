#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

void ejecutable();
void mergeSort(int*, int);
void mergeLists(int*, int, int*, int, int*);
void print(int*, int);

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
    do {
       ejecutable();
    } while(true);
    return 0;
}

void ejecutable() {
     int n;
     int ranX;
     do {
        cout<<"entrada: "; cin>>n;
        if(n <= 0) cout<<"Debe ingresar un valor  mayor a cero "<<endl;
     } while(n <= 0);
        
     int arr[n];
     cout<<"lista: "<<endl;
     for(int i = 0; i < n; i++) {
     	ranX= rand()%500;
        arr[i] = ranX - i;
        cout<<arr[i]<<"   "; 
     }
     
     Start(); mergeSort(arr, n); Stop();
     cout<<endl<<"lista ordenada: "<<endl; print(arr, n);
     cout<<endl<<"tiempo: "<<double(li.QuadPart-CounterStart)/PCFreq<<" milisegundos"<<endl;
     cout<<endl; system("pause");
     system("cls");
}

void mergeSort(int vector[], int n) {
    int *vector1, *vector2, n1, n2, x, y;
    if (n>1) {
        if (n%2 == 0) n1 = n2 = (int) n / 2;
        else {
            n1 =(int) n / 2;
            n2 = n1 + 1;
        }
        vector1 = (int *) malloc(sizeof(int)*n1);
        vector2 = (int *) malloc(sizeof(int)*n2);
        for(x = 0; x < n1; x++) vector1[x] = vector[x];
        for(y = 0;y < n2; x++, y++) vector2[y] = vector[x];
        mergeSort(vector1, n1);
        mergeSort(vector2, n2);
        mergeLists(vector1, n1, vector2, n2, vector);
        free(vector1);
        free(vector2);
    }
}

void mergeLists(int arreglo1[], int n1, int arreglo2[], int n2, int arreglo3[]) {
    int x1 = 0, x2 = 0, x3 = 0;
    while (x1 < n1 && x2 < n2) {
        if (arreglo1[x1] < arreglo2[x2]) {
            arreglo3[x3] = arreglo1[x1];
            x1++;
        } else {
            arreglo3[x3] = arreglo2[x2];
            x2++;
        }
        x3++;
    }
    while (x1 < n1) {
        arreglo3[x3] = arreglo1[x1];
        x1++; x3++;
    }
    while (x2 < n2) {
        arreglo3[x3] = arreglo2[x2];
        x2++; x3++;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] <<"   ";
}
