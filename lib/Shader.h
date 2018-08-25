#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

#include "Transform.h"
#include "Camera.h"

class Shader
{
private:
    enum {
        VERTEX_SHADER,
        FRAGMENT_SHADER,
        NUM_SHADERS
    };

    enum {
        TRANSFORM_UNIFORM,
        NUM_UNIFORMS
    };

    GLuint _program;
    GLuint _shaders[NUM_SHADERS];
    GLuint _uniforms[NUM_UNIFORMS];

public:
    Shader(const std::string& fileName);
    ~Shader();

    void bind();
    void update(const Transform& transform, const Camera& camera);

    GLuint createShader(const std::string& text, GLenum shaderType);

    std::string loadShader(const std::string& fileName);
    void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
};


#endif