#ifndef _ROS_SERVICE_GetMotorsLimits_h
#define _ROS_SERVICE_GetMotorsLimits_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/MotorLimits.h"

namespace idmind_tabletop_msgs
{

static const char GETMOTORSLIMITS[] = "idmind_tabletop_msgs/GetMotorsLimits";

  class GetMotorsLimitsRequest : public ros::Msg
  {
    public:

    GetMotorsLimitsRequest()
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

    virtual const char * getType() override { return GETMOTORSLIMITS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetMotorsLimitsResponse : public ros::Msg
  {
    public:
      uint32_t motors_limits_length;
      typedef idmind_tabletop_msgs::MotorLimits _motors_limits_type;
      _motors_limits_type st_motors_limits;
      _motors_limits_type * motors_limits;
      enum { NUM_MOTORS =  5 };

    GetMotorsLimitsResponse():
      motors_limits_length(0), st_motors_limits(), motors_limits(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motors_limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motors_limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motors_limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motors_limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motors_limits_length);
      for( uint32_t i = 0; i < motors_limits_length; i++){
      offset += this->motors_limits[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t motors_limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motors_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motors_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motors_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motors_limits_length);
      if(motors_limits_lengthT > motors_limits_length)
        this->motors_limits = (idmind_tabletop_msgs::MotorLimits*)realloc(this->motors_limits, motors_limits_lengthT * sizeof(idmind_tabletop_msgs::MotorLimits));
      motors_limits_length = motors_limits_lengthT;
      for( uint32_t i = 0; i < motors_limits_length; i++){
      offset += this->st_motors_limits.deserialize(inbuffer + offset);
        memcpy( &(this->motors_limits[i]), &(this->st_motors_limits), sizeof(idmind_tabletop_msgs::MotorLimits));
      }
     return offset;
    }

    virtual const char * getType() override { return GETMOTORSLIMITS; };
    virtual const char * getMD5() override { return "ddf0e63e5c3c977e8f87acff85235958"; };

  };

  class GetMotorsLimits {
    public:
    typedef GetMotorsLimitsRequest Request;
    typedef GetMotorsLimitsResponse Response;
  };

}
#endif
