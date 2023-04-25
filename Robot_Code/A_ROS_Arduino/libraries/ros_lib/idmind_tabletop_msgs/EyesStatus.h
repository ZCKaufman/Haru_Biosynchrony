#ifndef _ROS_idmind_tabletop_msgs_EyesStatus_h
#define _ROS_idmind_tabletop_msgs_EyesStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class EyesStatus : public ros::Msg
  {
    public:
      typedef uint8_t _eye_type;
      _eye_type eye;
      typedef float _pos_x_type;
      _pos_x_type pos_x;
      typedef float _pos_y_type;
      _pos_y_type pos_y;
      typedef bool _is_moving_type;
      _is_moving_type is_moving;
      typedef float _progress_type;
      _progress_type progress;
      enum { LEFT_EYE =  0 };
      enum { RIGHT_EYE =  1 };

    EyesStatus():
      eye(0),
      pos_x(0),
      pos_y(0),
      is_moving(0),
      progress(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->eye >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eye);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_y);
      union {
        bool real;
        uint8_t base;
      } u_is_moving;
      u_is_moving.real = this->is_moving;
      *(outbuffer + offset + 0) = (u_is_moving.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_moving);
      offset += serializeAvrFloat64(outbuffer + offset, this->progress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->eye =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->eye);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_y));
      union {
        bool real;
        uint8_t base;
      } u_is_moving;
      u_is_moving.base = 0;
      u_is_moving.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_moving = u_is_moving.real;
      offset += sizeof(this->is_moving);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->progress));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/EyesStatus"; };
    virtual const char * getMD5() override { return "0ee0470f62439a53994f277f3dd2db96"; };

  };

}
#endif
