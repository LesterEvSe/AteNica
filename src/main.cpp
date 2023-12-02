#include "rays.hpp"
#include "board.hpp"
#include "movepicker.hpp"
#include "pst.hpp"
#include "eval.hpp"
#include "search.hpp"

int main() {
    init_bits_pre_calculation(); // Must be at the beginning!
    Rays::init();
    Attacks::init(); // Must be init after Rays
    MovePicker::init();
    ZobristHash::init();
    PieceTables::init();
    Eval::init();

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dist(0, std::numeric_limits<uint64_t>::max());

    std::vector<uint64_t> nums(1'000'000);
    for (uint64_t i = 0; i < nums.size(); ++i)
        nums[i] = dist(gen);

    init();
    auto start_time = std::chrono::steady_clock::now();
    check(count_bits_popcount, nums);
    auto end_time1 = std::chrono::steady_clock::now();
    check(count_bits_my_func, nums);
    auto end_time2 = std::chrono::steady_clock::now();
    check(count_bits, nums);
    auto end_time3 = std::chrono::steady_clock::now();

    auto duration_popcount = std::chrono::duration_cast<std::chrono::milliseconds>(end_time1 - start_time);
    auto duration_my_func = std::chrono::duration_cast<std::chrono::milliseconds>(end_time2 - end_time1);
    auto duration_my_func_better = std::chrono::duration_cast<std::chrono::milliseconds>(end_time3 - end_time2);

    std::cout << "popcount: " << duration_popcount << std::endl;
    std::cout << "my_count (old): " << duration_my_func << std::endl;
    std::cout << "my_count (new): " << duration_my_func_better << std::endl;

    return 0;
}
