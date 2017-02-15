#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <irrKlang.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace irrklang;

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


#define F first
#define S second

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


extern GLuint programID;
extern int do_rot, floor_rel;
extern glm::vec3 rect_pos, floor_pos;
extern double last_update_time, current_time;

extern float rectangle_rot_dir,rectangle_rotation;
extern bool rectangle_rot_status;

extern VAO *rectangle, *cam, *floor_vao;
extern tiles_class tiles_grid[12][12];
extern float camera_rotation_angle;
extern block_class block_obj;
extern int active_s, active_d, active_w, active_a,count,last_count, flag, level;
extern float angle;
extern pair<int,int> goal_state, bridge1;
extern pair<float, float> prev_pos;
extern int arr1[10][10], arr2[10][10], arr3[10][10];
extern glm::vec3 eye;
extern glm::vec3 target;
extern int view_type;


//functions
void createRectangle ();
void createCam ();
void createFloor ();
void drawSingleObject(VAO * obj, glm::vec3 trans_coord, glm::vec3 rot_coord, float rot_angle);
void draw (GLFWwindow* window, float x, float y, float w, float h, int doM, int doV, int doP);
void initGL (GLFWwindow* window, int width, int height);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode);
void draw3DObject (struct VAO* vao);
GLFWwindow* initGLFW (int width, int height);
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void reshapeWindow (GLFWwindow* window, int width, int height);
void drawBlockObject(VAO * obj, glm::vec3 trans_coord1, int axis, glm::vec3 trans_coord2, glm::vec3 rot_coord, float rot_angle);
void checkBlockPosition();
void setEyeTarget();
void createTiles1();
void createTiles2();
void createTiles3();
