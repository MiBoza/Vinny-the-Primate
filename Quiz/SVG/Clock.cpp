#include <iostream>
#include <fstream>
//#include <string>
#include "/home/kurogawa/Desktop/Programming/maths.h"
//g++ -Wall -o Clock Clock.cpp
using namespace std;

//const double pi = 3.14159265358979323846264338327950288419716939937510582097494459230781;

int main () {
    ofstream A;

    string time;
    int hour, minute, second;
    float a, b;

    cout<<"Input time:\n"; cin>>time;

    hour    = int(stod(time.substr(0,2)));
    minute  = int(stod(time.substr(3,2)));
    second  = int(stod(time.substr(6,2)));

    A.open ("Clock.html");
    A << "<html>\n";
    A << "<body>\n";
    A << "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    A << "<circle cx=\"100\" cy=\"100\" r=\"90\" stroke=\"black\" fill=\"none\" stroke-width=\"2\" />\n";

    for(int i = 0; i < 12; i++){
        a = cos(pi*i/6);
        b = sin(pi*i/6);
        A << "<line x1=\""<<100+90*a<<"\" y1=\""<<100-90*b<<"\" x2=\""<<100+80*a<<"\" y2=\""<<100-80*b<<"\" stroke=\"black\" stroke-width=\"6\" />\n";}

    second = second + 60*minute + 3600*hour;

    //Hour Hand
    a = cos(pi*second/21600);
    b = sin(pi*second/21600);
    A << "<line x1=\"100\" y1=\"100\" x2=\""<<100+30*b<<"\" y2=\""<<100-30*a<<"\" stroke=\"black\" stroke-width=\"6\" />\n";

    //Minute Hand
    a = cos(pi*second/1800);
    b = sin(pi*second/1800);
    A << "<line x1=\"100\" y1=\"100\" x2=\""<<100+50*b<<"\" y2=\""<<100-50*a<<"\" stroke=\"black\" stroke-width=\"4\" />\n";

    //Second Hand
    a = cos(pi*second/30);
    b = sin(pi*second/30);
    A << "<line x1=\"100\" y1=\"100\" x2=\""<<100+70*b<<"\" y2=\""<<100-70*a<<"\" stroke=\"black\" stroke-width=\"2\" />\n";

    A << "</svg>\n";
    A << "</body>\n";
    A << "</html>\n";
    A.close();
    return 0;
}
