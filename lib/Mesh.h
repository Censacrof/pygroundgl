#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>

class Vertex
{
private:
    glm::vec3 _pos;
    glm::vec2 _textCoord;

public:
    Vertex(const glm::vec3& pos, const glm::vec2& textCoord)
    {
        _pos = pos;
        _textCoord = textCoord;
    }

    inline glm::vec3& getPos() { return _pos; }
    inline glm::vec2& getTextCoord() { return _textCoord; }
};


class Mesh
{
private:
    enum {
        POSITION_VB,
        TEXTCOORD_VB,
        INDEX_VB,
        
        NUM_BUFFERS
    };

    GLuint _vertexArrayObject;
    GLuint _vertexArrayBuffers[NUM_BUFFERS];

    unsigned int _drawCount;

public:
    Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
    Mesh(const std::string& fileName);
    ~Mesh();

    void draw();

};

#endif