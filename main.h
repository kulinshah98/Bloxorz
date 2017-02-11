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

extern GLuint programID;
extern int do_rot, floor_rel;
extern glm::vec3 rect_pos, floor_pos;
extern double last_update_time, current_time;

extern float rectangle_rot_dir,rectangle_rotation;
extern bool rectangle_rot_status;

extern VAO *rectangle, *cam, *floor_vao;

extern float camera_rotation_angle;

//functions
void createRectangle ();
void createCam ();
void createFloor ();
void draw (GLFWwindow* window, float x, float y, float w, float h, int doM, int doV, int doP);
void initGL (GLFWwindow* window, int width, int height);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
void draw3DObject (struct VAO* vao);
GLFWwindow* initGLFW (int width, int height);
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void reshapeWindow (GLFWwindow* window, int width, int height);
