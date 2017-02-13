#include "main.h"



/* Render the scene with openGL */
/* Edit this function according to your assignment */

void drawSingleObject(VAO * obj, glm::vec3 trans_coord, glm::vec3 rot_coord, float rot_angle)
{
  //glm::vec3 eye ( 2, 4, -4);
  //cout << eye << endl;
  // Target - Where is the camera looking at.  Don't change unless you are sure!!
  //glm::vec3 target (2, 0, 0);
  // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
//  cout << target[0] << " " << target[1] << " " << target[2] << " " << eye[0] << " " << " " << eye[1] << " " << " " << eye[2] << endl;
setEyeTarget();
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

void drawBlockObject(VAO * obj, glm::vec3 trans_coord1, int axis, glm::vec3 trans_coord2, glm::vec3 rot_coord, float rot_angle)
{
  //glm::vec3 eye ( 2, 4, -4);
  //cout << eye << endl;
  // Target - Where is the camera looking at.  Don't change unless you are sure!!
  //glm::vec3 target (2, 0, 0);
  // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
  setEyeTarget();
  glm::vec3 up (0, 1, 0);
//  cout << target[0] << " " << target[1] << " " << target[2] << " " << eye[0] << " " << " " << eye[1] << " " << " " << eye[2] << endl;

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
  glm::mat4 rotateRectangle2 = glm::mat4(1.0f);
  if(axis==1)
  {
    rotateRectangle2 = glm::rotate((float )M_PI/2, glm::vec3(0,0,1));
  }
  else if(axis==2)
  {
    rotateRectangle2 = glm::rotate((float )M_PI/2, glm::vec3(1,0,0));
  }
  glm::mat4 translateRectangle1 = glm::translate (trans_coord1);
  glm::mat4 translateRectangle2 = glm::translate (-trans_coord2);
  glm::mat4 translateRectangle3 = glm::translate (trans_coord2);        // glTranslatef
  glm::mat4 rotateRectangle = glm::rotate((float )(rot_angle*M_PI/180.0f), rot_coord);
  glm::mat4 transformRectangle =  rotateRectangle2 * translateRectangle1  * translateRectangle3 * rotateRectangle * translateRectangle2;
  Matrices.model *= transformRectangle;

  MVP = VP * Matrices.model;
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
  draw3DObject(obj);
}

void checkBlockPosition()
{
  float block_x = block_obj.block_coord[0]+2;
  float block_y = block_obj.block_coord[2]+2;
//  cout << block_x  << " " << block_y << endl;
  //cout << block_obj.block_coord[0] << " " <<  block_obj.block_coord[2] << " " << goal_state.first - 2 << " " << goal_state.second - 2 << endl;
  if(block_obj.along_y==1 && block_obj.block_coord[0]==goal_state.first-2 && block_obj.block_coord[2]==goal_state.second-2)
  {
    printf("Game Completed successfully\n");
    exit(0);
  }
  else if(block_obj.along_y==1 && arr[ (int )block_obj.block_coord[0] + 2 ][ (int )block_obj.block_coord[2] + 2 ]==0)
  {
    printf("Game Over\n");
    exit(0);
  }
  else if(block_obj.along_x==1 && ((arr[(int)(block_x-0.5)][ (int )block_y ]==0 && ((int)(block_x-0.5)!=goal_state.first || (int)block_y!=goal_state.second)) || (arr[(int)(block_x+0.5)][ (int )block_y ]==0 && ((int)(block_x+0.5)!=goal_state.first || (int)block_y!=goal_state.second))))
  {
    printf("Game Over\n");
    exit(0);
  }
  else if(block_obj.along_z==1 && ((arr[(int)(block_x)][ (int )(block_y-0.5) ]==0 && ((int)(block_y-0.5)!=goal_state.second || (int)block_x!=goal_state.first)) || (arr[(int)(block_x)][ (int )(block_y + 0.5) ]==0 && ((int)(block_y+0.5)!=goal_state.second || (int)block_x!=goal_state.first))))
  {
    printf("Game Over\n");
    exit(0);
  }
}

void setEyeTarget()
{
  if(view_type==0)
  {
    eye = glm::vec3(2,4,-4);
    target = glm::vec3(2,0,0);
  }
  else if(view_type==1)
  {
    eye = glm::vec3(2,9,1);
    target = glm::vec3(2,0,2);
  }
  else if(view_type==2)
  {
    if(block_obj.along_y==1)
    {
      eye = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 1.3, block_obj.block_coord[2]+0.5);
      target = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 1.3, block_obj.block_coord[2]+3);
    }
    else if(block_obj.along_x==1)
    {
      eye = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 0.7, block_obj.block_coord[2]+0.5);
      target = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 0.7, block_obj.block_coord[2]+3);
    }
    else if(block_obj.along_z==1)
    {
      eye = glm::vec3(block_obj.block_coord[0] - 0.5, block_obj.block_coord[1] + 0.7, block_obj.block_coord[2]);
      target = glm::vec3(block_obj.block_coord[0] - 3, block_obj.block_coord[1] + 0.7, block_obj.block_coord[2]);
    }
  }
  else if(view_type==3)
  {
    if(block_obj.along_y==1)
    {
      eye = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 2.5, block_obj.block_coord[2]-1);
      target = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] , block_obj.block_coord[2]);
    }
    else if(block_obj.along_x==1)
    {
      eye = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 2.2, block_obj.block_coord[2]-1);
      target = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 0.7, block_obj.block_coord[2]);
    }
    else if(block_obj.along_z==1)
    {
      eye = glm::vec3(block_obj.block_coord[0] , block_obj.block_coord[1] + 2.2, block_obj.block_coord[2]);
      target = glm::vec3(block_obj.block_coord[0], block_obj.block_coord[1] + 0.7, block_obj.block_coord[2]);
    }
  }
  else if(view_type==4)
  {
    
  }
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
      if(tiles_grid[i][j].active==1)
      {
        tiles_grid[i][j].drawTiles();
      }
    }
  }
  block_obj.drawBlock();
  checkBlockPosition();
}


void createTiles()
{
  goal_state.first = 4;
  goal_state.second = 4;
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
  block_obj.createBlock();
  block_obj.block_coord = glm::vec3(1,1,0);
  block_obj.along_y = 1;
  //createRectangle();
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
  active_s = active_w = active_a = active_d=0;
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
