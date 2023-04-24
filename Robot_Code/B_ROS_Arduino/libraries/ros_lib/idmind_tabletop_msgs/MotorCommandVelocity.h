#ifndef _ROS_idmind_tabletop_msgs_MotorCommandVelocity_h
#define _ROS_idmind_tabletop_msgs_MotorCommandVelocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorCommandVelocity : public ros::Msg
  {
    public:
      typedef uint8_t _motor_type;
      _motor_type motor;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef uint8_t _play_time_type;
      _play_time_type play_time;
      enum { BASE =  0 };
      enum { NECK =  1 };
      enum { EYES_ROLL =  2 };
      enum { EYES_TILT =  3 };
      enum { EYES_STROKE =  4 };
      enum { MAX_PLAY_TIME =  250 };
      enum { DEFAULT_PLAY_TIME =  200 };

    MotorCommandVelocity():
      motor(0),
      velocity(0),
      play_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      *(outbuffer + offset + 0) = (this->play_time >> (8 * 0)) & 0xFF;
      offset += sizeof(this->play_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      this->play_time =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->play_time);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorCommandVelocity"; };
    virtual const char * getMD5() override { return "816dede76347a0feb06cbcc8c9545e85"; };

  };

}
#endif
