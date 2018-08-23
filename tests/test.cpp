#include <glm/glm.hpp>
#include <GL/glew.h>

#include "../lib/Display.h"
#include "../lib/Mesh.h"
#include "../lib/Shader.h"
#include "../lib/Texture.h"


int main()
{
    Display display = Display(300, 300, "Test");

    Vertex vertices[] = {
        Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1)),
        Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0, 0)),
        Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1, 0))
    };

    Mesh mesh = Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Shader shader = Shader("res/basicShader");
    Texture texture = Texture("res/brick.jpg");

    while(display.isWindowOpen())
    {
        display.clear(0.125f, 0.25f, 0.5f, 1.0f);

        shader.bind();
        texture.bind(0);
        mesh.draw();

        display.update();
    }

    return 0;
}