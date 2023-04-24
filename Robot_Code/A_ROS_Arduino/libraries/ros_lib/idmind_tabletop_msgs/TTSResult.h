#ifndef _ROS_idmind_tabletop_msgs_TTSResult_h
#define _ROS_idmind_tabletop_msgs_TTSResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TTSResult : public ros::Msg
  {
    public:
      typedef bool _played_type;
      _played_type played;

    TTSResult():
      played(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_played;
      u_played.real = this->played;
      *(outbuffer + offset + 0) = (u_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->played);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_played;
      u_played.base = 0;
      u_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->played = u_played.real;
      offset += sizeof(this->played);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSResult"; };
    virtual const char * getMD5() override { return "639f1b990ee199578ea2e208b3d315f1"; };

  };

}
#endif
