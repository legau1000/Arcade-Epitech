/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <string>
#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    clear();
    initscr();
    nodelay(stdscr, true);
    noecho();
    curs_set(0);
}

Ncurses::~Ncurses()
{
    endwin();
}

e_type Ncurses::getType()
{
    return (ONE);
}

void *Ncurses::createAsset(std::string &path)
{}

void Ncurses::drawAsset(void *sprite)
{
    mvprintw(1, 47, (char*)sprite);
}

void Ncurses::destroyAsset(void *sprite)
{}

void Ncurses::drawWindow()
{
    refresh();
}

void Ncurses::catchEvent()
{}

void Ncurses::start_sound() 
{}

void Ncurses::stop_sound()
{}


// void Ncurses::displayWallpaper()
// {
//     clear();
//     initscr();
//     WINDOW *tab[] = {
//         subwin(stdscr, LINES / 4, COLS, 0, 0),
//         subwin(stdscr, LINES / 4, COLS / 4, LINES / 4, 0),
//         subwin(stdscr, LINES / 4, COLS / 4, LINES / 2, 0),
//         subwin(stdscr, LINES / 2, COLS / 7, LINES / 4, 160),
//         subwin(stdscr, LINES / 4, COLS / 2, LINES / 4, 60),
//         subwin(stdscr, LINES / 4, COLS / 2, LINES / 2, 60),
//         nullptr};
//     int index = 0;

//     while (tab[index])
//     {
//         box(tab[index], ACS_VLINE, ACS_HLINE);
//         index++;
//     }

//     std::string delimiter = "\n";
//     std::string time_1 = this->_time->getInfos().substr(0, this->_time->getInfos().find(delimiter));
//     std::string time_2 = this->_time->getInfos().erase(0, this->_time->getInfos().find(delimiter) + 1);

//     std::string host_1 = this->_host->getInfos().substr(0, this->_host->getInfos().find(delimiter));
//     std::string host_2 = this->_host->getInfos().erase(0, this->_host->getInfos().find(delimiter) + 1);

//     std::string version_1 = this->_kernel->getInfos().substr(0, this->_kernel->getInfos().find(delimiter));
//     std::string version_2 = this->_kernel->getInfos().erase(0, this->_kernel->getInfos().find(delimiter) + 1);

//     std::string cpu_1 = this->_cpu->getInfos().substr(0, this->_cpu->getInfos().find(delimiter));
//     std::string cpu_2 = this->_cpu->getInfos().erase(0, this->_cpu->getInfos().find(delimiter) + 1);
//     std::string cpu_3 = this->_cpu->getInfos().erase(0, this->_cpu->getInfos().find(delimiter) + 2);
//     std::string cpu_4 = this->_cpu->getInfos().erase(0, this->_cpu->getInfos().find(delimiter) + 3);
//     std::string cpu_5 = this->_cpu->getInfos().erase(0, this->_cpu->getInfos().find(delimiter) + 4);

//     std::string ram_1 = this->_ram->getInfos().substr(0, this->_ram->getInfos().find(delimiter));
//     std::string ram_2 = this->_ram->getInfos().erase(0, this->_ram->getInfos().find(delimiter) + 1);

//     mvwprintw(tab[0], 5, 75, "BIENVENUE SUR L'INTERFACE NCURSES");
//     mvwprintw(tab[1], 3, 10, host_1.data());
//     mvwprintw(tab[1], 5, 10, host_2.data());
//     mvwprintw(tab[1], 1, 13, "Hostname & Username");
//     mvwprintw(tab[2], 1, 10, "Operate name & Kernel v.");
//     mvwprintw(tab[2], 3, 7, version_1.data());
//     mvwprintw(tab[2], 5, 7, version_2.data());
//     mvwprintw(tab[3], 1, 7, "Date and Time");
//     mvwprintw(tab[3], 3, 8, time_1.data());
//     mvwprintw(tab[3], 5, 8, time_2.data());
//     mvwprintw(tab[4], 1, 45, "MEMOIRE");
//     mvwprintw(tab[5], 1, 47, "CPU");

//     nodelay(stdscr, true);
//     noecho();
//     curs_set(0);
//     while (getch() != 113)
//     {
//         while (tab[index])
//         {
//             this->_time->refreshInfos();
//             this->_cpu->refreshInfos();
//             this->_ram->refreshInfos();
//             time_1 = this->_time->getInfos().substr(0, this->_time->getInfos().find(delimiter));
//             time_2 = this->_time->getInfos().erase(0, this->_time->getInfos().find(delimiter) + 1);
//             ram_1 = this->_ram->getInfos().substr(0, this->_ram->getInfos().find(delimiter));
//             ram_2 = this->_ram->getInfos().erase(0, this->_ram->getInfos().find(delimiter) + 1);
//             std::string cpu = this->_cpu->getInfos();
//             std::string ram = this->_ram->getInfos();

//             cpu_1 = cpu.substr(0, cpu.find(delimiter));
//             cpu.erase(0, cpu.find(delimiter) + 1);
//             cpu_2 = cpu.substr(0, cpu.find(delimiter));
//             cpu.erase(0, cpu.find(delimiter) + 1);
//             cpu_3 = cpu.substr(0, cpu.find(delimiter));
//             cpu.erase(0, cpu.find(delimiter) + 1);
//             cpu_4 = cpu.substr(0, cpu.find(delimiter));
//             cpu.erase(0, cpu.find(delimiter) + 1);
//             cpu_5 = cpu.substr(0, cpu.find(delimiter));
//             cpu.erase(0, cpu.find(delimiter) + 1);
//             mvwprintw(tab[3], 3, 8, time_1.data());
//             mvwprintw(tab[3], 5, 8, time_2.data());
//             mvwprintw(tab[4], 4, 15, ram_1.data());
//             mvwprintw(tab[4], 4, 65, ram_2.data());
//             mvwprintw(tab[5], 3, 25, cpu_1.data());
//             mvwprintw(tab[5], 4, 25, cpu_2.data());
//             mvwprintw(tab[5], 5, 25, cpu_3.data());
//             mvwprintw(tab[5], 6, 25, cpu_4.data());
//             mvwprintw(tab[5], 7, 25, cpu_5.data());
//             wrefresh(tab[index]);
//             index++;
//         }
//         index = 0;
//     }

//     endwin();
// }