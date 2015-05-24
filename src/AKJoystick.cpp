#include "AKJoystick.h"

std::vector<SDL_Joystick*> AKJoystick::mJoysticks;

bool AKJoystick::Init()
{
    if( SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0 )
    {
        printf( "Warning: Unable to initialize joystick subsystem! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
         mJoysticks = std::vector<SDL_Joystick*>();
        if( SDL_NumJoysticks() < 1 )
        {
            printf( "Warning: No joysticks connected!\n" );
            return false;
        }
        else
        {
            return true;
        }
    }
}

void AKJoystick::Quit()
{
    for (std::vector<SDL_Joystick*>::iterator it = mJoysticks.begin(); it != mJoysticks.end(); ++it)
    {
        SDL_JoystickClose((*it));
    }
    mJoysticks.clear();
    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
}

SDL_Joystick* AKJoystick::GetJoystick()
{
    SDL_Joystick* newJoystick = NULL;
    if( SDL_NumJoysticks() < 1 ){
        printf( "Warning: No joysticks connected!\n" );
    }
    else
    {
        newJoystick = SDL_JoystickOpen( mJoysticks.size() );
        if( newJoystick == NULL )
        {
            printf( "Warning: Joystick not available!\n" );
        }
        else
        {
            mJoysticks.push_back(newJoystick);
        }
    }
    return newJoystick;
}

AKJoystick::AKJoystick()
{
}

AKJoystick::~AKJoystick()
{
    printf("AKJoystick Destructor\n");
}