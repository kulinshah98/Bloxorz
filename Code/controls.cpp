#include "controls.h"

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
     // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_C:
                rectangle_rot_status = !rectangle_rot_status;
                break;
            case GLFW_KEY_P:
                break;
            case GLFW_KEY_X:
                // do something ..
                break;
            default:
                break;
        }
    }
    else if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                quit(window);
                break;
            default:
                break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{

	switch (key) {
		case 'Q':
		case 'q':
         quit(window);
         exit(0);
         break;
    case 'a':
      if(active_d==0 && active_w==0 && active_s==0)
      {
        count++;
        active_a=1;
        printf("****\n");
         prev_block_coord=block_obj.block_coord;
        if(angle==90)
        {
          angle=0;
        }
      }
     	break;
    case 'd':
      if(active_a==0 && active_w==0 && active_s==0)
      {
        count++;
         prev_block_coord=block_obj.block_coord;
        active_d=1;
        if(angle==90)
        {
          angle=0;
        }
      }
     	break;
    case 'w':
      if(active_d==0 && active_a==0 && active_s==0)
      {
        count++;
         prev_block_coord=block_obj.block_coord;
        active_w=1;
        if(angle==90)
        {
          angle=0;
        }
      }
     	break;
    case 's':
      if(active_d==0 && active_w==0 && active_a==0)
      {
        count++;
         prev_block_coord=block_obj.block_coord;
        active_s=1;
        if(angle==90)
        {
          angle=0;
        }
      }
     	break;
    case 't':
      //Top View
      view_type = 1;
      break;
    case 'y':
      //Tower View
      view_type = 0;
      break;
    case 'b':
      printf("B\n");
      //Block View
      view_type = 2;
      break;
    case 'f':
      //Follow Cam view
      view_type = 3;
      break;
    case 'h':
      //Helicopter View
      eye = glm::vec3(2,4,-4);
      target = glm::vec3(2,0,0);
      view_type = 4;
      break;
    case 'i':
      target[1]+=0.2;
      break;
    case 'j':
      target[0]-=0.2;
      break;
    case 'k':
      target[1]-=0.2;
      break;
    case 'l':
      target[0]+=0.2;
      break;
    default:
			break;
	}
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
    switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            if (action == GLFW_PRESS) {
                flag=1;
                double x,y;
                glfwGetCursorPos(window, &x, &y);
                prev_pos.first = float(x);
                prev_pos.second = float(y);
            }
            else if(action == GLFW_RELEASE) {
              flag=0;
            }
            break;
        default:
            break;
    }
}

void scrollHandler(GLFWwindow* window, double xpos, double ypos)
{
  cout << xpos << " " << ypos << endl;
  eye[1]=eye[1] + ypos*0.5;
  eye[2]=eye[2] - ypos*0.5;
}

void mouseHandler(GLFWwindow* window, double xpos, double ypos)
{
  double posx, posy;

  glfwGetCursorPos(window, &posx, &posy);
    posx -= 500;
    posy -= 350;
    posx = posx*1.0/500.0;
    posy = -posy*1.0/350.0;
    target += glm::vec3(0.02*posx,-0.02*posy,0);
}
