/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** LoadGraph.hpp
*/

#ifndef MAPGRAPHGAME_HPP__
#define MAPGRAPHGAME_HPP__

#include <iostream>

class mapGraphGame
{
    public:
        mapGraphGame(const std::string &name, const std::string &path) : _path(path), _name(name)
        { 
            this->_used = false;
        };
        ~mapGraphGame() {};

        bool GetUse() const {return (this->_used);};
        void SetUse(const bool use) {this->_used = use;};

        std::string GetPath() {return (this->_path);};

        std::string GetName() {return (this->_name);};

    protected:

    private:
        std::string _path;
        std::string _name;
        bool _used;
};

#endif