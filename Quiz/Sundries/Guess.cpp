#include <iostream>
#include <bits/stdc++.h>    /* srand, rand */
#include <time.h>           /* time */
using namespace std;

int main(){
    int limit, guess;
    guess = 0;
    srand(time(NULL));
    cout<<"Guess the number I'm thinking\n";
    cout<<"What's the limit? "; cin>>limit;
    int thought = rand()%limit + 1;

    cout<<"What's your guess?\n";
    while(guess != thought){
        cin>>guess;
        if(guess < thought){
            cout<<"Too low ";}
        if(guess > thought){
            cout<<"Too high ";}
    }
    cout<<"You did it!\n";
    return 0;}
