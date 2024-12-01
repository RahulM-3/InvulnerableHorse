#include <pch.h>

Actor currentHorse;

void Application::Initialize(HMODULE _Module)
{
    InputsManager::Register();


    ScriptRegister(_Module, []
    {
            while (true)
            {
                currentHorse = UNSORTED::GET_MOUNT(UNSORTED::GET_PLAYER_ACTOR(0));
                UNSORTED::SET_ACTOR_INVULNERABILITY(currentHorse, true);
                BUILTIN::WAIT(0);
            }
    });
}


void Application::Shutdown(HMODULE _Module)
{
    ScriptUnregister(_Module);
		
    InputsManager::Unregister();
}
