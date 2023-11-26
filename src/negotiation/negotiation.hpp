#ifndef __negotiation_included__
#define __negotiation_included__

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

#endif // !__negotiation_included__