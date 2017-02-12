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
GLMatrices Matrices;

//Classes

#ifndef TILES_H
#define TILES_H

class tiles_class
{
public:
  int active, color, type;
  glm::vec3 tiles_coord;
  VAO * tiles_vao;

public:
  void init(int tiles_type);
  void createTiles();
  void drawTiles();
};

#endif

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

//variables
GLuint programID;
int do_rot, floor_rel;
double last_update_time, current_time;
glm::vec3 rect_pos, floor_pos;
float rectangle_rotation = 0;
double tiles_length = 0.07, tiles_width = 0.07,tiles_height = 0.03;
float rectangle_rot_dir = 1, angle;
bool rectangle_rot_status = true;
VAO *rectangle, *cam, *floor_vao;
float camera_rotation_angle = 90;
tiles_class tiles_grid[12][12];
block_class block_obj;
int active_s, active_d, active_w, active_a;
glm::vec3 prev_block_coord;
