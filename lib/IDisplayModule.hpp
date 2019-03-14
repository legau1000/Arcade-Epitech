/*
** EPITECH PROJECT, 2017
** Arcarde Epitech Tek2
** File description:
** IDISPLAYMODULE_HPP_.hpp
*/

#ifndef IDISPLAYMODULE_HPP_
# define IDISPLAYMODULE_HPP_

#include <string>
#include <iostream>
// open and close the window on constructor and destructor

namespace displayModule
{
    enum e_event {
        ERROR = -1,
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
    };

    class Asset
    {
        public:
            /* Constructor who don't take params
                Set _y to 0
                Set _x to 0
                Set _asset to nullptr       */
            explicit Asset() 
            {
                this->_x = 0;
                this->_y = 0;
                this->_asset = nullptr;
            };
            ~Asset() = default;

            // Set X and Y of sprite
            void setPosition(int x, int y)
            {
                this->_x = x;
                this->_y = x;
            };

            // Set The Asset to _Asset
            void setAsset(void *asset)
            {
                this->_asset = asset;
            };

            // Get Asset (Sprite / Texts / Other)
            void *getAsset()
            {
                return (_asset);
            };

            // Get Positions
            int getXPosition()
            {
                return (_x);
            };

            int getYPosition() 
            {
                return (_y);
            };

        private:
            void *_asset;
            int _x;
            int _y;
    };

    class IDisplayModule
    {
        public:
            // Destroyer
            virtual ~IDisplayModule() = default;

            // Sprites
            virtual Asset createAsset(const std::string &path) = 0;
            virtual void drawAsset(Asset &sprite) = 0;
            virtual void refreshWindow() = 0;

            // Text
            virtual Asset createText(const std::string &text) = 0;

            // Set Position
            virtual void setAssetPosition(Asset &asset, int x, int y) = 0;

            // Events
            virtual e_event catchEvent() = 0;

            // Sounds
            virtual void start_sound() = 0;
            virtual void stop_sound() = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */