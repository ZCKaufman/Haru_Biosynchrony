#ifndef _ROS_idmind_tabletop_msgs_MotorPosResult_h
#define _ROS_idmind_tabletop_msgs_MotorPosResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorPosResult : public ros::Msg
  {
    public:
      typedef bool _position_reached_type;
      _position_reached_type position_reached;
      typedef uint8_t _motor_type;
      _motor_type motor;
      typedef float _position_type;
      _position_type position;

    MotorPosResult():
      position_reached(0),
      motor(0),
      position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_position_reached;
      u_position_reached.real = this->position_reached;
      *(outbuffer + offset + 0) = (u_position_reached.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position_reached);
      *(outbuffer + offset + 0) = (this->motor >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor);
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_position_reached;
      u_position_reached.base = 0;
      u_position_reached.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->position_reached = u_position_reached.real;
      offset += sizeof(this->position_reached);
      this->motor =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorPosResult"; };
    virtual const char * getMD5() override { return "b145b0c923573656b15064f01bce22a4"; };

  };

}
#endif
