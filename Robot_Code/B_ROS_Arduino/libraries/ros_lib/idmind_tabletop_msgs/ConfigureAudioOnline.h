#ifndef _ROS_SERVICE_ConfigureAudioOnline_h
#define _ROS_SERVICE_ConfigureAudioOnline_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char CONFIGUREAUDIOONLINE[] = "idmind_tabletop_msgs/ConfigureAudioOnline";

  class ConfigureAudioOnlineRequest : public ros::Msg
  {
    public:
      typedef uint8_t _channel_id_type;
      _channel_id_type channel_id;
      typedef float _volume_type;
      _volume_type volume;
      typedef float _fade_duration_type;
      _fade_duration_type fade_duration;
      typedef bool _do_fade_type;
      _do_fade_type do_fade;

    ConfigureAudioOnlineRequest():
      channel_id(0),
      volume(0),
      fade_duration(0),
      do_fade(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->channel_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel_id);
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
      } u_do_fade;
      u_do_fade.real = this->do_fade;
      *(outbuffer + offset + 0) = (u_do_fade.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->do_fade);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->channel_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel_id);
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
      } u_do_fade;
      u_do_fade.base = 0;
      u_do_fade.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->do_fade = u_do_fade.real;
      offset += sizeof(this->do_fade);
     return offset;
    }

    virtual const char * getType() override { return CONFIGUREAUDIOONLINE; };
    virtual const char * getMD5() override { return "5af43b2daa07dc822548c1acc4ff8037"; };

  };

  class ConfigureAudioOnlineResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _info_msg_type;
      _info_msg_type info_msg;

    ConfigureAudioOnlineResponse():
      success(0),
      info_msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_info_msg = strlen(this->info_msg);
      varToArr(outbuffer + offset, length_info_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->info_msg, length_info_msg);
      offset += length_info_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_info_msg;
      arrToVar(length_info_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_msg-1]=0;
      this->info_msg = (char *)(inbuffer + offset-1);
      offset += length_info_msg;
     return offset;
    }

    virtual const char * getType() override { return CONFIGUREAUDIOONLINE; };
    virtual const char * getMD5() override { return "47421756dccb893bfea457957b1798e6"; };

  };

  class ConfigureAudioOnline {
    public:
    typedef ConfigureAudioOnlineRequest Request;
    typedef ConfigureAudioOnlineResponse Response;
  };

}
#endif
