#ifndef ATENICA_MOVEPICKER_HPP
#define ATENICA_MOVEPICKER_HPP

#include "move_list.hpp"

class MovePicker {
private:
    MoveList &m_move_list;
    uint8_t m_curr_node; // First unpicked move

    // MVV - Most Valuable Victim
    // LVA - Least Valuable Attacker
    static uint8_t m_mvv_lva[PIECE_SIZE - 1][PIECE_SIZE];
    static constexpr int32_t CAPTURE_BONUS = 2000;
    static constexpr int32_t PROMOTION_BONUS = 1000;

public:
    static void init();

    explicit MovePicker(MoveList *move_list);
    [[nodiscard]] bool has_next() const;
    const Move &get_next(); // Using selection sorting in place, O(n) at a time
};

#endif //ATENICA_MOVEPICKER_HPP
