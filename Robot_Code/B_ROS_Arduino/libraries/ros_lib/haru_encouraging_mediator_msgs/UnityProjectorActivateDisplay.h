#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorActivateDisplay_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorActivateDisplay_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorActivateDisplay : public ros::Msg
  {
    public:
      typedef int32_t _display_number_type;
      _display_number_type display_number;

    UnityProjectorActivateDisplay():
      display_number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_display_number;
      u_display_number.real = this->display_number;
      *(outbuffer + offset + 0) = (u_display_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_display_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_display_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_display_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->display_number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_display_number;
      u_display_number.base = 0;
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->display_number = u_display_number.real;
      offset += sizeof(this->display_number);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorActivateDisplay"; };
    virtual const char * getMD5() override { return "69737c6a0b5675ed1c0328e44d56b87b"; };

  };

}
#endif
