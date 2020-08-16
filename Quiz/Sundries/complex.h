#include <iostream>
#include "maths.h"
using namespace std;
// Remember to make the complex number: complex z; z.Make(a, b);

class complex{
	public:
		double a;
		double b;
		
		void Print(){
			if(a != 0){cout<<a<<" ";}
			if(b > 0){cout<<"+ "<<b<<"j\n";}
			if(b < 0){cout<<b<<"j\n";}
			}
		
		void Make(double ai, double bi){
			a = ai;
			b = bi;
			}
		
		complex operator*(const complex y){
			complex z;
			z.a = a*y.a - b*y.b;
			z.b = a*y.b + b*y.a;
			return z;}

		complex operator+(const complex y){
			complex z;
			z.a = a + y.a;
			z.b = b + y.b;
			return z;}
		
		complex operator-(const complex y){
			complex z;
			z.a = a - y.a;
			z.b = b - y.b;
			return z;}
		
		complex operator/(const complex y){
			complex z;
			if(y.a == 0 && y.b == 0){
				cerr<<"Attempt to divide by zero\n";
				exit(1);}
			z.a = (a*y.a + b*y.b)/(y.a*y.a + y.b*y.b);
			z.b = (b*y.a - a*y.b)/(y.a*y.a + y.b*y.b);
			return z;}
		
		double magnitude(){
			return nroot(Ipow(a, 2) + Ipow(b, 2));
		}
		
		double angle(){
			double angle = itan(b/a);
			if(this->a < 0){angle = mod(angle, 2*pi)-pi;}
			return angle;
		}
		
		void MakeP(double magnitude, double angle){
			a = magnitude*cos(angle);
			b = magnitude*sin(angle);
		}
		
		void PrintP(){
			cout<<this->magnitude()<<"<"<<180*this->angle()/pi<<"\n";
		}
};
