#include "futo.h"

int main()
{
    Square sq = init_square(4);
    int solved = FALSE;
    sq[0][0] = 4;
    sq[0][3] = 2;
    sq[1][1] = 1;
    sq[3][3] = 4;
    solve(sq, &solved);


    destroy_square(sq);

}
