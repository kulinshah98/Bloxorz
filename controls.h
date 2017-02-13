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

#ifndef BLOCK_H
#define BLOCK_H

class block_class
{
public:
  int along_x, along_y, along_z;
  glm::vec3 block_coord;
  VAO * block_vao;

public:
  void createBlock();
  void drawBlock();
};

#endif

extern int do_rot, floor_rel;
extern glm::vec3 rect_pos, floor_pos;
extern float rectangle_rot_dir, triangle_rot_dir,rectangle_rotation;
extern bool triangle_rot_status, rectangle_rot_status;
extern int active_s, active_d, active_w, active_a;
extern float angle;
extern block_class block_obj;
extern glm::vec3 prev_block_coord;
extern int view_type;
extern glm::vec3 eye;
extern glm::vec3 target;

//functions
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void quit(GLFWwindow *window);
