#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
private:
    enum {
        VERTEX_SHADER,
        FRAGMENT_SHADER,
        NUM_SHADERS
    };

    GLuint _program;
    GLuint _shaders[NUM_SHADERS];

public:
    Shader(const std::string&);
    ~Shader();

    void bind();

    GLuint createShader(const std::string&, GLenum);

    std::string loadShader(const std::string&);
    void checkShaderError(GLuint, GLuint, bool, const std::string&);
};


#endif