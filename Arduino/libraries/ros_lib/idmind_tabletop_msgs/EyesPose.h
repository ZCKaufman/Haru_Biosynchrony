#ifndef _ROS_idmind_tabletop_msgs_EyesPose_h
#define _ROS_idmind_tabletop_msgs_EyesPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class EyesPose : public ros::Msg
  {
    public:
      typedef uint8_t _eye_type;
      _eye_type eye;
      typedef float _pos_x_type;
      _pos_x_type pos_x;
      typedef float _pos_y_type;
      _pos_y_type pos_y;
      enum { LEFT_EYE =  0 };
      enum { RIGHT_EYE =  1 };
      enum { EYE_WIDTH =  720 };
      enum { EYE_HEIGHT =  720 };

    EyesPose():
      eye(0),
      pos_x(0),
      pos_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->eye >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eye);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->eye =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->eye);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_y));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/EyesPose"; };
    virtual const char * getMD5() override { return "c21bc5be605ceed3c2aee5d10e5097fa"; };

  };

}
#endif
