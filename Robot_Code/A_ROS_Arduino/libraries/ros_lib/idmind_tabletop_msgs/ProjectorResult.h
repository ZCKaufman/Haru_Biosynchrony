#ifndef _ROS_idmind_tabletop_msgs_ProjectorResult_h
#define _ROS_idmind_tabletop_msgs_ProjectorResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class ProjectorResult : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef bool _file_played_type;
      _file_played_type file_played;

    ProjectorResult():
      file(""),
      file_played(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      union {
        bool real;
        uint8_t base;
      } u_file_played;
      u_file_played.real = this->file_played;
      *(outbuffer + offset + 0) = (u_file_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->file_played);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      union {
        bool real;
        uint8_t base;
      } u_file_played;
      u_file_played.base = 0;
      u_file_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->file_played = u_file_played.real;
      offset += sizeof(this->file_played);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ProjectorResult"; };
    virtual const char * getMD5() override { return "41822154069ead6cfafdce065675097a"; };

  };

}
#endif
