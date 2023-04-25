#ifndef _ROS_idmind_tabletop_msgs_MotorPosFeedback_h
#define _ROS_idmind_tabletop_msgs_MotorPosFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorPosFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _motor_type;
      _motor_type motor;
      typedef float _position_type;
      _position_type position;

    MotorPosFeedback():
      motor(0),
      position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor);
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorPosFeedback"; };
    virtual const char * getMD5() override { return "813720eb109f7a7e86a17381440253eb"; };

  };

}
#endif
