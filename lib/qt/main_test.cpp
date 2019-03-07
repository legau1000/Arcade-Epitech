#include <string>
#include <iostream>
#include "include/qt.hpp"

int main(int ac, char**av)
{
    int index = 0;

    IDisplayModule *nneqt = new qt;
    printf("OUI\n");
    while (1) {
        if (index % 10 == 0)
            nneqt->getType();
        index++;
    }
    return (0);
}