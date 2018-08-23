#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture
{
private:
    GLuint _texture;

public:
    Texture(const std::string&);
    ~Texture();

    void bind(unsigned int);


};


#endif