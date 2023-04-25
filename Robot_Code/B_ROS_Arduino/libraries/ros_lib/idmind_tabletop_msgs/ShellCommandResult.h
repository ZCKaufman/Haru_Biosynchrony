#ifndef _ROS_idmind_tabletop_msgs_ShellCommandResult_h
#define _ROS_idmind_tabletop_msgs_ShellCommandResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class ShellCommandResult : public ros::Msg
  {
    public:
      typedef int32_t _exit_status_type;
      _exit_status_type exit_status;
      typedef const char* _info_type;
      _info_type info;

    ShellCommandResult():
      exit_status(0),
      info("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_exit_status;
      u_exit_status.real = this->exit_status;
      *(outbuffer + offset + 0) = (u_exit_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exit_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exit_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exit_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exit_status);
      uint32_t length_info = strlen(this->info);
      varToArr(outbuffer + offset, length_info);
      offset += 4;
      memcpy(outbuffer + offset, this->info, length_info);
      offset += length_info;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_exit_status;
      u_exit_status.base = 0;
      u_exit_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exit_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exit_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exit_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exit_status = u_exit_status.real;
      offset += sizeof(this->exit_status);
      uint32_t length_info;
      arrToVar(length_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info-1]=0;
      this->info = (char *)(inbuffer + offset-1);
      offset += length_info;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ShellCommandResult"; };
    virtual const char * getMD5() override { return "94fe824f9ddfb6f659e5c60f993cce43"; };

  };

}
#endif
