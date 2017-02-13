#include "block.h"

void block_class::createBlock()
{
  static const GLfloat vertex_buffer_data [] = {
 -0.5, 1, 0.5,
 -0.5, -1, 0.5,
 0.5, -1, 0.5,
 -0.5, 1, 0.5,
 0.5, -1, 0.5,
 0.5, 1, 0.5,
 0.5, 1, 0.5,
 0.5, -1, 0.5,
 0.5, -1, -0.5,
 0.5, 1, 0.5,
 0.5, -1, -0.5,
 0.5, 1, -0.5,
 0.5, 1, -0.5,
 0.5, -1, -0.5,
 -0.5, -1, -0.5,
 0.5, 1, -0.5,
 -0.5, -1, -0.5,
 -0.5, 1, -0.5,
 -0.5, 1, -0.5,
 -0.5, -1, -0.5,
 -0.5, -1, 0.5,
 -0.5, 1, -0.5,
 -0.5, -1, 0.5,
 -0.5, 1, 0.5,
 -0.5, 1, -0.5,
 -0.5, 1, 0.5,
 0.5, 1, 0.5,
 -0.5, 1, -0.5,
 0.5, 1, 0.5,
 0.5, 1, -0.5,
 -0.5, -1, 0.5,
 -0.5, -1, -0.5,
 0.5, -1, -0.5,
 -0.5, -1, 0.5,
 0.5, -1, -0.5,
 0.5, -1, 0.5,
 -0.5, 1, 0.5,
 0.5, 1, -0.5,
 0.5, 1, -0.5,
   };

   static const GLfloat color_buffer_data [] = {
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,

 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,

 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,

 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,

 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,

 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,
 0.2, 0.5, 0.9,
 0.1, 0.2, 0.5,
 0.1, 0.2, 0.5,

 0, 0, 0,
 0, 0, 0,
 1, 1, 1,
   };
   block_vao = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void block_class::drawBlock()
{
  glm::vec3 rot_axis =  glm::vec3(0,0,1);
  if(active_d==1 && along_y==1)
  {
    rot_axis = glm::vec3(0,0,1);
    angle+=2;
    if(angle!=90)
    {
      drawBlockObject(block_vao, block_coord, 0, glm::vec3(- 0.5, - 1, 0), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0] - 1.5, block_coord[1] - 0.5, block_coord[2]);
  }
  else if(active_a==1 && along_y==1)
  {
    rot_axis = glm::vec3(0,0,1);
    angle-=2;
    if(angle!=-90)
    {
      drawBlockObject(block_vao, block_coord, 0, glm::vec3( 0.5, - 1, 0), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0] + 1.5, block_coord[1] - 0.5, block_coord[2]);
  }
  else if(active_w==1 && along_y==1)
  {
    rot_axis = glm::vec3(1,0,0);
    angle+=2;
    if(angle!=90)
    {
      drawBlockObject(block_vao, block_coord, 0, glm::vec3( 0, -1, 0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0],  block_coord[1] - 0.5, block_coord[2] + 1.5);
  }
  else if(active_s==1 && along_y==1)
  {
    rot_axis = glm::vec3(1,0,0);
    angle-=2;
    if(angle!=-90)
    {
      drawBlockObject(block_vao, block_coord, 0, glm::vec3( 0, -1, -0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0], block_coord[1] - 0.5, block_coord[2] - 1.5);
  }
  if(active_a==1 && along_x==1)
  {
    rot_axis = glm::vec3(0,0,1);
    angle-=2;
    if(angle!=-90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[1], -block_coord[0], block_coord[2]), 1, glm::vec3( -0.5, -1, 0), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0]+1.5, block_coord[1] + 0.5, block_coord[2]);
  }
  else if(active_d==1 && along_x==1)
  {
    rot_axis = glm::vec3(0,0,1);
    angle+=2;
    if(angle!=90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[1], -block_coord[0], block_coord[2]), 1, glm::vec3( -0.5, 1, 0), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0]-1.5, block_coord[1] + 0.5, block_coord[2]);
  }
  else if(active_w==1 && along_x==1)
  {
    rot_axis = glm::vec3(0,1,0);
    angle-=2;
    if(angle!=-90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[1], -block_coord[0], block_coord[2]), 1, glm::vec3( -0.5, 0, 0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0], block_coord[1], block_coord[2] + 1);
  }
  else if(active_s==1 && along_x==1)
  {
    rot_axis = glm::vec3(0,1,0);
    angle+=2;
    if(angle!=90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[1], -block_coord[0], block_coord[2]), 1, glm::vec3( -0.5, 0, -0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0], block_coord[1], block_coord[2] - 1);
  }
  else if(active_a==1 && along_z==1)
  {
    rot_axis = glm::vec3(0,1,0);
    angle-=2;
    if(angle!=-90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[0], block_coord[2], -block_coord[1]), 2, glm::vec3( 0.5,0, 0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0]+1, block_coord[1], block_coord[2]);
  }
  else if(active_d==1 && along_z==1)
  {
    rot_axis = glm::vec3(0,1,0);
    angle+=2;
    if(angle!=90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[0], block_coord[2], -block_coord[1]), 2, glm::vec3( -0.5,0, 0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0]-1, block_coord[1], block_coord[2]);
  }
  else if(active_w==1 && along_z==1)
  {
    rot_axis = glm::vec3(1,0,0);
    angle+=2;
    if(angle!=90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[0], block_coord[2], -block_coord[1]), 2, glm::vec3( 0,1, 0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0], block_coord[1] + 0.5, block_coord[2] + 1.5);
  }
  else if(active_s==1 && along_z==1)
  {
    rot_axis = glm::vec3(1,0,0);
    angle-=2;
    if(angle!=-90)
    {
      drawBlockObject(block_vao, glm::vec3(block_coord[0], block_coord[2], -block_coord[1]), 2, glm::vec3( 0,-1, 0.5), rot_axis, angle);
      return;
    }
    block_coord = glm::vec3(block_coord[0], block_coord[1] + 0.5, block_coord[2] - 1.5);
  }
  if(angle==90 || angle==-90)
  {
    angle=0;
    if(along_y==1 && (active_d==1 || active_a==1))
    {
      along_y=0;
      along_x=1;
      active_d=0;
      active_a=0;
    }
    if(along_y==1 && (active_w==1 || active_s==1))
    {
      along_y=0;
      along_z=1;
      active_w=0;
      active_s=0;
    }
    if(along_x==1 && (active_d==1 || active_a==1))
    {
      along_y=1;
      along_x=0;
      active_d=0;
      active_a=0;
    }
    if(along_x==1 && (active_w==1 || active_s==1))
    {
      active_w=0;
      active_s=0;
    }
    if(along_z==1 && (active_d==1 || active_a==1))
    {
      active_d=0;
      active_a=0;
    }
    if(along_z==1 && (active_w==1 || active_s==1))
    {
      along_y=1;
      along_z=0;
      active_w=0;
      active_s=0;
    }
  }
  if(along_x==1 && angle==0)
  {
    rot_axis=glm::vec3(0,0,1);
    angle=90;
  }
  else if(along_y==1 && angle==0)
  {
    rot_axis=glm::vec3(1,0,0);
    angle=0;
  }
  else if(along_z==1 && angle==0)
  {
    rot_axis=glm::vec3(1,0,0);
    angle=90;
  }
  drawSingleObject(block_vao, block_coord, rot_axis, angle);
  //angle=0;
}
