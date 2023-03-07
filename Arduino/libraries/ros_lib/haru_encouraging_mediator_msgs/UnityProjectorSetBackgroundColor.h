#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetBackgroundColor_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetBackgroundColor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetBackgroundColor : public ros::Msg
  {
    public:
      typedef uint8_t _r_type;
      _r_type r;
      typedef uint8_t _g_type;
      _g_type g;
      typedef uint8_t _b_type;
      _b_type b;
      typedef uint8_t _a_type;
      _a_type a;
      typedef int32_t _display_number_type;
      _display_number_type display_number;
      typedef bool _do_animation_type;
      _do_animation_type do_animation;
      typedef float _animation_time_type;
      _animation_time_type animation_time;
      typedef const char* _pattern_file_type;
      _pattern_file_type pattern_file;

    UnityProjectorSetBackgroundColor():
      r(0),
      g(0),
      b(0),
      a(0),
      display_number(0),
      do_animation(0),
      animation_time(0),
      pattern_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->r >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r);
      *(outbuffer + offset + 0) = (this->g >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g);
      *(outbuffer + offset + 0) = (this->b >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b);
      *(outbuffer + offset + 0) = (this->a >> (8 * 0)) & 0xFF;
      offset += sizeof(this->a);
      union {
        int32_t real;
        uint32_t base;
      } u_display_number;
      u_display_number.real = this->display_number;
      *(outbuffer + offset + 0) = (u_display_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_display_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_display_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_display_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->display_number);
      union {
        bool real;
        uint8_t base;
      } u_do_animation;
      u_do_animation.real = this->do_animation;
      *(outbuffer + offset + 0) = (u_do_animation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->do_animation);
      union {
        float real;
        uint32_t base;
      } u_animation_time;
      u_animation_time.real = this->animation_time;
      *(outbuffer + offset + 0) = (u_animation_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_animation_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_animation_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_animation_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->animation_time);
      uint32_t length_pattern_file = strlen(this->pattern_file);
      varToArr(outbuffer + offset, length_pattern_file);
      offset += 4;
      memcpy(outbuffer + offset, this->pattern_file, length_pattern_file);
      offset += length_pattern_file;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->r);
      this->g =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->g);
      this->b =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->b);
      this->a =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->a);
      union {
        int32_t real;
        uint32_t base;
      } u_display_number;
      u_display_number.base = 0;
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_display_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->display_number = u_display_number.real;
      offset += sizeof(this->display_number);
      union {
        bool real;
        uint8_t base;
      } u_do_animation;
      u_do_animation.base = 0;
      u_do_animation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->do_animation = u_do_animation.real;
      offset += sizeof(this->do_animation);
      union {
        float real;
        uint32_t base;
      } u_animation_time;
      u_animation_time.base = 0;
      u_animation_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_animation_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_animation_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_animation_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->animation_time = u_animation_time.real;
      offset += sizeof(this->animation_time);
      uint32_t length_pattern_file;
      arrToVar(length_pattern_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pattern_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pattern_file-1]=0;
      this->pattern_file = (char *)(inbuffer + offset-1);
      offset += length_pattern_file;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetBackgroundColor"; };
    virtual const char * getMD5() override { return "3e1f499e4fb41298cacbd3138fdb631c"; };

  };

}
#endif
