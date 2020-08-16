#include<iostream>
using namespace std;

void Parabola(float x1, float y1, float x2, float y2, float x3, float y3, float ans[])
{
float dom1 = (x1 - x2)*(x1 - x3);
float dom2 = (x2 - x1)*(x2 - x3);
float dom3 = (x3 - x1)*(x3 - x2);

ans[0]= y1/dom1 + y2/dom2 + y3/dom3;
ans[1] = (x2 + x3)*y1/dom1 + (x1 + x3)*y2/dom2 + (x1 + x2)*y3/dom3;
ans[1] *= -1;
ans[2] = y1*x2*x3/dom1 + x1*y2*x3/dom2 + x1*x2*y3/dom3;
}


int main(){
float x1, x2, x3, y1, y2, y3;
cout<<"Enter points of parabola: (x1, y1); (x2, y2); (x3, y3) "<<endl;
cout<<"x1: "; cin>>x1;
cout<<"y1: "; cin>>y1;
cout<<"x2: "; cin>>x2;
cout<<"y2: "; cin>>y2;
cout<<"x3: "; cin>>x3;
cout<<"y3: "; cin>>y3;

float ans [3];
Parabola(x1, y1, x2, y2, x3, y3, ans);
cout<<"P(x) = "<<ans[0]<<"x^2 + "<<ans[1]<<"x + "<<ans[2]<<endl;

return 0;}
