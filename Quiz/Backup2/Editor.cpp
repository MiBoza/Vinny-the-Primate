#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream A;
    ofstream B;
    char file[20];
    int write;

    cout<<"File name: "; cin>>file;
    cout<<"Content to write: "; cin>>write;

    B.open(file, ios::in | ios::binary | ios::trunc);
    B.write((char*)&write, 4);
    B.close();

    write = 1785;
    A.open(file, ios::binary | ios::in);
    A.read((char*)&write, 4);
    cout<<"Content = "<<write<<"\n";
    A.close();

    return 0;
}
