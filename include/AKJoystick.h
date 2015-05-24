#ifndef AKJOYSTICK_H
#define AKJOYSTICK_H

// STL includes
#include <vector>

// External libs
#include <SDL2/SDL.h>

// Forward declarations
class AKJoystick
{
    public:
        // Class methods
        static bool Init();
        static void Quit();

        static SDL_Joystick* GetJoystick();

        // Instance methods
        AKJoystick();
        ~AKJoystick();

        // Members

        // Friend methods

    protected:

    private:
        static std::vector<SDL_Joystick*> mJoysticks;
};

#endif // AKJOYSTICK_H
