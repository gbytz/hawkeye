#ifndef AKKEYBOARD_H
#define AKKEYBOARD_H

// STL includes

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKKeyboard
{
    public:
        // Class methods

        // Instance methods
        AKKeyboard();
        ~AKKeyboard();

        void Update();

        bool UpPressed();
        bool DownPressed();
        bool LeftPressed();
        bool RightPressed();
        // Members

        // Friend methods

    protected:
    private:
        const Uint8* currentKeyStates;
};

#endif // AKKEYBOARD_H
