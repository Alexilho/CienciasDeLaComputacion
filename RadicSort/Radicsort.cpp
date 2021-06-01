#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

int getMax(int*, int);
void countSort(int*, int, int);
int unsigned bits (int x, int k, int j);
void intercambio(char a[], int i, int j);
void base(int*, int);
void print(int*, int);
void ejecutable();

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

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


    int inline unsigned bits (int x, int k, int j)
    {return (x>>k)&~(~0<<j);}


void intercambio(char a[], int i, int j){
	int temp;
	temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

void ejecutable() {
		
     int n;
     do {
        cout<<"entrada: "; cin>>n;
        if(n <= 0) cout<<"Debe ingresar un valor  mayor a cero "<<endl;
     } while(n <= 0);
        
     int arr[n];
     char s;
     cout<<"lista: "<<endl;
     for(int i = 0; i < n; i++) {
        arr[i]= 65 + rand() % (99 - 1);
        s=i;
        cout<<arr[s]<<"   "; 
     }
    
     int a = sizeof(arr)/sizeof(arr[0]);
	Start(); base(arr, a); Stop();
     cout<<endl<<"lista ordenada: "<<endl; print(arr, a);
     cout<<endl<<"tiempo: "<<double(li.QuadPart-CounterStart)/PCFreq<<" milisegundos"<<endl;
     cout<<endl; system("pause");
     system("cls");
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {  
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void base(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
    
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] <<"   ";
}
