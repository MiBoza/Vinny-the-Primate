//g++ -Wall -o TunePlayer TunePlayer.cpp 

#include<iostream>
#include "maths.h"
using namespace std;

int main(){
    double out[200];
    float A = 2;
    float omega = 0.01*pi;

    out[0] = A;
    cout<<out[0]<<" ";
    out[1] = A*cos(omega);
    cout<<out[1]<<" ";
    double tCos = 2*cos(omega);

    for(int i = 2; i < 201; i++){
    out[i] = tCos*out[i-1]-out[i-2];
    cout<<out[i]<<" ";}
    cout<<endl;
    cout<<2*cos(2*pi)<<endl;
return 0;}
