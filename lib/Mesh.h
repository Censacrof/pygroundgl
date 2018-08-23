#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex
{
private:
    glm::vec3 _pos;

public:
    Vertex(const glm::vec3& pos)
    {
        _pos = pos;
    }
};


class Mesh
{
private:
    enum {
        POSITION_VB,
        
        NUM_BUFFERS
    };

    GLuint _vertexArrayObject;
    GLuint _vertexArrayBuffers[NUM_BUFFERS];

    unsigned int _drawCount;

public:
    Mesh(Vertex*, unsigned int);
    ~Mesh();

    void draw();

};

#endif