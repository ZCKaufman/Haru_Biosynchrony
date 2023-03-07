#ifndef _ROS_SERVICE_SetMotorMode_h
#define _ROS_SERVICE_SetMotorMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETMOTORMODE[] = "idmind_tabletop_msgs/SetMotorMode";

  class SetMotorModeRequest : public ros::Msg
  {
    public:
      typedef uint8_t _motor_id_type;
      _motor_id_type motor_id;
      typedef uint8_t _mode_type;
      _mode_type mode;
      enum { ON =  0 };
      enum { OFF =  1 };
      enum { BRAKE =  2 };

    SetMotorModeRequest():
      motor_id(0),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_id);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
     return offset;
    }

    virtual const char * getType() override { return SETMOTORMODE; };
    virtual const char * getMD5() override { return "9a3dce85c6b8841a8172f98276b8548b"; };

  };

  class SetMotorModeResponse : public ros::Msg
  {
    public:

    SetMotorModeResponse()
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

    virtual const char * getType() override { return SETMOTORMODE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetMotorMode {
    public:
    typedef SetMotorModeRequest Request;
    typedef SetMotorModeResponse Response;
  };

}
#endif
