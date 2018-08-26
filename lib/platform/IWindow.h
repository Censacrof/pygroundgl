#ifndef IWINDOW_H
#define IWINDOW_H

#include <string>

class IWindow
{
public:

    virtual void open(int width, int height, std::string windowTitle) = 0;
    virtual void close() = 0;

    virtual void update() = 0;

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual float getRatio() const = 0;

    virtual bool isWindowOpen() const = 0;

    virtual void clear(float r, float g, float b, float a) = 0;
};

#endif