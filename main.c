#include "futo.h"

void comparison_init(Comparison *comparison, int lesser_y, int lesser_x,
                     int greater_y, int greater_x);

int main()
{
    Square *sq = square_init(6);
    int solved = false;
    sq->self[2][2] = 5;
    sq->self[4][4] = 2;
    sq->self[4][5] = 6;
    sq->self[5][5] = 1;

    Comparison cs[11];
    comparison_init(&cs[0], 0, 1, 0, 2);
    comparison_init(&cs[1], 2, 1, 2, 0);
    comparison_init(&cs[2], 0, 5, 0, 4);
    comparison_init(&cs[3], 2, 5, 2, 4);
    comparison_init(&cs[4], 3, 1, 2, 1);
    comparison_init(&cs[5], 3, 0, 4, 0);
    comparison_init(&cs[6], 4, 0, 4, 1);
    comparison_init(&cs[7], 3, 3, 3, 2);
    comparison_init(&cs[8], 3, 4, 3, 3);
    comparison_init(&cs[9], 3, 5, 2, 5);
    comparison_init(&cs[10], -1, -1, -1, -1);

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
