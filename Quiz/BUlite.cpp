#include <iostream>

int main(){
    system("cp /home/kurogawa/Desktop/Programming/Backup1/Size.bin /home/kurogawa/Desktop/Programming/Backup2");
    system("cp /home/kurogawa/Desktop/Programming/Backup1/Vocab.txt /home/kurogawa/Desktop/Programming/Backup2");
    system("cp /home/kurogawa/Desktop/Programming/GTK/Size.bin /home/kurogawa/Desktop/Programming/Backup1");
    system("cp /home/kurogawa/Desktop/Programming/GTK/Vocab.txt /home/kurogawa/Desktop/Programming/Backup1");

    std::cout<<"cp /home/kurogawa/Desktop/Programming/Backup1/(Size.bin + Vocab.txt) /home/kurogawa/Desktop/Programming/Backup2\n";
    std::cout<<"cp /home/kurogawa/Desktop/Programming/GTK/(Size.bin + Vocab.txt) /home/kurogawa/Desktop/Programming/Backup1\n";

    return 0;}
