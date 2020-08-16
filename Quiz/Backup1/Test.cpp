#include <iostream>
#include <vector>
#include <string>
//g++ -Wall -o Test Test.cpp
using namespace std;

struct Row{
    string entry[3];
    float val;
};

int main(){
    vector<Row> table;

    table =    {{"一理ある", "いちりある", "to have a point", 0.3}, 
                {"禁物", "きんもつ", "Restriction", 0.3}, 
                {"裏", "うら", "Back", 0.3}, 
                {"潜める", "ひそめる", "to conceal", 0.3}, 
                {"蒸し返す", "むしかえす", "to reheat", 0.3}, 
                {"事象", "じしょう", "Event", 0.3}, 
                {"絡む", "からむ", "to entangle", 0.3}, 
                {"裏切り", "うらぎり", "Treason", 0.3}, 
                {"早口言葉", "はやくちことば", "Tongue Twister", 0.44}, 
                {"効果", "こうか", "Effect", 0.44}};

    cout<<"table[3].entry[0] = "<<table[3].entry[0]<<"\n";

    return 0;
}
