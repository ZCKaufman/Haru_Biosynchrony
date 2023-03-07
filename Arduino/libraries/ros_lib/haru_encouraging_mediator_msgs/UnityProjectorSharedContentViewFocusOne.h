#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewFocusOne_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewFocusOne_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSharedContentViewFocusOne : public ros::Msg
  {
    public:
      typedef bool _do_focus_type;
      _do_focus_type do_focus;
      typedef bool _do_animation_type;
      _do_animation_type do_animation;
      typedef const char* _user_id_type;
      _user_id_type user_id;
      typedef int32_t _side_selector_type;
      _side_selector_type side_selector;
      typedef uint8_t _highlight_r_type;
      _highlight_r_type highlight_r;
      typedef uint8_t _highlight_g_type;
      _highlight_g_type highlight_g;
      typedef uint8_t _highlight_b_type;
      _highlight_b_type highlight_b;
      typedef uint8_t _highlight_a_type;
      _highlight_a_type highlight_a;

    UnityProjectorSharedContentViewFocusOne():
      do_focus(0),
      do_animation(0),
      user_id(""),
      side_selector(0),
      highlight_r(0),
      highlight_g(0),
      highlight_b(0),
      highlight_a(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_do_focus;
      u_do_focus.real = this->do_focus;
      *(outbuffer + offset + 0) = (u_do_focus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->do_focus);
      union {
        bool real;
        uint8_t base;
      } u_do_animation;
      u_do_animation.real = this->do_animation;
      *(outbuffer + offset + 0) = (u_do_animation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->do_animation);
      uint32_t length_user_id = strlen(this->user_id);
      varToArr(outbuffer + offset, length_user_id);
      offset += 4;
      memcpy(outbuffer + offset, this->user_id, length_user_id);
      offset += length_user_id;
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
      *(outbuffer + offset + 0) = (this->highlight_r >> (8 * 0)) & 0xFF;
      offset += sizeof(this->highlight_r);
      *(outbuffer + offset + 0) = (this->highlight_g >> (8 * 0)) & 0xFF;
      offset += sizeof(this->highlight_g);
      *(outbuffer + offset + 0) = (this->highlight_b >> (8 * 0)) & 0xFF;
      offset += sizeof(this->highlight_b);
      *(outbuffer + offset + 0) = (this->highlight_a >> (8 * 0)) & 0xFF;
      offset += sizeof(this->highlight_a);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_do_focus;
      u_do_focus.base = 0;
      u_do_focus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->do_focus = u_do_focus.real;
      offset += sizeof(this->do_focus);
      union {
        bool real;
        uint8_t base;
      } u_do_animation;
      u_do_animation.base = 0;
      u_do_animation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->do_animation = u_do_animation.real;
      offset += sizeof(this->do_animation);
      uint32_t length_user_id;
      arrToVar(length_user_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_id-1]=0;
      this->user_id = (char *)(inbuffer + offset-1);
      offset += length_user_id;
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
      this->highlight_r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->highlight_r);
      this->highlight_g =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->highlight_g);
      this->highlight_b =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->highlight_b);
      this->highlight_a =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->highlight_a);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSharedContentViewFocusOne"; };
    virtual const char * getMD5() override { return "c612af5f03e687f4f619f3966edc21db"; };

  };

}
#endif
