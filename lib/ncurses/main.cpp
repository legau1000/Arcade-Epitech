#include "include/Ncurses.hpp"

int main()
{
    Ncurses nc;
    char *str = {"XXXXXXXXXX\nX         X\nXXXXXXXXXX"};

    while (1) {
        nc.drawAsset(str);
        nc.drawWindow();
    }    
}