#include <cstdlib>
#include <inttypes.h>
#include <vector>
#include <tuple>

enum CellVState {
    Hidden,
    Flagged,
    Unhidden,
};
typedef std::tuple<CellVState, bool> CellState;

class Negotiation {
private:
    std::vector<std::vector<CellState>> cells_state;
public:
    Negotiation();
    ~Negotiation();
};

Negotiation::Negotiation() {
    int16_t max_mines = 12;
    for (size_t i = 0; i < 8; i++) {
        std::vector<CellState> collumn;
        for (size_t j = 0; j < 8; j++) {
            bool curr_bombing = false;
            if (std::rand()%100 >= 60) {
                curr_bombing = true;
                max_mines--;
            }

            collumn.push_back(std::make_tuple(CellVState::Hidden, curr_bombing));
        }
        cells_state.push_back(collumn);
    }
}

Negotiation::~Negotiation() {
}
