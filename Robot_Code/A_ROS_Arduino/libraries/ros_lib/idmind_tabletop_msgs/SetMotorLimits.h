#ifndef _ROS_SERVICE_SetMotorLimits_h
#define _ROS_SERVICE_SetMotorLimits_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/MotorLimits.h"

namespace idmind_tabletop_msgs
{

static const char SETMOTORLIMITS[] = "idmind_tabletop_msgs/SetMotorLimits";

  class SetMotorLimitsRequest : public ros::Msg
  {
    public:
      typedef idmind_tabletop_msgs::MotorLimits _limits_type;
      _limits_type limits;

    SetMotorLimitsRequest():
      limits()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->limits.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->limits.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETMOTORLIMITS; };
    virtual const char * getMD5() override { return "646ff52f3d1f5045999e438d8b3cefc2"; };

  };

  class SetMotorLimitsResponse : public ros::Msg
  {
    public:
      uint32_t updated_limits_length;
      typedef idmind_tabletop_msgs::MotorLimits _updated_limits_type;
      _updated_limits_type st_updated_limits;
      _updated_limits_type * updated_limits;
      enum { NUM_MOTORS =  5 };

    SetMotorLimitsResponse():
      updated_limits_length(0), st_updated_limits(), updated_limits(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->updated_limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->updated_limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->updated_limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->updated_limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->updated_limits_length);
      for( uint32_t i = 0; i < updated_limits_length; i++){
      offset += this->updated_limits[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t updated_limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      updated_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      updated_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      updated_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->updated_limits_length);
      if(updated_limits_lengthT > updated_limits_length)
        this->updated_limits = (idmind_tabletop_msgs::MotorLimits*)realloc(this->updated_limits, updated_limits_lengthT * sizeof(idmind_tabletop_msgs::MotorLimits));
      updated_limits_length = updated_limits_lengthT;
      for( uint32_t i = 0; i < updated_limits_length; i++){
      offset += this->st_updated_limits.deserialize(inbuffer + offset);
        memcpy( &(this->updated_limits[i]), &(this->st_updated_limits), sizeof(idmind_tabletop_msgs::MotorLimits));
      }
     return offset;
    }

    virtual const char * getType() override { return SETMOTORLIMITS; };
    virtual const char * getMD5() override { return "dcf6eed9056dedabedc9da427b47b37f"; };

  };

  class SetMotorLimits {
    public:
    typedef SetMotorLimitsRequest Request;
    typedef SetMotorLimitsResponse Response;
  };

}
#endif
