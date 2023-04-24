#ifndef _ROS_idmind_tabletop_msgs_TTSConfig_h
#define _ROS_idmind_tabletop_msgs_TTSConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TTSConfig : public ros::Msg
  {
    public:
      typedef bool _add_emphasis_type;
      _add_emphasis_type add_emphasis;
      typedef int8_t _emphasis_type_type;
      _emphasis_type_type emphasis_type;
      typedef bool _add_break_type;
      _add_break_type add_break;
      typedef int8_t _break_type_type;
      _break_type_type break_type;
      typedef uint32_t _break_time_type;
      _break_time_type break_time;
      typedef bool _add_pitch_type;
      _add_pitch_type add_pitch;
      typedef bool _relative_pitch_type;
      _relative_pitch_type relative_pitch;
      typedef int8_t _pitch_type_type;
      _pitch_type_type pitch_type;
      typedef float _pitch_value_type;
      _pitch_value_type pitch_value;
      typedef bool _add_rate_type;
      _add_rate_type add_rate;
      typedef int8_t _rate_type_type;
      _rate_type_type rate_type;
      typedef uint32_t _rate_value_type;
      _rate_value_type rate_value;
      typedef bool _add_duration_type;
      _add_duration_type add_duration;
      typedef int32_t _duration_value_type;
      _duration_value_type duration_value;
      typedef bool _add_volume_type;
      _add_volume_type add_volume;
      typedef int8_t _volume_type_type;
      _volume_type_type volume_type;
      typedef int32_t _volume_value_type;
      _volume_value_type volume_value;
      typedef const char* _file_uri_type;
      _file_uri_type file_uri;
      typedef bool _add_emotion_type;
      _add_emotion_type add_emotion;
      typedef uint8_t _emotion_type;
      _emotion_type emotion;
      enum { EMPHASIS_REDUCED =  -1 };
      enum { EMPHASIS_NONE =  0 };
      enum { EMPHASIS_MODERATED =  1 };
      enum { EMPHASIS_STRONG =  2 };
      enum { BREAK_VERY_WEAK =  -3 };
      enum { BREAK_WEAK =  -2 };
      enum { BREAK_NONE =  -1 };
      enum { BREAK_MEDIUM =  0 };
      enum { BREAK_STRONG =  1 };
      enum { BREAK_VERY_STRONG =  2 };
      enum { PITCH_VERY_SLOW =  -2 };
      enum { PITCH_SLOW =  -1 };
      enum { PITCH_DEFAULT =  0 };
      enum { PITCH_MEDIUM =  1 };
      enum { PITCH_HIGH =  2 };
      enum { PITCH_VERY_HIGH =  3 };
      enum { RATE_VERY_SLOW =  -2 };
      enum { RATE_SLOW =  -1 };
      enum { RATE_DEFAULT =  0 };
      enum { RATE_MEDIUM =  1 };
      enum { RATE_HIGH =  2 };
      enum { RATE_VERY_HIGH =  3 };
      enum { VOLUME_SILENT =  -3 };
      enum { VOLUME_VERY_SOFT =  -2 };
      enum { VOLUME_SOFT =  -1 };
      enum { VOLUME_DEFAULT =  0 };
      enum { VOLUME_MEDIUM =  1 };
      enum { VOLUME_LOUD =  2 };
      enum { VOLUME_VERY_LOUD =  3 };
      enum { EMOTION_HAPPY =  0 };
      enum { EMOTION_SAD =  1 };
      enum { EMOTION_CALM =  2 };
      enum { EMOTION_ANGRY =  3 };

    TTSConfig():
      add_emphasis(0),
      emphasis_type(0),
      add_break(0),
      break_type(0),
      break_time(0),
      add_pitch(0),
      relative_pitch(0),
      pitch_type(0),
      pitch_value(0),
      add_rate(0),
      rate_type(0),
      rate_value(0),
      add_duration(0),
      duration_value(0),
      add_volume(0),
      volume_type(0),
      volume_value(0),
      file_uri(""),
      add_emotion(0),
      emotion(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_add_emphasis;
      u_add_emphasis.real = this->add_emphasis;
      *(outbuffer + offset + 0) = (u_add_emphasis.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_emphasis);
      union {
        int8_t real;
        uint8_t base;
      } u_emphasis_type;
      u_emphasis_type.real = this->emphasis_type;
      *(outbuffer + offset + 0) = (u_emphasis_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->emphasis_type);
      union {
        bool real;
        uint8_t base;
      } u_add_break;
      u_add_break.real = this->add_break;
      *(outbuffer + offset + 0) = (u_add_break.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_break);
      union {
        int8_t real;
        uint8_t base;
      } u_break_type;
      u_break_type.real = this->break_type;
      *(outbuffer + offset + 0) = (u_break_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->break_type);
      *(outbuffer + offset + 0) = (this->break_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->break_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->break_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->break_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->break_time);
      union {
        bool real;
        uint8_t base;
      } u_add_pitch;
      u_add_pitch.real = this->add_pitch;
      *(outbuffer + offset + 0) = (u_add_pitch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_pitch);
      union {
        bool real;
        uint8_t base;
      } u_relative_pitch;
      u_relative_pitch.real = this->relative_pitch;
      *(outbuffer + offset + 0) = (u_relative_pitch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->relative_pitch);
      union {
        int8_t real;
        uint8_t base;
      } u_pitch_type;
      u_pitch_type.real = this->pitch_type;
      *(outbuffer + offset + 0) = (u_pitch_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pitch_type);
      union {
        float real;
        uint32_t base;
      } u_pitch_value;
      u_pitch_value.real = this->pitch_value;
      *(outbuffer + offset + 0) = (u_pitch_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_value);
      union {
        bool real;
        uint8_t base;
      } u_add_rate;
      u_add_rate.real = this->add_rate;
      *(outbuffer + offset + 0) = (u_add_rate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_rate);
      union {
        int8_t real;
        uint8_t base;
      } u_rate_type;
      u_rate_type.real = this->rate_type;
      *(outbuffer + offset + 0) = (u_rate_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rate_type);
      *(outbuffer + offset + 0) = (this->rate_value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rate_value >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rate_value >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rate_value >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rate_value);
      union {
        bool real;
        uint8_t base;
      } u_add_duration;
      u_add_duration.real = this->add_duration;
      *(outbuffer + offset + 0) = (u_add_duration.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_duration);
      union {
        int32_t real;
        uint32_t base;
      } u_duration_value;
      u_duration_value.real = this->duration_value;
      *(outbuffer + offset + 0) = (u_duration_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duration_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duration_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration_value);
      union {
        bool real;
        uint8_t base;
      } u_add_volume;
      u_add_volume.real = this->add_volume;
      *(outbuffer + offset + 0) = (u_add_volume.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_volume);
      union {
        int8_t real;
        uint8_t base;
      } u_volume_type;
      u_volume_type.real = this->volume_type;
      *(outbuffer + offset + 0) = (u_volume_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->volume_type);
      union {
        int32_t real;
        uint32_t base;
      } u_volume_value;
      u_volume_value.real = this->volume_value;
      *(outbuffer + offset + 0) = (u_volume_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volume_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volume_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volume_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volume_value);
      uint32_t length_file_uri = strlen(this->file_uri);
      varToArr(outbuffer + offset, length_file_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->file_uri, length_file_uri);
      offset += length_file_uri;
      union {
        bool real;
        uint8_t base;
      } u_add_emotion;
      u_add_emotion.real = this->add_emotion;
      *(outbuffer + offset + 0) = (u_add_emotion.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add_emotion);
      *(outbuffer + offset + 0) = (this->emotion >> (8 * 0)) & 0xFF;
      offset += sizeof(this->emotion);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_add_emphasis;
      u_add_emphasis.base = 0;
      u_add_emphasis.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_emphasis = u_add_emphasis.real;
      offset += sizeof(this->add_emphasis);
      union {
        int8_t real;
        uint8_t base;
      } u_emphasis_type;
      u_emphasis_type.base = 0;
      u_emphasis_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->emphasis_type = u_emphasis_type.real;
      offset += sizeof(this->emphasis_type);
      union {
        bool real;
        uint8_t base;
      } u_add_break;
      u_add_break.base = 0;
      u_add_break.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_break = u_add_break.real;
      offset += sizeof(this->add_break);
      union {
        int8_t real;
        uint8_t base;
      } u_break_type;
      u_break_type.base = 0;
      u_break_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->break_type = u_break_type.real;
      offset += sizeof(this->break_type);
      this->break_time =  ((uint32_t) (*(inbuffer + offset)));
      this->break_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->break_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->break_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->break_time);
      union {
        bool real;
        uint8_t base;
      } u_add_pitch;
      u_add_pitch.base = 0;
      u_add_pitch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_pitch = u_add_pitch.real;
      offset += sizeof(this->add_pitch);
      union {
        bool real;
        uint8_t base;
      } u_relative_pitch;
      u_relative_pitch.base = 0;
      u_relative_pitch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->relative_pitch = u_relative_pitch.real;
      offset += sizeof(this->relative_pitch);
      union {
        int8_t real;
        uint8_t base;
      } u_pitch_type;
      u_pitch_type.base = 0;
      u_pitch_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pitch_type = u_pitch_type.real;
      offset += sizeof(this->pitch_type);
      union {
        float real;
        uint32_t base;
      } u_pitch_value;
      u_pitch_value.base = 0;
      u_pitch_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_value = u_pitch_value.real;
      offset += sizeof(this->pitch_value);
      union {
        bool real;
        uint8_t base;
      } u_add_rate;
      u_add_rate.base = 0;
      u_add_rate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_rate = u_add_rate.real;
      offset += sizeof(this->add_rate);
      union {
        int8_t real;
        uint8_t base;
      } u_rate_type;
      u_rate_type.base = 0;
      u_rate_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rate_type = u_rate_type.real;
      offset += sizeof(this->rate_type);
      this->rate_value =  ((uint32_t) (*(inbuffer + offset)));
      this->rate_value |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rate_value |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->rate_value |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->rate_value);
      union {
        bool real;
        uint8_t base;
      } u_add_duration;
      u_add_duration.base = 0;
      u_add_duration.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_duration = u_add_duration.real;
      offset += sizeof(this->add_duration);
      union {
        int32_t real;
        uint32_t base;
      } u_duration_value;
      u_duration_value.base = 0;
      u_duration_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duration_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duration_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duration_value = u_duration_value.real;
      offset += sizeof(this->duration_value);
      union {
        bool real;
        uint8_t base;
      } u_add_volume;
      u_add_volume.base = 0;
      u_add_volume.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_volume = u_add_volume.real;
      offset += sizeof(this->add_volume);
      union {
        int8_t real;
        uint8_t base;
      } u_volume_type;
      u_volume_type.base = 0;
      u_volume_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->volume_type = u_volume_type.real;
      offset += sizeof(this->volume_type);
      union {
        int32_t real;
        uint32_t base;
      } u_volume_value;
      u_volume_value.base = 0;
      u_volume_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volume_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volume_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volume_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volume_value = u_volume_value.real;
      offset += sizeof(this->volume_value);
      uint32_t length_file_uri;
      arrToVar(length_file_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_uri-1]=0;
      this->file_uri = (char *)(inbuffer + offset-1);
      offset += length_file_uri;
      union {
        bool real;
        uint8_t base;
      } u_add_emotion;
      u_add_emotion.base = 0;
      u_add_emotion.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add_emotion = u_add_emotion.real;
      offset += sizeof(this->add_emotion);
      this->emotion =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->emotion);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSConfig"; };
    virtual const char * getMD5() override { return "4a8daa9a080911169a567e8693b33e63"; };

  };

}
#endif
