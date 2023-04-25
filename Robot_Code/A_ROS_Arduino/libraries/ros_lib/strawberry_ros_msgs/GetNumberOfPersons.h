#ifndef _ROS_SERVICE_GetNumberOfPersons_h
#define _ROS_SERVICE_GetNumberOfPersons_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETNUMBEROFPERSONS[] = "strawberry_ros_msgs/GetNumberOfPersons";

  class GetNumberOfPersonsRequest : public ros::Msg
  {
    public:

    GetNumberOfPersonsRequest()
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

    virtual const char * getType() override { return GETNUMBEROFPERSONS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetNumberOfPersonsResponse : public ros::Msg
  {
    public:
      typedef int32_t _value_type;
      _value_type value;

    GetNumberOfPersonsResponse():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return GETNUMBEROFPERSONS; };
    virtual const char * getMD5() override { return "b3087778e93fcd34cc8d65bc54e850d1"; };

  };

  class GetNumberOfPersons {
    public:
    typedef GetNumberOfPersonsRequest Request;
    typedef GetNumberOfPersonsResponse Response;
  };

}
#endif
