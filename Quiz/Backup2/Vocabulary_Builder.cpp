#include "Window.h"
#include <gtkmm/application.h>

//g++ main.cpp -o main `pkg-config gtkmm-3.0 --libs --cflags`
int main(int argc, char *argv[]){
  auto app = Gtk::Application::create(argc, argv);

  Buttons buttons;

  //Shows the window and returns when it is closed.
  return app->run(buttons);
}
