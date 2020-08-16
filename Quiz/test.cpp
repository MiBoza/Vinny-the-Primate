#include <iostream>
using namespace std;

template <class T>
class list{
public:
    T x;
    int* len = 0;
    list* begin;
    list* next;
    list* prev;
    list** current;

    void make(T a){
        list New;
        New.x = a;
        *New.len = 1;
        New.begin = &New;
        *(New.current) = &New;
    }
    void push(T a){
        list New;
        New.x = a;
        New.begin = begin;
        New.prev = prev;
        New.next = begin;
        New.current = current;
        prev->next = &New;
        prev = &New;
        *current = &New;
    }
    T pop(){
        T temp = (*current)->x;
        (*current)->prev->next = (*current)->next;
        (*current)->next->prev = (*current)->prev;
        delete (*current);
    }
};

int main(){
    list<int> L;
    L.make(1);

    cout<<"L[0] = "<<(*L.current)->x<<"\n";
    cout<<"L.len = "<<*L.len<<"\n";

    return 0;}
