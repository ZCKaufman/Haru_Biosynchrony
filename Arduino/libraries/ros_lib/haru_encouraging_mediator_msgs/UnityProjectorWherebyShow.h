#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorWherebyShow_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorWherebyShow_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorWherebyShow : public ros::Msg
  {
    public:
      typedef bool _show_teleconference_type;
      _show_teleconference_type show_teleconference;

    UnityProjectorWherebyShow():
      show_teleconference(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show_teleconference;
      u_show_teleconference.real = this->show_teleconference;
      *(outbuffer + offset + 0) = (u_show_teleconference.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show_teleconference);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show_teleconference;
      u_show_teleconference.base = 0;
      u_show_teleconference.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show_teleconference = u_show_teleconference.real;
      offset += sizeof(this->show_teleconference);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorWherebyShow"; };
    virtual const char * getMD5() override { return "eb26398abc6dc3b31e156815a7f41904"; };

  };

}
#endif
