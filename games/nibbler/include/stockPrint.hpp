/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** LoadGraph.hpp
*/

#ifndef STOCKPRINT_HPP__
#define STOCKPRINT_HPP__

#include <string>

class stockPrint
{
    public:
        stockPrint(std::string path, std::string name, int x, int y) : _path(path), _name(name)
        {
            this->_text = false;
            this->_x = x;
            this->_y = y;
        };
        ~stockPrint() {};

        std::string GetPath() {return (this->_path);};
        std::string GetName() {return (this->_name);};

        int GetX() {return (this->_x);};
        int GetY() {return (this->_y);};

        bool GetText() {return (this->_text);};

        void SetText(bool text) {this->_text = text;};

        void SetXY(int x, int y)
        {
            this->_x = x;
            this->_y = y;
        };

    protected:

    private:
        const std::string _path;
        const std::string _name;
        bool _text;
        int _x;
        int _y;

};

#endif