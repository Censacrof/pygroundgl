#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


class Camera
{
private:
    glm::vec3 _pos;

    float _fov;
    float _aspectRatio;
    float _zNear;
    float _zFar;
    glm::mat4 _perspective;    
    
    glm::vec3 _forwardDir;
    glm::vec3 _upDir;

public:
    Camera(
        const glm::vec3& pos,
        float fov,
        float aspectRatio,
        float zNear,
        float zFar,
        const glm::vec3& forwardDir = glm::vec3(0.0f, 0.0f, 1.0f),
        const glm::vec3& upDir = glm::vec3(0.0f, 1.0f, 0.0f)
    );

    ~Camera();

    //getters
    inline glm::mat4 getViewMatrix() const 
    {  
        return _perspective * glm::lookAt(_pos, _pos + _forwardDir, _pos + _upDir);
    }

    inline glm::vec3 getPos() const { return _pos; }

    inline float getFov() const { return _fov; }
    inline float getAspectRatio() const { return _aspectRatio; }
    inline float getZNear() const { return _zNear; }
    inline float getZFar() const { return _zFar; }    

    inline glm::vec3 getForwardDir() const { return _forwardDir; }
    inline glm::vec3 getUpDir() const { return _upDir; }

    //setters
    void setPos(const glm::vec3& pos) { _pos = pos; }

    void setForwardDir(const glm::vec3& forwardDir) { _forwardDir = forwardDir; }
    void setUpDir(const glm::vec3& upDir) { _upDir = upDir; }

    void setPerspective(float fov, float aspectRatio, float zNear, float zFar) 
    {
        _fov = fov;
        _aspectRatio = aspectRatio;
        _zNear = zNear;
        _zFar = zFar;
        
        _perspective = glm::perspective(fov, aspectRatio, zNear, zFar);
    }
};


#endif