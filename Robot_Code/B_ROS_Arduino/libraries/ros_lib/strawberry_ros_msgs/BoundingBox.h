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
    virtual const char * getMD5() override { return "84d1e990d1f294f77913746f85100f74"; };

  };

}
#endif
