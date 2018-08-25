#include "Shader.h"

#include <string>
#include <fstream>
#include <iostream>

#include <GL/glew.h>

#include "Transform.h"
#include "Camera.h"

Shader::Shader(const std::string& fileName)
{
    _program = glCreateProgram();
    _shaders[VERTEX_SHADER] = createShader(loadShader(fileName + ".vert"), GL_VERTEX_SHADER);
    _shaders[FRAGMENT_SHADER] = createShader(loadShader(fileName + ".frag"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(_program, _shaders[i]);

    glBindAttribLocation(_program, 0, "_position");
    glBindAttribLocation(_program, 1, "_texCoord");

    glLinkProgram(_program);
    checkShaderError(_program, GL_LINK_STATUS, true, "Error, shader program linking failed");

    glValidateProgram(_program);
    checkShaderError(_program, GL_VALIDATE_STATUS, true, "Error, shader program validation failed");

    _uniforms[TRANSFORM_UNIFORM] = glGetUniformLocation(_program, "_transform");
}

Shader::~Shader()
{
    for (unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(_program, _shaders[i]);
        glDeleteShader(_shaders[i]);
    }

    glDeleteProgram(_program);
}


GLuint Shader::createShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);

    if (shader == 0)
        std::cerr << "Error, shader creation failed" << std::endl;

    const GLchar* shaderSourceString[1];
    GLint shaderSourceStringLength[1];

    shaderSourceString[0] = text.c_str();
    shaderSourceStringLength[0] = text.length();

    glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error, shader program compilation failed");

    return shader;    
}


void Shader::bind()
{
    glUseProgram(_program);
}

void Shader::update(const Transform& transform, const Camera& camera)
{
    glm::mat4 worldViewMatrix = camera.getViewMatrix() * transform.getWorldMatrix();

    glUniformMatrix4fv(_uniforms[TRANSFORM_UNIFORM], 1, false, &worldViewMatrix[0][0]);
}

std::string Shader::loadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}


void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}