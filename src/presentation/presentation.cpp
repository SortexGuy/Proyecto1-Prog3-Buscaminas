#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "negotiation/negotiation.hpp"

class Presentation {
private:
    ftxui::ScreenInteractive game_screen;
    ftxui::Element game_content;
public:
    Presentation(std::vector<std::vector<CellState>> state);

    ~Presentation();
};

Presentation::Presentation(std::vector<std::vector<CellState>> state) {
    game_screen = ftxui::ScreenInteractive::Fullscreen();

    auto rows;
    for(std::vector<CellState> row : state) {
        ftxui::Elements collumns;
        for(CellState collumn : row) {
            auto pix = ftxui::Pixel();
            if (std::get<0>(collumn) == CellVState::Flagged) {
                pix.character = 'F';
            } else if (std::get<0>(collumn) == CellVState::Hidden) {
                pix.character = '#';
            } else {
                pix.character = ' ';
            }
            collumns.push_back(pix);
        }
        
    }
    
    game_content = ftxui::hbox();
    ftxui::Box mine_box = ftxui::Box();
}

Presentation::~Presentation() {
}
