#include "futo.h"

void comparison_init(Comparison *comparison, int lesser_y, int lesser_x,
                     int greater_y, int greater_x);

int main()
{
    Square sq = square_init(4);
    int solved = false;
    sq[0][0] = 4;
    sq[0][3] = 2;
    sq[1][1] = 1;
    sq[3][3] = 4;

    Comparison cs[1];
    comparison_init(cs, 0, 0, 0, 1);

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
