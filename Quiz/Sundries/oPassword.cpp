//g++ -Wall -o Password Password.cpp
#include<iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main(){
bool bank;
cout<<"Choose Bank:"<<endl;
cout<<"0. BCR"<<endl;
cout<<"1. BN"<<endl;
cin>>bank;

srand (time(NULL));
int l;
char c;

if(!bank){
l = rand()%4 + 8;

for(int i = 0; i<l; i++){
c = rand() % 74 + 46;
if(c == 47){c = 44;}
if(c > 57){c += 7;}
if(c > 90){c += 6;}
if(c > 122){c -= 75;}
cout<<c;}
cout<<endl<<endl;}

if(bank){
l = rand()%5 + 8;
char temp [12];
bool anygood = 0;
int yet = 2;
int adjust = 0;

while(!anygood){

for(int i = 0; i<4; i++){
temp[i] = rand()%10 + 48;}

for(int i = 4; i<l; i++){
if(yet == 0){adjust = 12;}
temp[i] = rand() % (52+adjust) + 58-adjust;
if(temp[i] == 47){temp[i] = 44;}
if(temp[i] > 57){temp[i] += 7;}
if(temp[i] > 90){temp[i] += 6;}
if(yet > 0){yet -= 1;}}

c = 0;
for(int i = 0; i<l; i++){
yet = rand()%l;
while(temp[yet] == 0){yet = (yet+1)%l;}
if(c == temp[yet]){break;}
if(i+1 == l){anygood = 1;}
c = temp[yet];
cout<<c;
temp[yet] = 0;
}
cout<<endl<<endl;}}


return 0;}

