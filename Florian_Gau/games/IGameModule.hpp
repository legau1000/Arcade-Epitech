/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <iostream>
#include <memory>
#include "IDisplayModule.hpp"

namespace gameModule
{
    class IGameModule
    {
        public:
            virtual ~IGameModule() = default;
            virtual displayModule::e_event game() = 0;
            virtual bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &lib) = 0;
            virtual bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &lib) = 0;
    };
} // namespace gameModule

#endif //OOP_ARCADE_2018_IGAMEMODULE_HPP