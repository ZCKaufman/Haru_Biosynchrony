#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorStaticImageConfiguration_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorStaticImageConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorStaticImageConfiguration : public ros::Msg
  {
    public:
      typedef bool _do_animation_type;
      _do_animation_type do_animation;
      typedef bool _coupled_type;
      _coupled_type coupled;
      typedef bool _return_default_type;
      _return_default_type return_default;
      typedef int32_t _animation_mode_type;
      _animation_mode_type animation_mode;
      typedef int32_t _size_mode_type;
      _size_mode_type size_mode;
      typedef int32_t _position_mode_type;
      _position_mode_type position_mode;
      typedef int32_t _display_number_type;
      _display_number_type display_number;
      typedef float _animation_time_type;
      _animation_time_type animation_time;

    UnityProjectorStaticImageConfiguration():
      do_animation(0),
      coupled(0),
      return_default(0),
      animation_mode(0),
      size_mode(0),
      position_mode(0),
      display_number(0),
      animation_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_do_animation;
      u_do_animation.real = this->do_animation;
      *(outbuffer + offset + 0) = (u_do_animation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->do_animation);
      union {
        bool real;
        uint8_t base;
      } u_coupled;
      u_coupled.real = this->coupled;
      *(outbuffer + offset + 0) = (u_coupled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->coupled);
      union {
        bool real;
        uint8_t base;
      } u_return_default;
      u_return_default.real = this->return_default;
      *(outbuffer + offset + 0) = (u_return_default.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->return_default);
      union {
        int32_t real;
        uint32_t base;
      } u_animation_mode;
      u_animation_mode.real = this->animation_mode;
      *(outbuffer + offset + 0) = (u_animation_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_animation_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_animation_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_animation_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->animation_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_size_mode;
      u_size_mode.real = this->size_mode;
      *(outbuffer + offset + 0) = (u_size_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_position_mode;
      u_position_mode.real = this->position_mode;
      *(outbuffer + offset + 0) = (u_position_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_mode);
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
        float real;
        uint32_t base;
      } u_animation_time;
      u_animation_time.real = this->animation_time;
      *(outbuffer + offset + 0) = (u_animation_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_animation_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_animation_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_animation_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->animation_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_do_animation;
      u_do_animation.base = 0;
      u_do_animation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->do_animation = u_do_animation.real;
      offset += sizeof(this->do_animation);
      union {
        bool real;
        uint8_t base;
      } u_coupled;
      u_coupled.base = 0;
      u_coupled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->coupled = u_coupled.real;
      offset += sizeof(this->coupled);
      union {
        bool real;
        uint8_t base;
      } u_return_default;
      u_return_default.base = 0;
      u_return_default.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->return_default = u_return_default.real;
      offset += sizeof(this->return_default);
      union {
        int32_t real;
        uint32_t base;
      } u_animation_mode;
      u_animation_mode.base = 0;
      u_animation_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_animation_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_animation_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_animation_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->animation_mode = u_animation_mode.real;
      offset += sizeof(this->animation_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_size_mode;
      u_size_mode.base = 0;
      u_size_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->size_mode = u_size_mode.real;
      offset += sizeof(this->size_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_position_mode;
      u_position_mode.base = 0;
      u_position_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position_mode = u_position_mode.real;
      offset += sizeof(this->position_mode);
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
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorStaticImageConfiguration"; };
    virtual const char * getMD5() override { return "42394c32c4161ad901a954db3d9cfe5b"; };

  };

}
#endif
