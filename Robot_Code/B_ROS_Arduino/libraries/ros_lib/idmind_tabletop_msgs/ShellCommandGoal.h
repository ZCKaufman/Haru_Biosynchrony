#ifndef _ROS_idmind_tabletop_msgs_ShellCommandGoal_h
#define _ROS_idmind_tabletop_msgs_ShellCommandGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class ShellCommandGoal : public ros::Msg
  {
    public:
      typedef const char* _command_type;
      _command_type command;

    ShellCommandGoal():
      command("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_command = strlen(this->command);
      varToArr(outbuffer + offset, length_command);
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_command;
      arrToVar(length_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ShellCommandGoal"; };
    virtual const char * getMD5() override { return "cba5e21e920a3a2b7b375cb65b64cdea"; };

  };

}
#endif
