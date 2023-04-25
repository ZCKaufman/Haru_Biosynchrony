#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewConfiguration_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSharedContentViewConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSharedContentViewConfiguration : public ros::Msg
  {
    public:
      typedef bool _do_animation_type;
      _do_animation_type do_animation;
      typedef int32_t _animation_mode_type;
      _animation_mode_type animation_mode;
      typedef int32_t _view_mode_type;
      _view_mode_type view_mode;
      typedef int32_t _display_number_type;
      _display_number_type display_number;
      typedef float _animation_time_type;
      _animation_time_type animation_time;
      uint32_t local_users_length;
      typedef std_msgs::String _local_users_type;
      _local_users_type st_local_users;
      _local_users_type * local_users;
      uint32_t remote_users_length;
      typedef std_msgs::String _remote_users_type;
      _remote_users_type st_remote_users;
      _remote_users_type * remote_users;
      typedef float _highlight_focused_time_type;
      _highlight_focused_time_type highlight_focused_time;
      typedef float _remove_others_time_type;
      _remove_others_time_type remove_others_time;
      typedef float _resize_focused_time_type;
      _resize_focused_time_type resize_focused_time;
      typedef float _exit_focused_time_type;
      _exit_focused_time_type exit_focused_time;

    UnityProjectorSharedContentViewConfiguration():
      do_animation(0),
      animation_mode(0),
      view_mode(0),
      display_number(0),
      animation_time(0),
      local_users_length(0), st_local_users(), local_users(nullptr),
      remote_users_length(0), st_remote_users(), remote_users(nullptr),
      highlight_focused_time(0),
      remove_others_time(0),
      resize_focused_time(0),
      exit_focused_time(0)
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
      } u_view_mode;
      u_view_mode.real = this->view_mode;
      *(outbuffer + offset + 0) = (u_view_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_view_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_view_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_view_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->view_mode);
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
      *(outbuffer + offset + 0) = (this->local_users_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->local_users_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->local_users_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->local_users_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_users_length);
      for( uint32_t i = 0; i < local_users_length; i++){
      offset += this->local_users[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->remote_users_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remote_users_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remote_users_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remote_users_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remote_users_length);
      for( uint32_t i = 0; i < remote_users_length; i++){
      offset += this->remote_users[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_highlight_focused_time;
      u_highlight_focused_time.real = this->highlight_focused_time;
      *(outbuffer + offset + 0) = (u_highlight_focused_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_highlight_focused_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_highlight_focused_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_highlight_focused_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->highlight_focused_time);
      union {
        float real;
        uint32_t base;
      } u_remove_others_time;
      u_remove_others_time.real = this->remove_others_time;
      *(outbuffer + offset + 0) = (u_remove_others_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remove_others_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remove_others_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remove_others_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remove_others_time);
      union {
        float real;
        uint32_t base;
      } u_resize_focused_time;
      u_resize_focused_time.real = this->resize_focused_time;
      *(outbuffer + offset + 0) = (u_resize_focused_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resize_focused_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resize_focused_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resize_focused_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resize_focused_time);
      union {
        float real;
        uint32_t base;
      } u_exit_focused_time;
      u_exit_focused_time.real = this->exit_focused_time;
      *(outbuffer + offset + 0) = (u_exit_focused_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exit_focused_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exit_focused_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exit_focused_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exit_focused_time);
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
      } u_view_mode;
      u_view_mode.base = 0;
      u_view_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_view_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_view_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_view_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->view_mode = u_view_mode.real;
      offset += sizeof(this->view_mode);
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
      uint32_t local_users_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      local_users_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      local_users_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      local_users_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->local_users_length);
      if(local_users_lengthT > local_users_length)
        this->local_users = (std_msgs::String*)realloc(this->local_users, local_users_lengthT * sizeof(std_msgs::String));
      local_users_length = local_users_lengthT;
      for( uint32_t i = 0; i < local_users_length; i++){
      offset += this->st_local_users.deserialize(inbuffer + offset);
        memcpy( &(this->local_users[i]), &(this->st_local_users), sizeof(std_msgs::String));
      }
      uint32_t remote_users_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      remote_users_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      remote_users_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      remote_users_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->remote_users_length);
      if(remote_users_lengthT > remote_users_length)
        this->remote_users = (std_msgs::String*)realloc(this->remote_users, remote_users_lengthT * sizeof(std_msgs::String));
      remote_users_length = remote_users_lengthT;
      for( uint32_t i = 0; i < remote_users_length; i++){
      offset += this->st_remote_users.deserialize(inbuffer + offset);
        memcpy( &(this->remote_users[i]), &(this->st_remote_users), sizeof(std_msgs::String));
      }
      union {
        float real;
        uint32_t base;
      } u_highlight_focused_time;
      u_highlight_focused_time.base = 0;
      u_highlight_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_highlight_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_highlight_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_highlight_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->highlight_focused_time = u_highlight_focused_time.real;
      offset += sizeof(this->highlight_focused_time);
      union {
        float real;
        uint32_t base;
      } u_remove_others_time;
      u_remove_others_time.base = 0;
      u_remove_others_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remove_others_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remove_others_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remove_others_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remove_others_time = u_remove_others_time.real;
      offset += sizeof(this->remove_others_time);
      union {
        float real;
        uint32_t base;
      } u_resize_focused_time;
      u_resize_focused_time.base = 0;
      u_resize_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resize_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resize_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resize_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resize_focused_time = u_resize_focused_time.real;
      offset += sizeof(this->resize_focused_time);
      union {
        float real;
        uint32_t base;
      } u_exit_focused_time;
      u_exit_focused_time.base = 0;
      u_exit_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exit_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exit_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exit_focused_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exit_focused_time = u_exit_focused_time.real;
      offset += sizeof(this->exit_focused_time);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSharedContentViewConfiguration"; };
    virtual const char * getMD5() override { return "feb400d9bbbbcf7317cb0402ed8b1fb8"; };

  };

}
#endif
