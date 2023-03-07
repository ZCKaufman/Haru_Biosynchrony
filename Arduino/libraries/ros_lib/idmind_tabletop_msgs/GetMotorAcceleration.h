#ifndef _ROS_SERVICE_GetMotorAcceleration_h
#define _ROS_SERVICE_GetMotorAcceleration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char GETMOTORACCELERATION[] = "idmind_tabletop_msgs/GetMotorAcceleration";

  class GetMotorAccelerationRequest : public ros::Msg
  {
    public:
      typedef uint8_t _motor_id_type;
      _motor_id_type motor_id;

    GetMotorAccelerationRequest():
      motor_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_id);
     return offset;
    }

    virtual const char * getType() override { return GETMOTORACCELERATION; };
    virtual const char * getMD5() override { return "ad93bb186d2ed1d75ce7e06ce3ebe190"; };

  };

  class GetMotorAccelerationResponse : public ros::Msg
  {
    public:
      typedef float _ratio_type;
      _ratio_type ratio;
      typedef uint8_t _max_time_type;
      _max_time_type max_time;

    GetMotorAccelerationResponse():
      ratio(0),
      max_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->ratio);
      *(outbuffer + offset + 0) = (this->max_time >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ratio));
      this->max_time =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->max_time);
     return offset;
    }

    virtual const char * getType() override { return GETMOTORACCELERATION; };
    virtual const char * getMD5() override { return "169524d423fa34f040ff708eb154ff94"; };

  };

  class GetMotorAcceleration {
    public:
    typedef GetMotorAccelerationRequest Request;
    typedef GetMotorAccelerationResponse Response;
  };

}
#endif
