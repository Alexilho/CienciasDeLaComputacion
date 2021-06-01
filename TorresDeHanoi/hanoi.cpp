#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace::std;

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


void Mover_Torres(int N, int Origen, int Intermedio, int Destino)

{ 

if ( N > 1 )

{ 
Mover_Torres( N - 1, Origen, Destino, Intermedio);




Mover_Torres( N - 1, Intermedio, Origen, Destino);
} 





} 

int main()

{ 
int Discos;
cin >> Discos;
Start();
Mover_Torres( Discos, 1, 2, 3);
Stop();
cout<<endl<<"tiempo: "<<double(li.QuadPart-CounterStart)/PCFreq<<" milisegundos"<<endl;

cout << endl << endl;

return 0;

} 
