#ifndef _ROS_idmind_tabletop_msgs_TTSCommand_h
#define _ROS_idmind_tabletop_msgs_TTSCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace idmind_tabletop_msgs
{

  class TTSCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _message_type;
      _message_type message;
      typedef bool _disable_lipsync_type;
      _disable_lipsync_type disable_lipsync;

    TTSCommand():
      header(),
      message(""),
      disable_lipsync(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_disable_lipsync;
      u_disable_lipsync.real = this->disable_lipsync;
      *(outbuffer + offset + 0) = (u_disable_lipsync.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_lipsync);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_disable_lipsync;
      u_disable_lipsync.base = 0;
      u_disable_lipsync.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_lipsync = u_disable_lipsync.real;
      offset += sizeof(this->disable_lipsync);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSCommand"; };
    virtual const char * getMD5() override { return "120a9210f3ea622dac0b0682e1534fb4"; };

  };

}
#endif
