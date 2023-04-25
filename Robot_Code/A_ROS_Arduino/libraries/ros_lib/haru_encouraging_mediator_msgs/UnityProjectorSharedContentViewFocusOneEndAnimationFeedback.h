#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewFocusOneEndAnimationFeedback_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewFocusOneEndAnimationFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSharedContentViewFocusOneEndAnimationFeedback : public ros::Msg
  {
    public:
      typedef bool _finished_animation_type;
      _finished_animation_type finished_animation;

    UnityProjectorSharedContentViewFocusOneEndAnimationFeedback():
      finished_animation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_finished_animation;
      u_finished_animation.real = this->finished_animation;
      *(outbuffer + offset + 0) = (u_finished_animation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->finished_animation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_finished_animation;
      u_finished_animation.base = 0;
      u_finished_animation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->finished_animation = u_finished_animation.real;
      offset += sizeof(this->finished_animation);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSharedContentViewFocusOneEndAnimationFeedback"; };
    virtual const char * getMD5() override { return "4e426a7d95541b2e57f628191183612d"; };

  };

}
#endif
