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



typedef enum e_event
{
    ERROR = - 1,
    NOTHING,
    ARROW_UP,
    ARROW_DOWN,
    ARROW_RIGHT,
    ARROW_LEFT,
    KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
    KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
    SPACE,
    ENTER,
    ESCAPE
}e_event;

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
        virtual void drawAsset(void *sprite, int x, int y) = 0;
        virtual void destroyAsset(void *sprite) = 0;
        virtual void drawWindow() = 0;

        // Events
        virtual e_event catchEvent() = 0;

        // Sounds
        virtual void start_sound() = 0;
        virtual void stop_sound() = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */