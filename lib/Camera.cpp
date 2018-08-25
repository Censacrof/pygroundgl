#include "Camera.h"


Camera::Camera(
    const glm::vec3& pos,
    float fov,
    float aspectRatio,
    float zNear,
    float zFar,
    const glm::vec3& forwardDir,
    const glm::vec3& upDir
)
{
    _pos = pos;

    setPerspective(fov, aspectRatio, zNear, zFar);

    _forwardDir = forwardDir;
    _upDir = upDir;
}


Camera::~Camera()
{

}