#include "main.h"



// Creates the rectangle object used in this sample code
void createRectangle ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data [] = {
	-0.5, 0.5, 0.5,
	-0.5, -0.5, 0.5,
	0.5, -0.5, 0.5,
	-0.5, 0.5, 0.5,
	0.5, -0.5, 0.5,
	0.5, 0.5, 0.5,
	0.5, 0.5, 0.5,
	0.5, -0.5, 0.5,
	0.5, -0.5, -0.5,
	0.5, 0.5, 0.5,
	0.5, -0.5, -0.5,
	0.5, 0.5, -0.5,
	0.5, 0.5, -0.5,
	0.5, -0.5, -0.5,
	-0.5, -0.5, -0.5,
	0.5, 0.5, -0.5,
	-0.5, -0.5, -0.5,
	-0.5, 0.5, -0.5,
	-0.5, 0.5, -0.5,
	-0.5, -0.5, -0.5,
	-0.5, -0.5, 0.5,
	-0.5, 0.5, -0.5,
	-0.5, -0.5, 0.5,
	-0.5, 0.5, 0.5,
	-0.5, 0.5, -0.5,
	-0.5, 0.5, 0.5,
	0.5, 0.5, 0.5,
	-0.5, 0.5, -0.5,
	0.5, 0.5, 0.5,
	0.5, 0.5, -0.5,
	-0.5, -0.5, 0.5,
	-0.5, -0.5, -0.5,
	0.5, -0.5, -0.5,
	-0.5, -0.5, 0.5,
	0.5, -0.5, -0.5,
	0.5, -0.5, 0.5,
	-0.5, 0.5, 0.5,
	0.5, 0.5, -0.5,
	0.5, 0.75, -0.5,
    };

    static const GLfloat color_buffer_data [] = {
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0, 0, 0,
	0, 0, 0,
	1, 1, 1,
    };

    // create3DObject creates and returns a handle to a VAO that can be used later
    rectangle = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data, color_buffer_data, GL_FILL);
}
void createCam ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data [] = {
	-0.1, 0, 0,
	0.1, 0, 0,
	0, 0.1, 0,
    };

    static const GLfloat color_buffer_data [] = {
	1, 1, 1,
	1, 1, 1,
	1, 1, 1,
    };

    // create3DObject creates and returns a handle to a VAO that can be used later
    cam = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data, color_buffer_data, GL_LINE);
}
void createFloor ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data [] = {
	-2, -1, 2,
	2, -1, 2,
	-2, -1, -2,
	-2, -1, -2,
	2, -1, 2,
	2, -1, -2,
    };

    static const GLfloat color_buffer_data [] = {
	0.65, 0.165, 0.165,
	0.65, 0.165, 0.165,
	0.65, 0.165, 0.165,
	0.65, 0.165, 0.165,
	0.65, 0.165, 0.165,
	0.65, 0.165, 0.165,
    };

    // create3DObject creates and returns a handle to a VAO that can be used later
    floor_vao = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color_buffer_data, GL_FILL);
}


/* Render the scene with openGL */
/* Edit this function according to your assignment */

void drawSingleObject(VAO * obj, glm::vec3 trans_coord, glm::vec3 rot_coord, float rot_angle)
{
  glm::vec3 eye ( 2, 4, -4);
  //cout << eye << endl;
  // Target - Where is the camera looking at.  Don't change unless you are sure!!
  glm::vec3 target (2, 0, 0);
  // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
  glm::vec3 up (0, 1, 0);

  // Compute Camera matrix (view)
  Matrices.view = glm::lookAt(eye, target, up); // Fixed camera for 2D (ortho) in XY plane

  // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
  glm::mat4 VP;
  VP = Matrices.projection * Matrices.view;

  // Send our transformation to the currently bound shader, in the "MVP" uniform
  // For each model you render, since the MVP will be different (at least the M part)
  glm::mat4 MVP;	// MVP = Projection * View * Model

  // Load identity to model matrix
  Matrices.model = glm::mat4(1.0f);
  //printf("%f %f %f\n",trans_coord[0], trans_coord[1], trans_coord[2]);
  //printf("%d %d %d\n",trans_coord[0], trans_coord[1], trans_coord[2]);
  glm::mat4 translateRectangle = glm::translate (trans_coord);        // glTranslatef
  glm::mat4 rotateRectangle = glm::rotate((float )(rot_angle*M_PI/180.0f), rot_coord);
  glm::mat4 transformRectangle = translateRectangle * rotateRectangle;
  Matrices.model *= transformRectangle;

  MVP = VP * Matrices.model;
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
  draw3DObject(obj);
}

void draw (GLFWwindow* window, float x, float y, float w, float h, int doM, int doV, int doP)
{
  int fbwidth, fbheight, i, j;
  glfwGetFramebufferSize(window, &fbwidth, &fbheight);
  glViewport((int)(x*fbwidth), (int)(y*fbheight), (int)(w*fbwidth), (int)(h*fbheight));

  // use the loaded shader program
  // Don't change unless you know what you are doing
  glUseProgram (programID);
  for(i=0;i<10;i++)
  {
    for(j=0;j<10;j++)
    {
      tiles_grid[i][j].drawTiles();
    }
  }
}


void createTiles()
{
  int arr[][10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //2
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0,   //3
    0, 0, 0, 1, 1, 1, 0, 0, 0, 0,   //4
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0,   //5
    0, 0, 0, 0, 1, 1, 0, 0, 0, 0,   //6
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //7
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //8
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //9
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0   //10
  };
  int i,j;
  for(i=0; i<10; i++)
  {
    for(j=0; j<10; j++)
    {
      tiles_class temp;
      temp.init(arr[i][j]);
      temp.createTiles();
      tiles_grid[i][j] = temp;
    }
  }
  for(i=0;i<10;i++)
  {
    for(j=0;j<10;j++)
    {
      tiles_grid[i][j].tiles_coord = glm::vec3(i-2, 0, j-2);
    }
  }
}

void initGL (GLFWwindow* window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
	// Create the models
	createTiles();
  createRectangle();
	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	// Get a handle for our "MVP" uniform
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


	reshapeWindow (window, width, height);

    // Background color of the scene
	glClearColor (0.3f, 0.3f, 0.3f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main (int argc, char** argv)
{
	int width = 1000;
	int height = 700;
  rect_pos = glm::vec3(0, 0, 0);
  floor_pos = glm::vec3(0, 0, 0);
  do_rot = 0;
  floor_rel = 1;

    GLFWwindow* window = initGLFW(width, height);

	initGL (window, width, height);

    double last_update_time = glfwGetTime();

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // OpenGL Draw commands
        current_time = glfwGetTime();
        if(do_rot)
        {
        //  printf("do_rot=1\n");
          camera_rotation_angle += 90*(current_time - last_update_time); // Simulating camera rotation
          //cout << camera_rotation_angle << " " << current_time << " " << last_update_time << endl;
        }
      	if(camera_rotation_angle > 720)
        {
          camera_rotation_angle -= 720;
        }
      	last_update_time = current_time;
      	draw(window, 0, 0, 1, 1, 1, 1, 1);
        //draw(window, 0.5, 0, 0.5, 0.5, 0, 1, 1);
      	//draw(window, 0, 0.5, 0.5, 0.5, 1, 0, 1);
      	//draw(window, 0.5, 0.5, 0.5, 0.5, 0, 0, 1);

        // Swap Frame Buffer in double buffering
        glfwSwapBuffers(window);

        // Poll for Keyboard and mouse events
        glfwPollEvents();

        // Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
    }

    glfwTerminate();
//    exit(EXIT_SUCCESS);
}
