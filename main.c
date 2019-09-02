#include "futo.h"

void comparison_init(Comparison *comparison, int lesser_y, int lesser_x,
                     int greater_y, int greater_x);

int main()
{
    Square sq = square_init(4);
    int solved = false;
    sq[2][0] = 2;

    Comparison cs[5];
    comparison_init(&cs[0], 1, 0, 1, 1);
    comparison_init(&cs[1], 1, 3, 2, 3);
    comparison_init(&cs[2], 2, 2, 3, 2);
    comparison_init(&cs[3], 2, 3, 3, 3);
    comparison_init(&cs[4], -1, -1, -1, -1);

    solve(sq, cs, &solved);
    square_destroy(sq);

}

void comparison_init(Comparison *comparison, int lesser_y, int lesser_x,
                     int greater_y, int greater_x)
{
    comparison->index_lesser[0] = lesser_y;
    comparison->index_lesser[1] = lesser_x;
    comparison->index_greater[0] = greater_y;
    comparison->index_greater[1] = greater_x;
}
