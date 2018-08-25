#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

Transform::Transform(const glm::vec3& pos, const glm::vec4& rot, const glm::vec3& scale)
{
    _pos = pos;
    _rot = rot;
    _scale = scale;
}

glm::mat4 Transform::getWorldMatrix() const
{
    return glm::translate(_pos) 
        * glm::rotate(_rot.a, glm::vec3(_rot.x, _rot.y, _rot.z))
        * glm::scale(_scale);
}