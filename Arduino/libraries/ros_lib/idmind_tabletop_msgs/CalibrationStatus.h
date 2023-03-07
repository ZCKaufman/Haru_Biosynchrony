#ifndef _ROS_idmind_tabletop_msgs_CalibrationStatus_h
#define _ROS_idmind_tabletop_msgs_CalibrationStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class CalibrationStatus : public ros::Msg
  {
    public:
      typedef bool _base_centered_type;
      _base_centered_type base_centered;
      typedef uint16_t _base_servo_value_type;
      _base_servo_value_type base_servo_value;
      typedef float _base_pos_value_type;
      _base_pos_value_type base_pos_value;

    CalibrationStatus():
      base_centered(0),
      base_servo_value(0),
      base_pos_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_base_centered;
      u_base_centered.real = this->base_centered;
      *(outbuffer + offset + 0) = (u_base_centered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->base_centered);
      *(outbuffer + offset + 0) = (this->base_servo_value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->base_servo_value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->base_servo_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->base_pos_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_base_centered;
      u_base_centered.base = 0;
      u_base_centered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->base_centered = u_base_centered.real;
      offset += sizeof(this->base_centered);
      this->base_servo_value =  ((uint16_t) (*(inbuffer + offset)));
      this->base_servo_value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->base_servo_value);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->base_pos_value));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/CalibrationStatus"; };
    virtual const char * getMD5() override { return "58ebea3457d810a2fc1c38a469cffc63"; };

  };

}
#endif
