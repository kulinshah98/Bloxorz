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
  void init(int tiles_type, int is_active);
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
pair<float, float> prev_pos;
bool rectangle_rot_status = true;
VAO *rectangle, *cam, *floor_vao;
float camera_rotation_angle = 90;
tiles_class tiles_grid[12][12];
block_class block_obj;
int active_s, active_d, active_w, active_a;
pair<int,int> goal_state;
pair<int,int> bridge1;
glm::vec3 prev_block_coord;
glm::vec3 eye;
glm::vec3 target;
int view_type=0,count=0,last_count=0,flag=0, level=1;
int arr1[][10] = {
  0, 0, 0, 0, 0, 0, 1, 0, 0, 0,   //1
  0, 0, 0, 0, 0, 1, 0, 1, 0, 0,   //2
  0, 0, 0, 0, 0, 1, 1, 0, 0, 0,   //3
  0, 0, 0, 1, 1, 1, 1, 0, 0, 0,   //4
  0, 0, 0, 1, 1, 1, 1, 0, 0, 0,   //5
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0,   //6
  0, 0, 0, 1, 1, 1, 0, 0, 0, 0,   //7
  0, 0, 0, 1, 1, 1, 0, 0, 0, 0,   //8
  0, 0, 0, 1, 1, 1, 0, 0, 0, 0,   //9
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0   //10
};
int arr2[][10] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //1
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //2
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //3
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //4
  0, 0, 0, 1, 2, 2, 1, 0, 0, 0,   //5
  0, 0, 0, 1, 0, 1, 1, 0, 0, 0,   //6
  0, 1, 2, 1, 0, 1, 1, 1, 0, 0,   //7
  0, 1, 1, 1, 0, 1, 1, 0, 1, 0,   //8
  0, 1, 2, 1, 0, 1, 1, 1, 0, 0,   //9
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0   //10
};
int arr3[][10] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //1
  0, 1, 1, 1, 0, 0, 0, 0, 0, 0,   //2
  0, 1, 4, 1, 0, 0, 1, 1, 1, 0,   //3
  0, 1, 1, 1, 0, 0, 1, 2, 1, 0,   //4
  0, 1, 1, 0, 0, 0, 1, 2, 1, 0,   //5
  0, 1, 1, 1, 3, 1, 2, 2, 1, 0,   //6
  0, 0, 0, 1, 0, 1, 2, 2, 1, 0,   //7
  0, 0, 0, 1, 0, 1, 0, 2, 0, 0,   //8
  0, 0, 0, 1, 0, 2, 2, 2, 0, 0,   //9
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0   //10
};
