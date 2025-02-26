#include <aocf/aocf_keyboard.h>
#include <aocf/aocf_platform.h>
#include <string>

#ifdef PLATFORM_WINDOWS
#define strnicmp _strnicmp
#endif

namespace AOCF{
    Keyboard::Keyboard(){
        update();
    }

    inline void Keyboard::update(){
        mKeyboardState = Platform::getKeyboardState();
    }
    
    bool Keyboard::getKey(unsigned char keyCode) const{
        unsigned char state = mKeyboardState->key[keyCode];
        bool pressed = (state & KeyboardState::PRESSED_BIT);
        return pressed;
    }

    bool Keyboard::getKeyUp(unsigned char keyCode) const{
        unsigned char state = mKeyboardState->key[keyCode];
        bool released = (state == KeyboardState::CHANGED_THIS_FRAME_BIT);
        return released;
    }

    bool Keyboard::getKeyDown(unsigned char keyCode) const{
        unsigned char state = mKeyboardState->key[keyCode];
        bool pressed = (state == (KeyboardState::CHANGED_THIS_FRAME_BIT | KeyboardState::PRESSED_BIT));
        return pressed;
    }
}