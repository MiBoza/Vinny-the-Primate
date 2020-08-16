#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

const double pi = 3.14159265358979323846264338327950288419716939937510582097494459230781;

const double e  = 2.71828182845904523536028747135266249775724709369;

const int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

/*
double abs(double x, double y = 0){
	if(x < 0){x *= -1;}
	return x;
}*/

int round(double x){
	if(x < 0){return (int)(x-0.499999999);}
	else{return (int)(x+0.499999999);}
	}

/*
int floor(double x){
	if(x < 0){return (int)(x-0.999999999);}
	else{return (int)(x);}
}
*/
	
int ceil(double x){
	if(x < 0){return (int)x;}	
	else{return (int)(x+0.999999999);}}

/*
double mod(double a, double b){
	int x = floor(a/b);
	return a - x*b;
}
*/

double Ipow(double x, int y){
	if(y == 0){return 1;}
	if(y == 1){return x;}
	if(y < 0){return 1/Ipow(x, -1*y);}
	
	double result = x;
	int index = 15;
	int p = 32768;
	
	for(int i = 1; i < 15; i++){
		if(3*pow2[i-1] > y){
			index = i;
			p = pow2[i];
			break;}
	}
	
	for(int i = 0; i < index; i++){
		result *= result;}
		
	return result*Ipow(x, y-p);
}

/*double stod(string s){
	if(s[0] == '-'){return -1*stod(s.substr(1));}
	
	double floaty = 0;
	int l = s.length();
	int p = s.find('.');
	if(p == -1){p = l;}
	double d = Ipow(10, p-1);
	char c;
	
	for(int i = 0; i < l; i++){
		if(i == p){continue;}
		c = s[i];
		floaty += (c - 48)*d;
		d /= 10;}
	
	return floaty;
}*/

double cos(double x){
	if(x < -1*pi || x > pi){return cos(mod(x + pi, 2*pi) - pi);}
	if(x < 0){return cos(-1*x);}
	if(x > pi/2){return -1*cos(pi-x);}
	
	double xmpiq = x - pi/4;
	double factor = 1;
	double poly = 1;
	double cos = 0;
	short sign = 1;
	bool s1 = 1;
	
	for(int i = 1; i <= 8; i++){
		cos += sign*poly/factor;
		poly *= xmpiq;
		factor *= i;
		if(s1){sign *= -1;}
		s1 = !s1;
	}
	
	return 0.7071067811865*cos;
}

double sin(double x){
	return cos(x - pi/2);}

double tan(double x){
	return sin(x)/cos(x);}

double Simpson(Matrix* L, float a, float b){
	if((*L->sizev) != 1){
		cerr<<"Matrix must be single row to integrate\n";
		exit(1);}
	int n = (*L->sizeh)-1;
	L = L->beginh->next;
	double result = L->x;
	for(int i = 3; i < n; i += 2){
		L = L->next->next;
		result += L->x;
		}
	result *= 2;
	L = L->Move(0, 2);
	result += L->x;
	for(int i = 4; i < n; i += 2){
		L = L->next->next;
		result += L->x;
		}
	
	result *= 2;
	result += L->next->next->x + L->beginh->x;
	cout<<"result = "<<result<<"\n";
	result *= (b-a)/3/n;
	cout<<"a = "<<a<<"; b = "<<b<<"\n";
	return result;
}

const double itn[] = {0.7853981634, 1.446441332, 1.555172598, 1.568843204, 1.570552186, 1.570765809, 1.570792511, 1.570795850};

/*
double itan(double x){
	if(x < 0){return -1*itan(-1*x);}

	Matrix* L;
	double x1, result, h, temp;	

	x1 = x/2;
	int temp = 0;
	while(x1 > 1){
		x1 /= 8;
		count += 1;}
	
	if(count > 7){count = 7;}
	result = itn[count];
	
	x1 = Ipow(2, 3*temp);
	temp = x1;
	h = (x-x1)/10;
	L = L->Make(1/(1+x1*x1));
	
	for(int i = 1; i <= 10; i++){
		x1 += h;
		L = L->Push(1/(1+x1*x1));
		}
	
	L->Print();
	
	return result + Simpson(L, temp, x);;
}*/

double nroot(double a, int n = 2, double tol = 0.00000000001, double guess = 1){
	double x0, x1, z;
	x1 = guess;
	for(int i = 0; i < 100; i++){
		z = Ipow(x1, n-1);
		x0 = (x1*z - a)/n/z;
		x1 -= x0;
		if(abs(x0) < tol){break;}
	}
	return x1;
}

double epow(double x){
	int c = round(x);
	if(abs(c-x) < 0.00001){return Ipow(e, c);}
	
	double xmc = x - c;
	double factor = 1;
	double poly = 1;
	double ex = 0;
	
	for(int i = 0; i < 8; i++){
		ex += poly/factor;
		poly *= xmc;
		factor *= i+1;
	}
	ex = Ipow(e, c)*ex;
	
	return ex;
	}

double ln(double x){
	double a = (1+x)/2;
	double b = nroot(x);
	
	for(int i = 1; i < 20; i++){
		a = (a+b)/2;
		b = nroot(a*b);
		if(abs(a-b) < 0.000001){break;}
	}
	return 2*(x-1)/(a+b);
}

const double ln10 = ln(10);


double log(double x, double base = 10){
	if(base == 10){return ln(x)/ln10;}
	else{return ln(x)/ln(base);}
}

double pow(double x, double y){
	return epow(ln(x)*y);
}
