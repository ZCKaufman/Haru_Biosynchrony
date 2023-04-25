#ifndef _ROS_SERVICE_SetRoutineFile_h
#define _ROS_SERVICE_SetRoutineFile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETROUTINEFILE[] = "idmind_tabletop_msgs/SetRoutineFile";

  class SetRoutineFileRequest : public ros::Msg
  {
    public:
      typedef const char* _routine_file_type;
      _routine_file_type routine_file;

    SetRoutineFileRequest():
      routine_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_routine_file = strlen(this->routine_file);
      varToArr(outbuffer + offset, length_routine_file);
      offset += 4;
      memcpy(outbuffer + offset, this->routine_file, length_routine_file);
      offset += length_routine_file;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_routine_file;
      arrToVar(length_routine_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routine_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routine_file-1]=0;
      this->routine_file = (char *)(inbuffer + offset-1);
      offset += length_routine_file;
     return offset;
    }

    virtual const char * getType() override { return SETROUTINEFILE; };
    virtual const char * getMD5() override { return "0f08e3549fa8397dda175011658911c2"; };

  };

  class SetRoutineFileResponse : public ros::Msg
  {
    public:

    SetRoutineFileResponse()
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

    virtual const char * getType() override { return SETROUTINEFILE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetRoutineFile {
    public:
    typedef SetRoutineFileRequest Request;
    typedef SetRoutineFileResponse Response;
  };

}
#endif
