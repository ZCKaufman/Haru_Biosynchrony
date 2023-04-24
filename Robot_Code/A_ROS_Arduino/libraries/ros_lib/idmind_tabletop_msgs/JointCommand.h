#ifndef _ROS_idmind_tabletop_msgs_JointCommand_h
#define _ROS_idmind_tabletop_msgs_JointCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class JointCommand : public ros::Msg
  {
    public:
      typedef uint8_t _motor_type;
      _motor_type motor;
      typedef float _position_type;
      _position_type position;
      typedef uint8_t _control_mode_type;
      _control_mode_type control_mode;
      enum { BASE =  0 };
      enum { NECK =  1 };
      enum { EYES_ROLL =  2 };
      enum { EYES_TILT =  3 };
      enum { EYES_STROKE =  4 };
      enum { POS_CONTROL =  0 };
      enum { VEL_CONTROL =  1 };

    JointCommand():
      motor(0),
      position(0),
      control_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor);
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      *(outbuffer + offset + 0) = (this->control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
      this->control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/JointCommand"; };
    virtual const char * getMD5() override { return "c1a39a5a9e9b3dd2901fc358700fbb57"; };

  };

}
#endif
