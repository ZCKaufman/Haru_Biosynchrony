#ifndef _ROS_idmind_tabletop_msgs_LCDPlaybackCommand_h
#define _ROS_idmind_tabletop_msgs_LCDPlaybackCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LCDPlaybackCommand : public ros::Msg
  {
    public:
      typedef uint8_t _command_type;
      _command_type command;
      typedef uint32_t _entry_index_type;
      _entry_index_type entry_index;
      enum { STOP =  0 };
      enum { NEXT =  1 };
      enum { PREVIOUS =  2 };
      enum { JUMP_TO =  3 };

    LCDPlaybackCommand():
      command(0),
      entry_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      *(outbuffer + offset + 0) = (this->entry_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entry_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entry_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entry_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entry_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      this->entry_index =  ((uint32_t) (*(inbuffer + offset)));
      this->entry_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->entry_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->entry_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->entry_index);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDPlaybackCommand"; };
    virtual const char * getMD5() override { return "c2c7d249e3196f67f9d84be9f4ec4f97"; };

  };

}
#endif
