#include <fstream>           //files
#include <string>
#include <bits/stdc++.h>    /* srand, rand */
#include <time.h>           /* time */
#include <iostream>
#include <vector>
using namespace std;

const int sampleSize = 128;
const int constantSize = 20;
int save = 0;
ofstream B;

struct Row { 
    string entry[3];
    float val;
};

struct Choice { 
    int r, c;
};

void Save(vector<Row> &table, int table_it){
    if(save == 0){
        B.open("Vocab2.txt", ios::app);}
    if(save == sampleSize){
        B.close();
        B.open("Vocab2.txt", ios::app);
        save = 0;}
    B << table[table_it].entry[0] << ", "<< table[table_it].entry[1] << ", "<< table[table_it].entry[2] << ", " << table[table_it].val <<"\n";
    save++;
}

void Save(string line){
    if(save == 0){
        B.open("Vocab2.txt", ios::app);}
    if(save == sampleSize){
        B.close();
        B.open("Vocab2.txt", ios::app);
        save = 0;}

    B << line <<"\n";
    save++;
}

bool compare(Row r1, Row r2){
    return (r1.val < r2.val); }

int mod(int a, int b){
	int x = (int)(a/b);
	return a - x*b;
}

int readL(){
    ifstream A;
    int l;

    A.open("Size.bin", ios::binary | ios::in);
    A.read((char*)&l, 4);
    A.close();
    return l;}

void Load(vector<Row> &table, vector<int> &chosen){
    int l = readL();
    ifstream A;
    string line;
    int count, pos, prev;
    Row tempy;
    srand(time(NULL));

    //vector of chosen lines
    for(int i = 0; i < l; i++)
        chosen.push_back(i);
    random_shuffle(&(chosen[constantSize]), &(chosen[l]));
    sort(&(chosen[constantSize]), &(chosen[sampleSize]));

    A.open("Vocab.txt");
    count = 0;

    //loading chosen lines into table
    if(A.is_open()){
        for(int i = 0; i < l; i++){
            getline(A, line);
            if(count == sampleSize){break;}
            if(i != chosen[count]){
                continue;}

            pos = line.find(',');
            tempy.entry[0] = line.substr(0, pos);

            prev = pos+2;
            pos = line.find(',', prev);
            tempy.entry[1] = line.substr(prev, pos-prev);

            prev = pos+2;
            pos = line.find(',', prev);
            tempy.entry[2] = line.substr(prev, pos-prev);

            tempy.val = stof(line.substr(pos+2));
            table.push_back(tempy);

            count++;
            }
        A.close();
    }
    else{
        cout<<"Unable to open file";}
}

Choice Choose(vector<Row> &table){
    int r, c;
    srand(time(NULL));

    r = rand()%sampleSize;
    c = rand()%3;

    if(table[r].entry[c] == " "){
        c = mod(c+1, 3);
        }

    Choice choice = {r, c};
    return choice;}
    
void Save(vector<Row> &table, vector<int> &chosen){
    sort(&(table[0]), &(table[sampleSize]), compare);

    int chosen_it, table_it, file_it;
    chosen_it = file_it = constantSize;
    table_it = 0;
    int pos;
    float val;
    ifstream A;

    A.open("Vocab.txt");
    string line;

    //the constant lines are already taken into consideration
    //Their file versions are outdated.
    for(int i = 0; i < constantSize; i++){
        getline(A, line);
    }

    //merge table and the rest of the file
    while(getline(A, line)){
        if((chosen_it < sampleSize) && (file_it == chosen[chosen_it])){
            chosen_it++;
            file_it++;
            continue;}

        pos = line.find('.')-1;
        val = stof(line.substr(pos));
        while((table_it < sampleSize) && (table[table_it].val <= val)){
            Save(table, table_it);
            table_it++;
        }
        Save(line);
        file_it++;
    }

    while(table_it < sampleSize){
        Save(table, table_it);
        table_it++;}

    A.close();
    B.close();
    system("mv Vocab2.txt Vocab.txt");
}
