#ifndef _ROS_idmind_tabletop_msgs_MotorPosGoal_h
#define _ROS_idmind_tabletop_msgs_MotorPosGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MotorPosGoal : public ros::Msg
  {
    public:
      typedef float _position_type;
      _position_type position;
      typedef uint8_t _play_time_type;
      _play_time_type play_time;
      typedef bool _relative_type;
      _relative_type relative;
      typedef bool _disable_eyes_roll_sync_type;
      _disable_eyes_roll_sync_type disable_eyes_roll_sync;

    MotorPosGoal():
      position(0),
      play_time(0),
      relative(0),
      disable_eyes_roll_sync(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      *(outbuffer + offset + 0) = (this->play_time >> (8 * 0)) & 0xFF;
      offset += sizeof(this->play_time);
      union {
        bool real;
        uint8_t base;
      } u_relative;
      u_relative.real = this->relative;
      *(outbuffer + offset + 0) = (u_relative.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->relative);
      union {
        bool real;
        uint8_t base;
      } u_disable_eyes_roll_sync;
      u_disable_eyes_roll_sync.real = this->disable_eyes_roll_sync;
      *(outbuffer + offset + 0) = (u_disable_eyes_roll_sync.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_eyes_roll_sync);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
      this->play_time =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->play_time);
      union {
        bool real;
        uint8_t base;
      } u_relative;
      u_relative.base = 0;
      u_relative.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->relative = u_relative.real;
      offset += sizeof(this->relative);
      union {
        bool real;
        uint8_t base;
      } u_disable_eyes_roll_sync;
      u_disable_eyes_roll_sync.base = 0;
      u_disable_eyes_roll_sync.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_eyes_roll_sync = u_disable_eyes_roll_sync.real;
      offset += sizeof(this->disable_eyes_roll_sync);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MotorPosGoal"; };
    virtual const char * getMD5() override { return "ee64923c747292c2fe3d4455625294c6"; };

  };

}
#endif
