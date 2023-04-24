#ifndef _ROS_SERVICE_SetPath_h
#define _ROS_SERVICE_SetPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETPATH[] = "idmind_tabletop_msgs/SetPath";

  class SetPathRequest : public ros::Msg
  {
    public:
      typedef const char* _path_type;
      _path_type path;

    SetPathRequest():
      path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_path = strlen(this->path);
      varToArr(outbuffer + offset, length_path);
      offset += 4;
      memcpy(outbuffer + offset, this->path, length_path);
      offset += length_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_path;
      arrToVar(length_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_path-1]=0;
      this->path = (char *)(inbuffer + offset-1);
      offset += length_path;
     return offset;
    }

    virtual const char * getType() override { return SETPATH; };
    virtual const char * getMD5() override { return "1d00cd540af97efeb6b1589112fab63e"; };

  };

  class SetPathResponse : public ros::Msg
  {
    public:

    SetPathResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SETPATH; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetPath {
    public:
    typedef SetPathRequest Request;
    typedef SetPathResponse Response;
  };

}
#endif
