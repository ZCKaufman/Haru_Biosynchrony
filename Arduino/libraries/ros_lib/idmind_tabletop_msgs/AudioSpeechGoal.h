#ifndef _ROS_idmind_tabletop_msgs_AudioSpeechGoal_h
#define _ROS_idmind_tabletop_msgs_AudioSpeechGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioSpeechGoal : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef bool _loop_type;
      _loop_type loop;
      typedef float _volume_type;
      _volume_type volume;
      typedef uint32_t _start_time_type;
      _start_time_type start_time;
      typedef uint32_t _end_time_type;
      _end_time_type end_time;
      typedef bool _fade_type;
      _fade_type fade;
      typedef float _fade_duration_type;
      _fade_duration_type fade_duration;
      typedef bool _fade_out_type;
      _fade_out_type fade_out;
      typedef float _fade_out_duration_type;
      _fade_out_duration_type fade_out_duration;

    AudioSpeechGoal():
      file(""),
      loop(0),
      volume(0),
      start_time(0),
      end_time(0),
      fade(0),
      fade_duration(0),
      fade_out(0),
      fade_out_duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      } u_fade;
      u_fade.real = this->fade;
      *(outbuffer + offset + 0) = (u_fade.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fade);
      union {
        float real;
        uint32_t base;
      } u_fade_duration;
      u_fade_duration.real = this->fade_duration;
      *(outbuffer + offset + 0) = (u_fade_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fade_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fade_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fade_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fade_duration);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      } u_fade;
      u_fade.base = 0;
      u_fade.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fade = u_fade.real;
      offset += sizeof(this->fade);
      union {
        float real;
        uint32_t base;
      } u_fade_duration;
      u_fade_duration.base = 0;
      u_fade_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fade_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fade_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fade_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fade_duration = u_fade_duration.real;
      offset += sizeof(this->fade_duration);
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
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioSpeechGoal"; };
    virtual const char * getMD5() override { return "5c6b8926dfd455cde8e85ead1c83d2f0"; };

  };

}
#endif
