#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <GL/glew.h>

#include "../lib/Display.h"
#include "../lib/Mesh.h"
#include "../lib/Shader.h"
#include "../lib/Texture.h"
#include "../lib/Transform.h"
#include "../lib/Camera.h"

int main()
{
    Display display = Display(800, 600, "Test");

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0, 0)),
        Vertex(glm::vec3(-0.5f, 0.5f, 0.0), glm::vec2(0, 1)),
        Vertex(glm::vec3(0.5, 0.5, 0.0), glm::vec2(1, 1)),
        Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1, 0))
    };

    unsigned int indices[] = { 0, 1, 3, 3, 1, 2 };

    Mesh mesh = Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
    Shader shader = Shader("res/basicShader");
    Texture texture = Texture("res/brick.jpg");
    Transform transform = Transform();
    Camera camera = Camera(
        glm::vec3(0, 0, -1),
        90.0f,
        display.getRatio(),
        0.01f,
        1000.0f
    );

    float increment = 0.01f;
    float count = 0;
    while(display.isWindowOpen())
    {
        count += increment;

        transform.setRot(
            glm::rotate(increment, glm::vec3(1, 1, 1)) * transform.getRot()
        );
        transform.getRot().a += increment;

        camera.setPos(glm::vec3(0, 0, -2 + glm::sin(count)));

        display.clear(0.125f, 0.25f, 0.5f, 1.0f);

        shader.bind();
        shader.update(transform, camera);
        texture.bind(0);
        mesh.draw();

        display.update();
    }

    return 0;
}