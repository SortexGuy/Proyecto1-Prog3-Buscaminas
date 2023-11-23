#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"
#include "ftxui/component/component.hpp"

class Presentation {
private:
    // ftxui::ScreenInteractive game_screen;
    ftxui::Element game_content;
public:
    
    Presentation();
    Presentation();
};

Presentation::Presentation(/* args */) {
    game_content = ftxui::vbox({
        ftxui::hbox()
    });
    ftxui::Box mine_box = ftxui::Box();
}

Presentation::~Presentation() {
}
