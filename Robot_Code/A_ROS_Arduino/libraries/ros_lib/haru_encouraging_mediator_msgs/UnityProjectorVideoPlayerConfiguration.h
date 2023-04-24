#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorVideoPlayerConfiguration_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorVideoPlayerConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorVideoPlayerConfiguration : public ros::Msg
  {
    public:
      typedef bool _do_animation_type;
      _do_animation_type do_animation;
      typedef int32_t _size_mode_type;
      _size_mode_type size_mode;
      typedef int32_t _pose_mode_type;
      _pose_mode_type pose_mode;
      typedef bool _coupled_type;
      _coupled_type coupled;
      typedef int32_t _display_number_type;
      _display_number_type display_number;
      typedef float _animation_time_type;
      _animation_time_type animation_time;
      typedef bool _return_default_type;
      _return_default_type return_default;
      typedef bool _show_info_type;
      _show_info_type show_info;
      typedef const char* _info_name_type;
      _info_name_type info_name;
      typedef const char* _info_tag_type;
      _info_tag_type info_tag;
      typedef const char* _info_avatar_file_type;
      _info_avatar_file_type info_avatar_file;

    UnityProjectorVideoPlayerConfiguration():
      do_animation(0),
      size_mode(0),
      pose_mode(0),
      coupled(0),
      display_number(0),
      animation_time(0),
      return_default(0),
      show_info(0),
      info_name(""),
      info_tag(""),
      info_avatar_file("")
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
      } u_pose_mode;
      u_pose_mode.real = this->pose_mode;
      *(outbuffer + offset + 0) = (u_pose_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pose_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pose_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pose_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_mode);
      union {
        bool real;
        uint8_t base;
      } u_coupled;
      u_coupled.real = this->coupled;
      *(outbuffer + offset + 0) = (u_coupled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->coupled);
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
      union {
        bool real;
        uint8_t base;
      } u_return_default;
      u_return_default.real = this->return_default;
      *(outbuffer + offset + 0) = (u_return_default.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->return_default);
      union {
        bool real;
        uint8_t base;
      } u_show_info;
      u_show_info.real = this->show_info;
      *(outbuffer + offset + 0) = (u_show_info.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show_info);
      uint32_t length_info_name = strlen(this->info_name);
      varToArr(outbuffer + offset, length_info_name);
      offset += 4;
      memcpy(outbuffer + offset, this->info_name, length_info_name);
      offset += length_info_name;
      uint32_t length_info_tag = strlen(this->info_tag);
      varToArr(outbuffer + offset, length_info_tag);
      offset += 4;
      memcpy(outbuffer + offset, this->info_tag, length_info_tag);
      offset += length_info_tag;
      uint32_t length_info_avatar_file = strlen(this->info_avatar_file);
      varToArr(outbuffer + offset, length_info_avatar_file);
      offset += 4;
      memcpy(outbuffer + offset, this->info_avatar_file, length_info_avatar_file);
      offset += length_info_avatar_file;
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
      } u_pose_mode;
      u_pose_mode.base = 0;
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pose_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pose_mode = u_pose_mode.real;
      offset += sizeof(this->pose_mode);
      union {
        bool real;
        uint8_t base;
      } u_coupled;
      u_coupled.base = 0;
      u_coupled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->coupled = u_coupled.real;
      offset += sizeof(this->coupled);
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
      union {
        bool real;
        uint8_t base;
      } u_return_default;
      u_return_default.base = 0;
      u_return_default.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->return_default = u_return_default.real;
      offset += sizeof(this->return_default);
      union {
        bool real;
        uint8_t base;
      } u_show_info;
      u_show_info.base = 0;
      u_show_info.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show_info = u_show_info.real;
      offset += sizeof(this->show_info);
      uint32_t length_info_name;
      arrToVar(length_info_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_name-1]=0;
      this->info_name = (char *)(inbuffer + offset-1);
      offset += length_info_name;
      uint32_t length_info_tag;
      arrToVar(length_info_tag, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_tag; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_tag-1]=0;
      this->info_tag = (char *)(inbuffer + offset-1);
      offset += length_info_tag;
      uint32_t length_info_avatar_file;
      arrToVar(length_info_avatar_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_avatar_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_avatar_file-1]=0;
      this->info_avatar_file = (char *)(inbuffer + offset-1);
      offset += length_info_avatar_file;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorVideoPlayerConfiguration"; };
    virtual const char * getMD5() override { return "6f13c78177ad72243a55c8439003e570"; };

  };

}
#endif
