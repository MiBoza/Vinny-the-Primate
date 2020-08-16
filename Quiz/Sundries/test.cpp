#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    List* listy = new List;
    listy = listy->Make();
    for(int i = 1; i <= 10; i++){
        listy = listy->Push(i);}
    listy->Print();

    return 0;}
