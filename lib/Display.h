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
    Display(int width, int height, std::string windowTitle);
    ~Display();

    void update();


    int getWidth() const { return _width; }
    int getHeight() const { return _height; }
    float getRatio() const { return (float) _width / (float) _height; }

    bool isWindowOpen() const { return _isWindowOpen; }

    void clear(float r, float g, float b, float a);
};


#endif