#ifndef Example
#define Example

#include <gtkmm.h>
#include "Builder.h"

string prompts[] = {"Kanji:", "Kana:", "Translation:"};

//g++ Vocabulary_Builder.cpp -o Vocabulary_Builder `pkg-config gtkmm-3.0 --libs --cflags`
class Buttons : public Gtk::Window{
public:
    Buttons():
        VBox(Gtk::ORIENTATION_VERTICAL),
        HBox(Gtk::ORIENTATION_HORIZONTAL),
        H2Box(Gtk::ORIENTATION_HORIZONTAL),
        label("Kanji:"),
        chk1("1"), chk2("2"), chk3("3"), chk4("4"){
        ok.set_label("Ok");
        oops.set_label("Oops");
        close.set_label("Save & quit");

        set_title("Vocabulary Builder");
        set_default_size(250, 150);
        set_border_width(10);
        add(VBox);

        count = Prep();

        ok.signal_clicked().connect( sigc::mem_fun(*this,
                  &Buttons::Ok) );
        oops.signal_clicked().connect( sigc::mem_fun(*this,
                  &Buttons::Oops) );
        close.signal_clicked().connect( sigc::mem_fun(*this,
                  &Buttons::Close) );

        entry.set_text("Enter text");
        entry.select_region(0, 50);
        VBox.pack_start(label);
        VBox.add(entry);
        VBox.add(HBox);
        VBox.add(H2Box);
        HBox.pack_start(close);
        HBox.add(oops);
        HBox.add(ok);
        H2Box.pack_start(chk1);
        H2Box.add(chk2);
        H2Box.add(chk3);
        H2Box.add(chk4);

        show_all_children();
        H2Box.set_visible(0);
    }

protected:
    //Signal handlers:
    void Ok(){
        if(entry.get_text() == ""){
            line += " , ";}
        else{
            line += entry.get_text() + ", ";
            entry.set_text("");}

        if(state == 2){
            state = 0;
            label.set_text(prompts[state]);
            if(capacity < 4){
                capacity++;}
            else{
                influx++;
                Build(mem[3].append("0.3\n"));}
            scootR(mem);
            mem[0] = line;
            line = "";
        }
        else{
            state++;
            label.set_text(prompts[state]);}
        }

    void Oops(){
        if(state == 3){
            //Delete
            state = 0;
            label.set_text(prompts[state]);
            ok.set_sensitive(true);
            goof[0] = chk1.get_active(); goof[1] = chk2.get_active(); goof[2] = chk3.get_active(); goof[3] = chk4.get_active();
            chk1.set_active(0); chk2.set_active(0); chk3.set_active(0); chk4.set_active(0);
            H2Box.set_visible(0);
            del(mem, goof, capacity);
            line = "";
            oops.set_label("Oops");
            close.set_label("Save & Quit");}
        else{
            //Oops
            state = 3;
            oops.set_label("Delete");
            close.set_label("Nevermind");
            ok.set_sensitive(false);
            line = "1. " + mem[0] + "\n2. " + mem[1] + "\n3. " + mem[2] + "\n4. " + mem[3];
            label.set_text(line);
            H2Box.set_visible(1);}
    }

    void Close(){
        if(state == 3){
            //Nevermind
            state = 0;
            label.set_text(prompts[state]);
            line = "";
            oops.set_label("Oops");
            close.set_label("Save & Quit");
            ok.set_sensitive(true);
            H2Box.set_visible(0);}
        else{
            //Save & Quit
            Count(influx + capacity);
            for(int i = 0; i < capacity; i++){
                Build(mem[i].append("0.3\n"));}
            Save(count);
            hide();}
    }

    //Child widgets:
    Gtk::Button ok, close, oops;
    Gtk::Entry entry;
    Gtk::Label label;
    Gtk::Box VBox, HBox, H2Box;
    Gtk::CheckButton chk1, chk2, chk3, chk4;

    //Variables
    int count;
    int state = 0;
    int influx = 0;
    int capacity = 0;
    bool goof[4];
    string mem[4];
    string line = "";
};


#endif //Example
