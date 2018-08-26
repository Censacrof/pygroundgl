#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include "IWindow.h"

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class SDL2Window : public IWindow
{
private:
    SDL_Window* _mainWindow;
    SDL_GLContext _context;

    int _width;
    int _height;
    std::string _windowTitle;

    bool _isWindowOpen;

public:
    void open(int width, int height, std::string windowTitle);
    void close();

    void update();

    int getWidth() const { return _width; }
    int getHeight() const { return _height; }
    float getRatio() const { return (float) _width / (float) _height; }

    bool isWindowOpen() const { return _isWindowOpen; }

    void clear(float r, float g, float b, float a);
    
};

#endif