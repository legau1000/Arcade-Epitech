/*
** EPITECH PROJECT, 2017
** Arcarde Epitech Tek2
** File description:
** IDISPLAYMODULE_HPP_.hpp
*/

#ifndef IDISPLAYMODULE_HPP_
# define IDISPLAYMODULE_HPP_

#include <string>
// open and close the window on constructor and destructor

typedef enum e_type
{
    UNKNOW = -1,
    ONE,
    TWO,
    THREE
}e_type;

class IDisplayModule
{

    public:
        virtual ~IDisplayModule() {};

        /* Get type of lib
        0 -> nCurses, NDK++, aa-lib, libcaca
        1 -> Allegro, Xlib, GTK+, SFML, SDL
        2 -> OpenGL, Vulkan, Qt */
        virtual e_type getType() = 0;

        // Sprites
        virtual void *createAsset(std::string &path) = 0;
        virtual void drawAsset(void *sprite) = 0;
        virtual void destroyAsset(void *sprite) = 0;
        virtual void drawWindow() = 0;

        // Events
        virtual void catchEvent() = 0;

        // Sounds
        virtual void start_sound() = 0;
        virtual void stop_sound() = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */