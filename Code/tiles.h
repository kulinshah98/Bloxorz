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


#ifndef TILES_H
#define TILES_H

class tiles_class
{
public:
  int active, color, type;
  glm::vec3 tiles_coord;
  VAO * tiles_vao;

public:
  void init(int tiles_type, int is_active);
  void createTiles();
  void drawTiles();
};

#endif

extern double tiles_width, tiles_length, tiles_height;


//functions
void draw3DObject (struct VAO* vao);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode);
void drawSingleObject(VAO * obj, glm::vec3 trans_coord, glm::vec3 rot_coord, float rot_angle);
