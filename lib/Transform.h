#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>

//TODO
class Transform
{
private:
    glm::vec3 _pos;
    glm::vec4 _rot;
    glm::vec3 _scale;


public:
    Transform(
        const glm::vec3& pos = glm::vec3(0.0f, 0.0f, 0.0f), 
        const glm::vec4& rot = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f), 
        const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)
    );

    glm::mat4 getWorldMatrix() const;

    inline glm::vec3& getPos() { return _pos; }
    inline glm::vec4& getRot() { return _rot; }
    inline glm::vec3& getScale() { return _scale; }

    inline void setPos(const glm::vec3& pos) { _pos = pos; }
    inline void setRot(const glm::vec4& rot) { _rot = rot; }
    inline void setScale(const glm::vec3& scale) { _scale = scale; }

};

#endif