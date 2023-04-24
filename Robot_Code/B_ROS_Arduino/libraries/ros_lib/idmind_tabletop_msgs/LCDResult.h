#ifndef _ROS_idmind_tabletop_msgs_LCDResult_h
#define _ROS_idmind_tabletop_msgs_LCDResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LCDResult : public ros::Msg
  {
    public:
      typedef const char* _left_eye_file_type;
      _left_eye_file_type left_eye_file;
      typedef const char* _right_eye_file_type;
      _right_eye_file_type right_eye_file;
      typedef bool _files_played_type;
      _files_played_type files_played;

    LCDResult():
      left_eye_file(""),
      right_eye_file(""),
      files_played(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_left_eye_file = strlen(this->left_eye_file);
      varToArr(outbuffer + offset, length_left_eye_file);
      offset += 4;
      memcpy(outbuffer + offset, this->left_eye_file, length_left_eye_file);
      offset += length_left_eye_file;
      uint32_t length_right_eye_file = strlen(this->right_eye_file);
      varToArr(outbuffer + offset, length_right_eye_file);
      offset += 4;
      memcpy(outbuffer + offset, this->right_eye_file, length_right_eye_file);
      offset += length_right_eye_file;
      union {
        bool real;
        uint8_t base;
      } u_files_played;
      u_files_played.real = this->files_played;
      *(outbuffer + offset + 0) = (u_files_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->files_played);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_left_eye_file;
      arrToVar(length_left_eye_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_left_eye_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_left_eye_file-1]=0;
      this->left_eye_file = (char *)(inbuffer + offset-1);
      offset += length_left_eye_file;
      uint32_t length_right_eye_file;
      arrToVar(length_right_eye_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_right_eye_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_right_eye_file-1]=0;
      this->right_eye_file = (char *)(inbuffer + offset-1);
      offset += length_right_eye_file;
      union {
        bool real;
        uint8_t base;
      } u_files_played;
      u_files_played.base = 0;
      u_files_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->files_played = u_files_played.real;
      offset += sizeof(this->files_played);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDResult"; };
    virtual const char * getMD5() override { return "53332cc5bdac252cff9095cf3b6772c4"; };

  };

}
#endif
