#ifndef _ROS_idmind_tabletop_msgs_Lips_h
#define _ROS_idmind_tabletop_msgs_Lips_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class Lips : public ros::Msg
  {
    public:
      typedef bool _speaking_type;
      _speaking_type speaking;
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint32_t _x_type;
      _x_type x;
      typedef uint32_t _y_type;
      _y_type y;
      typedef uint32_t _bou_box_width_type;
      _bou_box_width_type bou_box_width;

    Lips():
      speaking(0),
      id(0),
      x(0),
      y(0),
      bou_box_width(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_speaking;
      u_speaking.real = this->speaking;
      *(outbuffer + offset + 0) = (u_speaking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speaking);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      *(outbuffer + offset + 0) = (this->y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      *(outbuffer + offset + 0) = (this->bou_box_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bou_box_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bou_box_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bou_box_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bou_box_width);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_speaking;
      u_speaking.base = 0;
      u_speaking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speaking = u_speaking.real;
      offset += sizeof(this->speaking);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->x =  ((uint32_t) (*(inbuffer + offset)));
      this->x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->x);
      this->y =  ((uint32_t) (*(inbuffer + offset)));
      this->y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->y);
      this->bou_box_width =  ((uint32_t) (*(inbuffer + offset)));
      this->bou_box_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bou_box_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bou_box_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->bou_box_width);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/Lips"; };
    virtual const char * getMD5() override { return "66e2a29e414d6f085749b1b658cc4de9"; };

  };

}
#endif
