#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewShow_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewShow_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSharedContentViewShow : public ros::Msg
  {
    public:
      typedef bool _show_type;
      _show_type show;
      typedef int32_t _side_selector_type;
      _side_selector_type side_selector;

    UnityProjectorSharedContentViewShow():
      show(0),
      side_selector(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show;
      u_show.real = this->show;
      *(outbuffer + offset + 0) = (u_show.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show);
      union {
        int32_t real;
        uint32_t base;
      } u_side_selector;
      u_side_selector.real = this->side_selector;
      *(outbuffer + offset + 0) = (u_side_selector.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_side_selector.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_side_selector.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_side_selector.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->side_selector);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show;
      u_show.base = 0;
      u_show.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show = u_show.real;
      offset += sizeof(this->show);
      union {
        int32_t real;
        uint32_t base;
      } u_side_selector;
      u_side_selector.base = 0;
      u_side_selector.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_side_selector.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_side_selector.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_side_selector.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->side_selector = u_side_selector.real;
      offset += sizeof(this->side_selector);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSharedContentViewShow"; };
    virtual const char * getMD5() override { return "44ff3a2fee4b65c88b51bbac2c89735f"; };

  };

}
#endif
