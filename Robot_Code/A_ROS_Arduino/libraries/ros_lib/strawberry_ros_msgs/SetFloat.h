#ifndef _ROS_SERVICE_SetFloat_h
#define _ROS_SERVICE_SetFloat_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char SETFLOAT[] = "strawberry_ros_msgs/SetFloat";

  class SetFloatRequest : public ros::Msg
  {
    public:
      typedef float _value_type;
      _value_type value;

    SetFloatRequest():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    virtual const char * getType() override { return SETFLOAT; };
    virtual const char * getMD5() override { return "1b1594d2b74931ef8fe7be8e2d594455"; };

  };

  class SetFloatResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    SetFloatResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return SETFLOAT; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SetFloat {
    public:
    typedef SetFloatRequest Request;
    typedef SetFloatResponse Response;
  };

}
#endif
