#include "rays.hpp"
#include "board.hpp"
#include "movepicker.hpp"
#include "piece_square_tables.hpp"
#include "eval.hpp"

int main() {
    Rays::init();
    Attacks::init(); // Must be init after Rays
    MovePicker::init();
    ZobristHash::init();
    PieceTables::init();
    Eval::init();

    return 0;
}
