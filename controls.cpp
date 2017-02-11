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
     	rect_pos.x -= 0.1;
     	break;
    case 'd':
     	rect_pos.x += 0.1;
     	break;
    case 'w':
     	rect_pos.y += 0.1;
     	break;
    case 's':
     	rect_pos.y -= 0.1;
     	break;
    case 'r':
     	rect_pos.z -= 0.1;
     	break;
    case 'f':
     	rect_pos.z += 0.1;
     	break;
    case 'e':
     	rectangle_rotation += 1;
     	break;
    case 'j':
     	floor_pos.x -= 0.1;
     	break;
    case 'l':
     	floor_pos.x += 0.1;
     	break;
    case 'i':
     	floor_pos.y += 0.1;
     	break;
    case 'k':
     	floor_pos.y -= 0.1;
     	break;
    case 'y':
     	floor_pos.z -= 0.1;
     	break;
    case 'h':
     	floor_pos.z += 0.1;
     	break;
    case 'g':
     	floor_rel ^= 1;
     	break;
    case ' ':
      printf("***\n");
     	do_rot ^= 1;
     	break;
		default:
			break;
	}
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
    switch (button) {
        case GLFW_MOUSE_BUTTON_RIGHT:
            if (action == GLFW_RELEASE) {
                rectangle_rot_dir *= -1;
            }
            break;
        default:
            break;
    }
}
