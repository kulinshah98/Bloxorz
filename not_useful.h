#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;


//variables
extern float rectangle_rot_dir;
extern bool rectangle_rot_status;

extern float camera_rotation_angle;

struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};
extern GLMatrices Matrices;


//functions
static void error_callback(int error, const char* description);
void reshapeWindow (GLFWwindow* window, int width, int height);
void quit(GLFWwindow *window);
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);


//functions
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);

void draw3DObject (struct VAO* vao);

void reshapeWindow (int width, int height);

void initGLUT (int& argc, char** argv, int width, int height);

void draw (GLFWwindow* window, float x, float y, float w, float h, int doM, int doV, int doP);

void idle ();

void draw(VAO * obj, glm::vec3 trans, glm::vec3 pos, float angle_rot);

extern GLuint programID;
