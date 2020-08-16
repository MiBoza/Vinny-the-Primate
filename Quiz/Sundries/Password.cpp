//g++ -Wall -o Password Password.cpp
#include<iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main(){
int length;
char c;
int num;
bool bank;
srand (time(NULL));

cout<<"Choose password layout:\n";
cout<<"1. BN\n";
cout<<"0. Other\n";
cin>>bank;

cout<<"Enter desired length of password: "; cin>> length;

if(!bank){
    bool use;
    int capacity = 0;
    int list[94];
    int LConsonants[] = {98, 99, 100, 102, 103, 104, 106, 107, 108, 109, 110, 112, 113, 114, 115, 116, 118, 119, 120, 121, 122};
    int LVowels[] = {97, 101, 105, 111, 117};
    int UConsonants[] = {66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90};
    int UVowels[] = {65, 69, 73, 79, 85};
    int Numbers[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    int Symbols[] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125};

    cout<<"Choose sets of characters to use.\n Enter 1 to use set or 0 to exclude it.\n";

    cout<<"Use Lowercase Consonants? "; cin>>use;
    if(use){
        for(int i = 0; i < 21; i++){
            list[capacity + i] = LConsonants[i];}
        capacity = 21;}

    cout<<"Use Lowercase Vowels? "; cin>>use;
    if(use){
        for(int i = 0; i < 5; i++){
            list[capacity + i] = LVowels[i];}
        capacity += 5;}

    cout<<"Use Uppercase Consonants? "; cin>>use;
    if(use){
        for(int i = 0; i < 21; i++){
        list[capacity + i] = UConsonants[i];}
        capacity += 21;}

    cout<<"Use Uppercase Vowels? "; cin>>use;
    if(use){
        for(int i = 0; i < 5; i++){
        list[capacity + i] = UVowels[i];}
        capacity += 5;}

    cout<<"Use Numbers? "; cin>>use;
    if(use){
        for(int i = 0; i < 10; i++){
        list[capacity + i] = Numbers[i];}
        capacity += 10;}

    cout<<"Use Symbols? "; cin>>use;
    if(use){
        for(int i = 0; i < 32; i++){
        list[capacity + i] = Symbols[i];}
        capacity += 32;}

    cout<<"\n";

    cout<<"capacity = "<<capacity<<"\n";
    for (int i = 0; i < length; i++){
        num = rand()%capacity;
        c = list[num];
        cout<<c;}
    cout<<"\n";
}
///////////////////////////////////////////////////

if(bank){

int List[] = {66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90, 98, 99, 100, 102, 103, 104, 106, 107, 108, 109, 110, 112, 113, 114, 115, 116, 118, 119, 120, 121, 122, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125};

int prev;

num = rand()%84;
c = num;
cout<<c;

for(int i = 0; i < length; i ++){
    prev = num;
    num = rand()%83;
    if(prev >= num){
        num += 1;}
    c = List[num];
    cout<<c;
    }
}
cout<<"\n\n";
return 0;}
