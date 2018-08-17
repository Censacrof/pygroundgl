#include <iostream>

#include "../lib/Display.h"

int main()
{
    Display display = Display(400, 300, "My Engine");

    while (display.isWindowsOpen())
    {
        display.update();
        display.clear(0, 1, 0, 1);
    }
    
    return 0;
}
