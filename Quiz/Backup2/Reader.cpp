#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream A;
    char file[20];
    int read;

    cout<<"File name: "; cin>>file;

    A.open(file, ios::binary | ios::in);
    A.read((char*)&read, 4);
    cout<<"Content = "<<read<<"\n";
    A.close();

    return 0;
}
