#include <iostream>
#include "Sculptor.hpp"

using namespace std;

int main(void){
    int i, j;
    Sculptor nintendo(30, 10, 50);
    
    nintendo.setColor(0.9, 0.9, 0.9, 1);
    nintendo.putbox(0, 28, 0, 5, 0, 49);
    nintendo.cutEllipsoid(-2, 3, -2, 4, 10, 4);
    nintendo.putbox(1, 1, 0, 5, 3, 3);
    nintendo.putbox(3, 3, 0, 5, 1, 1);

    nintendo.setColor(0.5, 0.5, 0.5, 1);
    nintendo.putbox(1, 27, 5, 5, 30, 47);

    nintendo.setColor(0.9, 0.9, 0.9, 1);
    j = 30;
    for (int n = 3; n >= 1; n--)
    {
        for (int i = 1; i <= n; i++)
        {
            nintendo.putVoxel(i, 5, j);
        }
        j++;
    }

    /**
     * GREEN SCREEN
     */
    nintendo.setColor(0.6, 0.7, 0.2, 0.7);
    nintendo.cutbox(4, 25, 5, 5, 33, 45);
    nintendo.putbox(4, 25, 4, 4, 33, 45);

    /**
     * BUTTONS
     */
    nintendo.setColor(0.9, 0.1, 0.2, 1);
    nintendo.putSphere(4, 5, 19, 2);
    nintendo.putSphere(8, 5, 16, 2);
    nintendo.cutVoxel(8, 7, 16);
    nintendo.cutVoxel(4, 7, 19);

    nintendo.setColor(0.9, 0.9, 0.9, 1);
    nintendo.putbox(1, 15, 5, 5, 8, 22);

    nintendo.setColor(0.5, 0.5, 0.5, 1);
    int aux = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            nintendo.putVoxel(11 + j + i, 6, 9 - i);
        }
        aux++;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            nintendo.putVoxel(17 + j + i, 6, 9 - i);
        }
        aux++;
    }
    nintendo.setColor(0, 0, 0, 1);
    nintendo.putbox(21, 22, 6, 6, 15, 20);
    nintendo.putbox(19, 24, 6, 6, 17, 18);

    /**
     * DETAILS
     */
    nintendo.setColor(0, 0, 0, 1);
    nintendo.putbox(27, 28, 2, 3, 38, 42);
    nintendo.putbox(28, 29, 2, 3, 39, 41);

    /**
     * WRITE NITENDO
     */
    i = -4;

    nintendo.setColor(1, 0, 0, 1);
    nintendo.putbox(20, 23, 0, 0, 48 + i, 48 + i);
    nintendo.putbox(21, 24, 0, 0, 42 + i, 42 + i);
    nintendo.putVoxel(24, 0, 47 + i);
    nintendo.putVoxel(23, 0, 46 + i);
    nintendo.putVoxel(22, 0, 45 + i);
    nintendo.putVoxel(21, 0, 44 + i);
    nintendo.putVoxel(20, 0, 43 + i);

    nintendo.putbox(20, 22, 0, 0, 40 + i, 40 + i);
    nintendo.putbox(24, 24, 0, 0, 40 + i, 40 + i);

    nintendo.putbox(20, 23, 0, 0, 38 + i, 38 + i);
    nintendo.putbox(22, 22, 0, 0, 37 + i, 37 + i);
    nintendo.putbox(23, 23, 0, 0, 35 + i, 36 + i);
    nintendo.putbox(20, 22, 0, 0, 34 + i, 34 + i);

    nintendo.putbox(20, 24, 0, 0, 31 + i, 31 + i);
    nintendo.putbox(23, 23, 0, 0, 30 + i, 32 + i);

    nintendo.putbox(21, 22, 0, 0, 29 + i, 29 + i);
    nintendo.putVoxel(23, 0, 28 + i);
    nintendo.putVoxel(23, 0, 25 + i);
    nintendo.putbox(20, 20, 0, 0, 25 + i, 28 + i);
    nintendo.putbox(22, 22, 0, 0, 26 + i, 27 + i);
    nintendo.putbox(24, 24, 0, 0, 26 + i, 27 + i);

    nintendo.putbox(20, 23, 0, 0, 23 + i, 23 + i);
    nintendo.putbox(22, 22, 0, 0, 22 + i, 22 + i);
    nintendo.putbox(23, 23, 0, 0, 20 + i, 21 + i);
    nintendo.putbox(20, 22, 0, 0, 19 + i, 19 + i);

    nintendo.putbox(21, 22, 0, 0, 17 + i, 17 + i);
    nintendo.putbox(20, 20, 0, 0, 15 + i, 16 + i);
    nintendo.putbox(23, 23, 0, 0, 15 + i, 16 + i);
    nintendo.putbox(21, 25, 0, 0, 14 + i, 14 + i);

    nintendo.putbox(21, 22, 0, 0, 12 + i, 12 + i);
    nintendo.putbox(20, 20, 0, 0, 10 + i, 11 + i);
    nintendo.putbox(23, 23, 0, 0, 10 + i, 11 + i);
    nintendo.putbox(21, 22, 0, 0, 9 + i, 9 + i);

    nintendo.writeOFF((char *)"nintendo.off");
}