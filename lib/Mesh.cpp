#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    _drawCount = numVertices;

    glewExperimental = GL_TRUE;
    glewInit();

    glGenVertexArrays(1, &_vertexArrayObject); //create vertex array buffer and save handle in _vertexArrayObject
    glBindVertexArray(_vertexArrayObject); //use _vertexArrayObject as the current vertex array buffer    

    glGenBuffers(NUM_BUFFERS, _vertexArrayBuffers); //create as many buffers as we need
    glBindBuffer(GL_ARRAY_BUFFER, _vertexArrayBuffers[POSITION_VB]); //use _vertexArrayBuffers[POSITION_VB] as current buffer
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);  //put data in video memory

    //tell opengl that elements in _vertexArrayBuffers[POSITION_VB] (vec3) have an attribute and it's id is 0
    glEnableVertexAttribArray(0);

    
    //tell opengl how to read that attribute
    glVertexAttribPointer(
        0, //index of the generic vertex attribute to be modified.
        3, //number of components per generic vertex attribute
        GL_FLOAT, //data type of each component in the array
        GL_FALSE, //specifies whether fixed-point data values should be normalized
        0, //the byte offset between consecutive generic vertex attributes
        0 //offset of the first component of the first generic vertex attribute in the array
    );

    glBindVertexArray(0); //unset current vertex array buffer
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &_vertexArrayObject);
}

void Mesh::draw()
{
    glBindVertexArray(_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, _drawCount);

    glBindVertexArray(0);
}