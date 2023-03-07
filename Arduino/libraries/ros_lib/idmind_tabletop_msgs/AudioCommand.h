#ifndef _ROS_idmind_tabletop_msgs_AudioCommand_h
#define _ROS_idmind_tabletop_msgs_AudioCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioCommand : public ros::Msg
  {
    public:
      typedef uint8_t _command_type;
      _command_type command;
      typedef const char* _file_type;
      _file_type file;
      typedef bool _loop_type;
      _loop_type loop;
      typedef float _volume_type;
      _volume_type volume;
      typedef bool _fade_in_type;
      _fade_in_type fade_in;
      typedef float _fade_in_duration_type;
      _fade_in_duration_type fade_in_duration;
      typedef bool _fade_out_type;
      _fade_out_type fade_out;
      typedef float _fade_out_duration_type;
      _fade_out_duration_type fade_out_duration;
      typedef uint32_t _start_time_type;
      _start_time_type start_time;
      typedef uint32_t _end_time_type;
      _end_time_type end_time;
      typedef uint8_t _channel_type;
      _channel_type channel;
      enum { PLAY =  0 };
      enum { STOP =  1 };
      enum { STOP_ALL =  2 };
      enum { MUSIC_CHANNEL =  0 };
      enum { SPEECH_CHANNEL =  1 };

    AudioCommand():
      command(0),
      file(""),
      loop(0),
      volume(0),
      fade_in(0),
      fade_in_duration(0),
      fade_out(0),
      fade_out_duration(0),
      start_time(0),
      end_time(0),
      channel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      union {
        float real;
        uint32_t base;
      } u_volume;
      u_volume.real = this->volume;
      *(outbuffer + offset + 0) = (u_volume.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volume.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volume.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volume.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volume);
      union {
        bool real;
        uint8_t base;
      } u_fade_in;
      u_fade_in.real = this->fade_in;
      *(outbuffer + offset + 0) = (u_fade_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fade_in);
      union {
        float real;
        uint32_t base;
      } u_fade_in_duration;
      u_fade_in_duration.real = this->fade_in_duration;
      *(outbuffer + offset + 0) = (u_fade_in_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fade_in_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fade_in_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fade_in_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fade_in_duration);
      union {
        bool real;
        uint8_t base;
      } u_fade_out;
      u_fade_out.real = this->fade_out;
      *(outbuffer + offset + 0) = (u_fade_out.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fade_out);
      union {
        float real;
        uint32_t base;
      } u_fade_out_duration;
      u_fade_out_duration.real = this->fade_out_duration;
      *(outbuffer + offset + 0) = (u_fade_out_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fade_out_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fade_out_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fade_out_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fade_out_duration);
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
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      union {
        float real;
        uint32_t base;
      } u_volume;
      u_volume.base = 0;
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volume = u_volume.real;
      offset += sizeof(this->volume);
      union {
        bool real;
        uint8_t base;
      } u_fade_in;
      u_fade_in.base = 0;
      u_fade_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fade_in = u_fade_in.real;
      offset += sizeof(this->fade_in);
      union {
        float real;
        uint32_t base;
      } u_fade_in_duration;
      u_fade_in_duration.base = 0;
      u_fade_in_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fade_in_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fade_in_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fade_in_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fade_in_duration = u_fade_in_duration.real;
      offset += sizeof(this->fade_in_duration);
      union {
        bool real;
        uint8_t base;
      } u_fade_out;
      u_fade_out.base = 0;
      u_fade_out.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fade_out = u_fade_out.real;
      offset += sizeof(this->fade_out);
      union {
        float real;
        uint32_t base;
      } u_fade_out_duration;
      u_fade_out_duration.base = 0;
      u_fade_out_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fade_out_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fade_out_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fade_out_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fade_out_duration = u_fade_out_duration.real;
      offset += sizeof(this->fade_out_duration);
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
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioCommand"; };
    virtual const char * getMD5() override { return "7f6223bd35c69148940d7b7a70bdf221"; };

  };

}
#endif
