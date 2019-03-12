#include "include/Ncurses.hpp"

int main()
{
    displayModule::Ncurses nc;
    int index = 0;
    int x = 0;
    int y = 0;
    char print[2];
    char *str = {"XXXXXXXXXX\nX        X\nXXXXXXXXXX"};

    print[1] = '\0';
    // while (1) {
        while (str[index]) {
            print[0] = str[index];
            if (str[index] == '\n') {
                y++;
                x = 0;
            } else {
                nc.drawAsset(print, x, y);
                nc.drawWindow();
                x++;
            }
            index++;
        }
        index = 0;
        x = 0;
        y = 0;
        while (1);
    // }
}