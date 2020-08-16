#include <iostream>
#include <fstream>
#include "list.h"
//g++ -Wall -o Test Test.cpp
using namespace std;

const int batchS = 5;
ifstream A;
ofstream B;

struct Row{
    string line, key;
};

ostream &operator<<(ostream &os, Row const &out){
    return os << out.key;}

void unique(list<Row> &mem){
    string line;
    for(int i = 0; i < mem.len; i++){
        line = mem[i].key;
        for(int j = i+1; j < mem.len; j++){
            if((i != j)&&(line == mem[j].key)){
                mem.pop();}
        }
    }
}

void compare(list<Row> &main, list<Row> &sub){
    for(int i = 0; i < main.len; i++){
        for(int j = 0; j < sub.len; j++){
            if(main[i].key == sub[j].key){
                cout<<"2, ";
                sub.pop();}
            }
        }
    }

bool fill(list<Row> &mem){
    int pos;
    int left = batchS - mem.len;
    bool runOut = 0;
    Row entry;
    list<Row> sub;

    while(left > 0){
        if(getline(A, entry.line)){
            pos = entry.line.find(',');
            entry.key = entry.line.substr(0, pos);
            sub.push(entry);
            left--;}
        else{
            runOut = 1;
            break;}
    }
    unique(sub);
    compare(mem, sub);
    mem.append(sub);
    if((mem.len < batchS) && !runOut){
        fill(mem);}
    return runOut;
}

bool in(list<Row> &mem, string key){
    for(int i = 0; i < mem.len; i++){
        if(mem[i].key == key){
            return 1;}
    }
    return 0;
}

int main(){
    list<Row> mem;
    Row entry;
    ofstream B, C;
    int pos;
    bool runOut = 0;


    while(!runOut){
        A.open("Vocab.txt");
        B.open("Done.txt", ios::app);

        runOut = fill(mem);
        for(int i = 0; i < mem.len; i++){
            B<<mem[i].line<<"\n";}

        C.open("Progress.txt", ios::trunc);
        while(getline(A, entry.line)){
            pos = entry.line.find(',');
            entry.key = entry.line.substr(0, pos);
            if(!in(mem, entry.key)){
                C<<entry.line<<"\n";}
        }
        A.close();
        B.close();
        C.close();
        system("mv Progress.txt Vocab.txt");
        mem.Clear();
    }
    B.close();
    system("mv Done.txt Vocab.txt");
    return 0;
}
