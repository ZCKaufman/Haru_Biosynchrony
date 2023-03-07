#ifndef _ROS_idmind_tabletop_msgs_MotorLimits_h
#define _ROS_idmind_tabletop_msgs_MotorLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorLimits : public ros::Msg
  {
    public:
      typedef uint8_t _motor_id_type;
      _motor_id_type motor_id;
      typedef uint16_t _limit_min_type;
      _limit_min_type limit_min;
      typedef uint16_t _limit_max_type;
      _limit_max_type limit_max;

    MotorLimits():
      motor_id(0),
      limit_min(0),
      limit_max(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      *(outbuffer + offset + 0) = (this->limit_min >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limit_min >> (8 * 1)) & 0xFF;
      offset += sizeof(this->limit_min);
      *(outbuffer + offset + 0) = (this->limit_max >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limit_max >> (8 * 1)) & 0xFF;
      offset += sizeof(this->limit_max);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_id);
      this->limit_min =  ((uint16_t) (*(inbuffer + offset)));
      this->limit_min |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->limit_min);
      this->limit_max =  ((uint16_t) (*(inbuffer + offset)));
      this->limit_max |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->limit_max);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorLimits"; };
    virtual const char * getMD5() override { return "934cf0577ace6928c81e51fb24617987"; };

  };

}
#endif
