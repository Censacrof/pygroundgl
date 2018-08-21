#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>


class Display
{    
private:
    SDL_Window* _mainWindow;
    SDL_GLContext _context;

    int _width;
    int _height;
    std::string _windowTitle;

    bool _isWindowOpen;

public:
    Display(int, int, std::string);
    ~Display();

    void update();


    int getWidth() { return _width; }
    int getHeight() { return _height; }
    float getRatio() { return (float) _width / (float) _height; }

    bool isWindowOpen() { return _isWindowOpen; }

    void clear(float, float, float, float);
};


#endif