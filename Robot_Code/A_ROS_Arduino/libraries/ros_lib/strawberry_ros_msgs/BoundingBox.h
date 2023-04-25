#ifndef _ROS_strawberry_ros_msgs_BoundingBox_h
#define _ROS_strawberry_ros_msgs_BoundingBox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class BoundingBox : public ros::Msg
  {
    public:
      typedef const char* _camera_id_type;
      _camera_id_type camera_id;
      typedef uint32_t _camera_img_width_type;
      _camera_img_width_type camera_img_width;
      typedef uint32_t _camera_img_height_type;
      _camera_img_height_type camera_img_height;
      typedef float _camera_focal_length_type;
      _camera_focal_length_type camera_focal_length;
      typedef uint32_t _top_type;
      _top_type top;
      typedef uint32_t _bottom_type;
      _bottom_type bottom;
      typedef uint32_t _right_type;
      _right_type right;
      typedef uint32_t _left_type;
      _left_type left;

    BoundingBox():
      camera_id(""),
      camera_img_width(0),
      camera_img_height(0),
      camera_focal_length(0),
      top(0),
      bottom(0),
      right(0),
      left(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_camera_id = strlen(this->camera_id);
      varToArr(outbuffer + offset, length_camera_id);
      offset += 4;
      memcpy(outbuffer + offset, this->camera_id, length_camera_id);
      offset += length_camera_id;
      *(outbuffer + offset + 0) = (this->camera_img_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->camera_img_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->camera_img_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->camera_img_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera_img_width);
      *(outbuffer + offset + 0) = (this->camera_img_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->camera_img_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->camera_img_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->camera_img_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera_img_height);
      union {
        float real;
        uint32_t base;
      } u_camera_focal_length;
      u_camera_focal_length.real = this->camera_focal_length;
      *(outbuffer + offset + 0) = (u_camera_focal_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_camera_focal_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_camera_focal_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_camera_focal_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera_focal_length);
      *(outbuffer + offset + 0) = (this->top >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->top >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->top >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->top >> (8 * 3)) & 0xFF;
      offset += sizeof(this->top);
      *(outbuffer + offset + 0) = (this->bottom >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bottom >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bottom >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bottom >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bottom);
      *(outbuffer + offset + 0) = (this->right >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->right >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->right >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right);
      *(outbuffer + offset + 0) = (this->left >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->left >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->left >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_camera_id;
      arrToVar(length_camera_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_id-1]=0;
      this->camera_id = (char *)(inbuffer + offset-1);
      offset += length_camera_id;
      this->camera_img_width =  ((uint32_t) (*(inbuffer + offset)));
      this->camera_img_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->camera_img_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->camera_img_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->camera_img_width);
      this->camera_img_height =  ((uint32_t) (*(inbuffer + offset)));
      this->camera_img_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->camera_img_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->camera_img_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->camera_img_height);
      union {
        float real;
        uint32_t base;
      } u_camera_focal_length;
      u_camera_focal_length.base = 0;
      u_camera_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_camera_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_camera_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_camera_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->camera_focal_length = u_camera_focal_length.real;
      offset += sizeof(this->camera_focal_length);
      this->top =  ((uint32_t) (*(inbuffer + offset)));
      this->top |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->top |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->top |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->top);
      this->bottom =  ((uint32_t) (*(inbuffer + offset)));
      this->bottom |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bottom |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bottom |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->bottom);
      this->right =  ((uint32_t) (*(inbuffer + offset)));
      this->right |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->right |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->right);
      this->left =  ((uint32_t) (*(inbuffer + offset)));
      this->left |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->left |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->left);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/BoundingBox"; };
    virtual const char * getMD5() override { return "42a828f46e4654736307ba8233f86874"; };

  };

}
#endif
