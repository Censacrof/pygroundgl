#include "Display.h"

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <pybind11/pybind11.h>

namespace py = pybind11;

Display::Display(int width, int height, std::string windowTitle)
{
    _isWindowOpen = false;

    _width = width;
    _height = height;
    _windowTitle = windowTitle;

    //init SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to init SDL\n";
        return;
    }

    //create window
    _mainWindow = SDL_CreateWindow(
        _windowTitle.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width,
        _height,
        SDL_WINDOW_OPENGL
    );

    //disable all deprecated code
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //set opengl target version 2.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    //set buffers sizes
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

    //enable double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //create the opengl context
    _context = SDL_GL_CreateContext(_mainWindow);
    if (_context == NULL)
    {
        std::cerr << "Failed to create opengl context\n";
        return;
    }


    //init glew
    GLenum status = GLint();
    if (status != GLEW_OK)
    {
        std::cerr << "Failed to initialize glew\n";
        return;
    }

    //enable depthtest (prevents drawing distant 'pixels' on closer 'pixels')
    glEnable(GL_DEPTH_TEST);

    //enable face culling (prevents drawing faces from behind)
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    _isWindowOpen = true;

    std::cout << "Display created\n";
}

Display::~Display()
{
    SDL_GL_DeleteContext(_context);
    SDL_DestroyWindow(_mainWindow);
    SDL_Quit();
}


void Display::update()
{
    //swap back and front buffer (double buffer)
    SDL_GL_SwapWindow(_mainWindow);

    //poll all sdl events
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            _isWindowOpen = false;
        
    }
}


void Display::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


int add(int a, int b) { return a + b; }

PYBIND11_MODULE(display, m) {
    // m.def("add", &add, "A function which adds two numbers");


    py::class_<Display>(m, "Display")
        .def(py::init<int, int, std::string>())
        .def("update", &Display::update)
        .def("getWidth", &Display::getWidth)
        .def("getHeight", &Display::getHeight)
        .def("getRatio", &Display::getRatio)
        .def("isWindowOpen", &Display::isWindowOpen)
        .def("clear", &Display::clear);
}