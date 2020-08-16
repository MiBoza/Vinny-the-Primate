#include <iostream>
using namespace std;
//g++ -Wall -o Undupe Undupe.cpp

template <class T>
class List{
public:
    T x;
    List<T>* next;
    List<T>* prev;

    void Make(T a){
        x = a;}

    List* push(T a){
        List<T>* New = new List<T>;
        New->x = a;
        New->prev = this;
        this->next = New;
        return New;}
};

template <class T>
class list{
protected:
    int pos;
    List<T>* A = new List<T>;
    List<T>* begin, *end;

    void Navigate(int i){
        if((i < 0) || (i > len)){
            cout<<"Error: Trying to index outside of array";
            exit(1);}
        int P = pos;
        while(P < i){
            A = A->next;
            P++;}
        while(P > i){
            A = A->prev;
            P--;}
        pos = P;
    }
public:
    int len = 0;

    void print(){
	    List<T>* B = begin;
	    for(int i = 1; i < len; i++){
		    cout<<B->x<<", ";
		    B = B->next;}
        cout<<B->x<<"\n";}

    void push(T a){
        if(len == 0){
            A->Make(a);
            begin = end = A;
            len = 1;
            pos = 0;}
        else{
            end = end->push(a);
            len++;}
    }

    T pop(int i = -1){
        if(i != -1){Navigate(i);}
        List<T>* pointer = A;
        T val = pointer->x;

        if(pointer == end){
                A = A->prev;
                pos--;
                end = A;}
        else{
            A = A->next;
            if(pointer == begin){
                begin = A;}            
            else{
                pointer->prev->next = pointer->next;
                pointer->next->prev = pointer->prev;}
        }

        len--;
        delete pointer;
        return val;}

    void append(list B){
        if(len == 0){
            *this = B;}
        else{
            if(B.len != 0){
                B.begin->prev = end;
                end->next = B.begin;
                end = B.end;
                len += B.len;}
            }
        }

	T operator[](int i){
        Navigate(i);
		return A->x;}

    void Clear(){
        if(len != 0){
            A = begin;
            while(A != end){
                A = A->next;
                delete A->prev;}
            delete A;
            len = 0;}
    }
};
