#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
   int Npuntos;
   double  **puntos= nullptr;
   while(scanf("%d", &Npuntos) && Npuntos){
           puntos = new double *[Npuntos];
           for (int i = 0; i < Npuntos; i++) {
               puntos[i] = new double [2];
           }
           double x,y,resultado = 10000;
           for (int j = 0; j <Npuntos ; ++j) {
               cin>>x>>y;
               puntos[j][0] = x;
               puntos[j][1] =y;
           }
           for (int k = 0; k < Npuntos-1; ++k) {
               for (int i = k+1; i < Npuntos ; ++i) {
                   double n1 = abs(puntos[k][0]-puntos[i][0]);
                   double n2 = abs(puntos[k][1]-puntos[i][1]);
                   double dist = sqrt(n1*n1+ n2*n2);
                   if(dist<resultado){
                       resultado = dist;
                   }
               }
           }
           delete []puntos;
           if (resultado==10000){
               cout<<"INFINITY"<<endl;
           }else printf("%.4lf\n", resultado);
   }
}