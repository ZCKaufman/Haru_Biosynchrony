#ifndef _ROS_idmind_tabletop_msgs_ProjectorCommand_h
#define _ROS_idmind_tabletop_msgs_ProjectorCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class ProjectorCommand : public ros::Msg
  {
    public:
      typedef uint8_t _command_type;
      _command_type command;
      typedef const char* _projector_file_type;
      _projector_file_type projector_file;
      typedef uint32_t _start_time_type;
      _start_time_type start_time;
      typedef uint32_t _end_time_type;
      _end_time_type end_time;
      typedef bool _loop_type;
      _loop_type loop;
      typedef uint8_t _skip_factor_type;
      _skip_factor_type skip_factor;
      typedef bool _backlight_type;
      _backlight_type backlight;
      typedef bool _transparency_type;
      _transparency_type transparency;
      typedef bool _wait_to_finish_type;
      _wait_to_finish_type wait_to_finish;
      typedef bool _keep_last_frame_type;
      _keep_last_frame_type keep_last_frame;
      typedef uint8_t _scale_type_type;
      _scale_type_type scale_type;
      enum { PLAY =  0 };
      enum { PAUSE =  1 };
      enum { STOP =  2 };

    ProjectorCommand():
      command(0),
      projector_file(""),
      start_time(0),
      end_time(0),
      loop(0),
      skip_factor(0),
      backlight(0),
      transparency(0),
      wait_to_finish(0),
      keep_last_frame(0),
      scale_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      uint32_t length_projector_file = strlen(this->projector_file);
      varToArr(outbuffer + offset, length_projector_file);
      offset += 4;
      memcpy(outbuffer + offset, this->projector_file, length_projector_file);
      offset += length_projector_file;
      *(outbuffer + offset + 0) = (this->start_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_time);
      *(outbuffer + offset + 0) = (this->end_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_time);
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      *(outbuffer + offset + 0) = (this->skip_factor >> (8 * 0)) & 0xFF;
      offset += sizeof(this->skip_factor);
      union {
        bool real;
        uint8_t base;
      } u_backlight;
      u_backlight.real = this->backlight;
      *(outbuffer + offset + 0) = (u_backlight.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->backlight);
      union {
        bool real;
        uint8_t base;
      } u_transparency;
      u_transparency.real = this->transparency;
      *(outbuffer + offset + 0) = (u_transparency.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->transparency);
      union {
        bool real;
        uint8_t base;
      } u_wait_to_finish;
      u_wait_to_finish.real = this->wait_to_finish;
      *(outbuffer + offset + 0) = (u_wait_to_finish.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wait_to_finish);
      union {
        bool real;
        uint8_t base;
      } u_keep_last_frame;
      u_keep_last_frame.real = this->keep_last_frame;
      *(outbuffer + offset + 0) = (u_keep_last_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->keep_last_frame);
      *(outbuffer + offset + 0) = (this->scale_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->scale_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      uint32_t length_projector_file;
      arrToVar(length_projector_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_projector_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_projector_file-1]=0;
      this->projector_file = (char *)(inbuffer + offset-1);
      offset += length_projector_file;
      this->start_time =  ((uint32_t) (*(inbuffer + offset)));
      this->start_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_time);
      this->end_time =  ((uint32_t) (*(inbuffer + offset)));
      this->end_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end_time);
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      this->skip_factor =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->skip_factor);
      union {
        bool real;
        uint8_t base;
      } u_backlight;
      u_backlight.base = 0;
      u_backlight.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->backlight = u_backlight.real;
      offset += sizeof(this->backlight);
      union {
        bool real;
        uint8_t base;
      } u_transparency;
      u_transparency.base = 0;
      u_transparency.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->transparency = u_transparency.real;
      offset += sizeof(this->transparency);
      union {
        bool real;
        uint8_t base;
      } u_wait_to_finish;
      u_wait_to_finish.base = 0;
      u_wait_to_finish.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wait_to_finish = u_wait_to_finish.real;
      offset += sizeof(this->wait_to_finish);
      union {
        bool real;
        uint8_t base;
      } u_keep_last_frame;
      u_keep_last_frame.base = 0;
      u_keep_last_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->keep_last_frame = u_keep_last_frame.real;
      offset += sizeof(this->keep_last_frame);
      this->scale_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->scale_type);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ProjectorCommand"; };
    virtual const char * getMD5() override { return "2a5173b574d2bd4796a62f99c7e21290"; };

  };

}
#endif
