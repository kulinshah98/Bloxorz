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

extern block_class block_obj;
extern int active_s, active_d, active_w, active_a;
extern float angle;
extern glm::vec3 prev_block_coord;


//functions
void draw3DObject (struct VAO* vao);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
void drawSingleObject(VAO * obj, glm::vec3 trans_coord, glm::vec3 rot_coord, float rot_angle);
void drawBlockObject(VAO * obj, glm::vec3 trans_coord1, int axis, glm::vec3 trans_coord2, glm::vec3 rot_coord, float rot_angle);
