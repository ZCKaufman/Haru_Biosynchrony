#ifndef _ROS_SERVICE_SetMotorAcceleration_h
#define _ROS_SERVICE_SetMotorAcceleration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETMOTORACCELERATION[] = "idmind_tabletop_msgs/SetMotorAcceleration";

  class SetMotorAccelerationRequest : public ros::Msg
  {
    public:
      typedef uint8_t _motor_id_type;
      _motor_id_type motor_id;
      typedef float _ratio_type;
      _ratio_type ratio;
      typedef uint8_t _max_time_type;
      _max_time_type max_time;

    SetMotorAccelerationRequest():
      motor_id(0),
      ratio(0),
      max_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->ratio);
      *(outbuffer + offset + 0) = (this->max_time >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ratio));
      this->max_time =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->max_time);
     return offset;
    }

    virtual const char * getType() override { return SETMOTORACCELERATION; };
    virtual const char * getMD5() override { return "dc8493705de536952bca98dc8bd30601"; };

  };

  class SetMotorAccelerationResponse : public ros::Msg
  {
    public:

    SetMotorAccelerationResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SETMOTORACCELERATION; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetMotorAcceleration {
    public:
    typedef SetMotorAccelerationRequest Request;
    typedef SetMotorAccelerationResponse Response;
  };

}
#endif
