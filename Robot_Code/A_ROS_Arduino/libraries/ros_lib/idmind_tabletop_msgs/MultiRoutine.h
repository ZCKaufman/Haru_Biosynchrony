#ifndef _ROS_SERVICE_MultiRoutine_h
#define _ROS_SERVICE_MultiRoutine_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char MULTIROUTINE[] = "idmind_tabletop_msgs/MultiRoutine";

  class MultiRoutineRequest : public ros::Msg
  {
    public:
      typedef const char* _routine_command_type;
      _routine_command_type routine_command;

    MultiRoutineRequest():
      routine_command("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_routine_command = strlen(this->routine_command);
      varToArr(outbuffer + offset, length_routine_command);
      offset += 4;
      memcpy(outbuffer + offset, this->routine_command, length_routine_command);
      offset += length_routine_command;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_routine_command;
      arrToVar(length_routine_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routine_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routine_command-1]=0;
      this->routine_command = (char *)(inbuffer + offset-1);
      offset += length_routine_command;
     return offset;
    }

    virtual const char * getType() override { return MULTIROUTINE; };
    virtual const char * getMD5() override { return "69460d3dea175758c910538ad5384bcf"; };

  };

  class MultiRoutineResponse : public ros::Msg
  {
    public:

    MultiRoutineResponse()
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

    virtual const char * getType() override { return MULTIROUTINE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class MultiRoutine {
    public:
    typedef MultiRoutineRequest Request;
    typedef MultiRoutineResponse Response;
  };

}
#endif
