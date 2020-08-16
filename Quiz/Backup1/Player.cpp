//g++ Player.cpp -o Player `pkg-config gtkmm-3.0 --libs --cflags`
#ifndef Example
#define Example

#include <gtkmm.h>
#include "quiz.h"

class Player : public Gtk::Window{
public:
    Player():
        VBox(Gtk::ORIENTATION_VERTICAL),
        HBox(Gtk::ORIENTATION_HORIZONTAL),
        prompt("Show answer?"){
        yes.set_label("Yes");
        no.set_label("No");
        no.set_sensitive(false);
        close.set_label("Save & Quit");

        set_title("Quiz Player");
        set_default_size(250, 150);
        set_border_width(10);
        add(VBox);

        Load(table, chosen);
        choice = Choose(table);
        tempy = table[choice.r];
        question.set_text(tempy.entry[choice.c]);

        yes.signal_clicked().connect( sigc::bind<bool>( sigc::mem_fun(*this, &Player::Press), 1) );
        no.signal_clicked().connect( sigc::bind<bool>( sigc::mem_fun(*this, &Player::Press), 0) );
        close.signal_clicked().connect( sigc::mem_fun(*this, &Player::Close) );


        VBox.pack_start(question);
        VBox.add(prompt);
        VBox.add(HBox);
        VBox.add(close);
        HBox.pack_start(no);
        HBox.add(yes);

        show_all_children();
    }

protected:
    //Signal handlers:

    void Press(bool right){
        if(state){
            table[choice.r].val = 0.8*tempy.val + 0.2*right;
            choice = Choose(table);
            tempy = table[choice.r];
            question.set_text(tempy.entry[choice.c]);
            prompt.set_text("Show answer?");
            no.set_sensitive(false);
            line = "";
            state = 0;}
        else{
            line = tempy.entry[0] + ", " + tempy.entry[1] + ", " + tempy.entry[2];
            question.set_text (line);
            prompt.set_text("Did you get it right?");
            no.set_sensitive(true);
            state = 1;}
    }

    void Close(){
        Save(table, chosen);
        hide();
    }

    //Child widgets:
    Gtk::Button yes;
    Gtk::Button no;
    Gtk::Button close;
    Gtk::Label question, prompt;
    Gtk::Box VBox;
    Gtk::Box HBox;

    //Variables
    float* a;
    bool state = 0;
    string line = "";
    vector<Row> table;
    vector<int> chosen;
    Choice choice;
    Row tempy;
};
#endif //Example

int main(int argc, char *argv[]){
  auto app = Gtk::Application::create(argc, argv);

  Player player;

  //Shows the window and returns when it is closed.
  return app->run(player);
}
