#ifndef _ROS_idmind_tabletop_msgs_EyesCommand_h
#define _ROS_idmind_tabletop_msgs_EyesCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class EyesCommand : public ros::Msg
  {
    public:
      typedef uint8_t _eye_type;
      _eye_type eye;
      typedef float _pos_x_type;
      _pos_x_type pos_x;
      typedef float _pos_y_type;
      _pos_y_type pos_y;
      typedef uint32_t _play_time_type;
      _play_time_type play_time;
      typedef bool _smooth_type;
      _smooth_type smooth;
      enum { LEFT_EYE =  0 };
      enum { RIGHT_EYE =  1 };
      enum { BOTH_EYES =  2 };
      enum { EYE_WIDTH =  720 };
      enum { EYE_HEIGHT =  720 };

    EyesCommand():
      eye(0),
      pos_x(0),
      pos_y(0),
      play_time(0),
      smooth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->eye >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eye);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_y);
      *(outbuffer + offset + 0) = (this->play_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->play_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->play_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->play_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->play_time);
      union {
        bool real;
        uint8_t base;
      } u_smooth;
      u_smooth.real = this->smooth;
      *(outbuffer + offset + 0) = (u_smooth.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->smooth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->eye =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->eye);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_y));
      this->play_time =  ((uint32_t) (*(inbuffer + offset)));
      this->play_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->play_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->play_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->play_time);
      union {
        bool real;
        uint8_t base;
      } u_smooth;
      u_smooth.base = 0;
      u_smooth.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->smooth = u_smooth.real;
      offset += sizeof(this->smooth);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/EyesCommand"; };
    virtual const char * getMD5() override { return "ed5526adbf5557b9d94e179b41bb57cb"; };

  };

}
#endif
