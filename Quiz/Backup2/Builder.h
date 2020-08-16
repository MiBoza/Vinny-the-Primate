#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void Count(int influx){
    ifstream A;
    ofstream B;
    int prev;

    A.open("Size.bin", ios::binary | ios::in);
    A.read((char*)&prev, 4);
    A.close();

    influx += prev;
    B.open("Size.bin", ios::in | ios::binary | ios::trunc);
    B.write((char*)&influx, 4);
    B.close();
}

int Prep(){
    float val = 0;
    string line;
    int pos, count;
    ifstream A;
    ofstream B;
    A.open("Vocab.txt");
    B.open("Vocab2.txt", ios::trunc);    

    getline(A, line);
    count = 1;
    pos = line.find('.')-1;
    val = stof(line.substr(pos));
    while(val < 0.3){
        B<<line<<"\n";
        getline(A, line);
        count += 1;
        pos = line.find('.')-1;
        val = stof(line.substr(pos));
        }
    A.close();
    B.close();

    return count-1;
}

void Build(string line){
    ofstream B;
    B.open("Vocab2.txt", ios::in | ios::app);

    B<<line;
    B.close();
}

void scootL(string* mem, int start){
    for(int i = start; i < 3; i ++){
        mem[i] = mem[i+1];}
}

void scootR(string* mem){
    for(int i = 3; i > 0; i--){
        mem[i] = mem[i-1];}
}

void del(string* mem, bool* goof, int &capacity){
    if(goof[3]){
        capacity = 3;
        mem[3] = "";}
    for(int i = 2; i >= 0; i--){
        if(goof[i]){
            capacity--;
            scootL(mem, i);
        }
    }
}

void Save(int count){
    ifstream A;
    ofstream B;
    string line;

    A.open("Vocab.txt");
    for(int i = 0; i < count; i++){
        getline(A, line);}

    B.open("Vocab2.txt", ofstream::app);
    while(getline(A, line)){
        B<<line<<"\n";}
    B.close();

    system("mv Vocab2.txt Vocab.txt");
    }
