#include <iostream>
#include "LinkedList.h"
#include "maths.h"
using namespace std;
// Remember to make the fraction: frac* a = new frac;

List* primeF(int x){
	List* listy = listy->Make();
	int limit;
	bool found;
	
	while(x > 1){
		limit = ceil(nroot(x, 2, 0.1));
		found = 0;
		for(int i = 2; i < limit; i++){
			if(mod(x, i) == 0){
				listy = listy->Push(i);
				x /= i;
				found = 1;
				break;}
		}
		
		if(!found){
			listy = listy->Push(x);
			x = 1;}
	}
	return listy->begin;
}

class frac{
	public:
		int num;
		int den;
		
		void print(){cout<<this->num<<"/"<<this->den;}
		
		frac Make(int num, int den){
			frac A;
			A.num = num;
			A.den = den;
			return A;}
		
		frac operator*(const frac f){
			frac A;
			A.num = num*f.num;
			A.den = den*f.den;
			return A;}

		frac operator+(const frac f){
			frac A;
			A.num = num*f.den+den*f.num;
			A.den = den*f.den;
			return A;}
		
		frac operator-(const frac f){
			frac A;
			A.num = num*f.den-den*f.num;
			A.den = den*f.den;
			return A;}
		
		frac operator/(const frac f){
			frac A;
			A.num = num*f.den;
			A.den = den*f.num;
			return A;}
		
		double decimal(){
			double x = num/den;
			return x;
		}
		
		void simplify(){
			List* a;
			List* b;
			bool sign;
			
			if((this->num < 0) && (this->den >= 0) || (this->num >= 0) && (this->den < 0)){sign = 0;}
			else{sign = 1;}
			this->num = abs(this->num);
			this->den = abs(this->den);
			
			a = primeF(this->num);
			b = primeF(this->den);
			
			while(a->next){
				a = a->next;
				while(b->next){
					b = b->next;
					if(a->x == b->x){
						a = a->Pop();
						b = b->Pop();
						break;}
				}
				b = b->begin;
			}
			a = a->begin;
			
			this->num = 2*sign-1;
			this->den = 1;
			while(a->next){
				a = a->next;
				this->num *= a->x;}
			
			while(b->next){
				b = b->next;
				this->den *= b->x;}
		}
		
};
