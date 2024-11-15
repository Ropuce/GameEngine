#ifndef CAMERA_H
#define CAMERA_H
#include <GL/glew.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <SDL2/SDL.h>
#include <Config/Config.h>

#include "Component.h"


enum class Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};



const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;




class Camera : public Component
{
public:	// Static members/functions

	static std::shared_ptr<Camera> activeCamera;
	
public:

	
	glm::vec3 worldUp = { 0, 1, 0 };
	glm::vec3 lookTarget;
	
	glm::vec3 position;
	
	glm::vec3 camFront;
	glm::vec3 camRight;
	glm::vec3 camUp;

	
	glm::mat4 view;
	glm::mat4 projection;
	
	//float eyex = -10, eyey = -100, eyez = 0;   // Posici�n de la c�mara
    //float centerx = 0.0f, centery = 10.0f, centerz = 0.0f; // Punto de vista
    //float upx = 0.0f, upy = 1.0f, upz = 0.0f;       // Vector hacia arriba

    float yaw = 90.0f;   // �ngulo horizontal (izquierda-derecha)
    float pitch = 0.0f; // �ngulo vertical (arriba-abajo)
    float moveStep = 0.02f; // Paso de movimiento de la c�mara
    float rotationStep = 2.0f; // Paso de rotaci�n de la c�mara
    float sensitivity = 0.5f;
    float verticalAngle = 0.0f; // �ngulo vertical para orbitaci�n con W y S

    bool altPressed = false;
	bool rMousePressed = false;
    bool FPSCam = false;
	bool arcBallCam = false;
    float zoom = 1.0f;
	float targetDistance = 2.0f;

	Camera(glm::vec3 pos, glm::vec3 lookAt);
	
    void update();
    
    void ProcessInput();
  
	void ProcessMouseMovement();
	
	void updateDirectionVectors();
	
	void updateCameraVectors();
	

};
#endif