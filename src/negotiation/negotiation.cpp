#include "negotiation.hpp"

class Negotiation {
private:
    std::vector<std::vector<CellState>> cells_state;
public:
    Negotiation();
    std::vector<std::vector<CellState>> get_cells_state();
    ~Negotiation();
};

Negotiation::Negotiation() {
    int16_t max_mines = 12, max_size = 8;

    for (size_t i = 0; i < max_size; i++) {
        std::vector<CellState> collumn;
        for (size_t j = 0; j < max_size; j++) {
            bool curr_bombing = false;
            int randi = std::rand() % 100;
            if (randi >= 60 && max_mines > 0) {
                curr_bombing = true;
                max_mines--;
            }
            CellVState curr_visual = CellVState::Hidden;
            // --- Debug ---
            if (randi%33 >= 20) {
                curr_visual = CellVState::Unhidden;
            } else if (randi%55 >= 20) {
                curr_visual = CellVState::Flagged;
            }
            // --- Debug ---

            collumn.push_back(std::make_tuple(curr_visual, curr_bombing));
        }
        cells_state.push_back(collumn);
    }
}

std::vector<std::vector<CellState>> Negotiation::get_cells_state() {
    return cells_state;
}

Negotiation::~Negotiation() {
}
