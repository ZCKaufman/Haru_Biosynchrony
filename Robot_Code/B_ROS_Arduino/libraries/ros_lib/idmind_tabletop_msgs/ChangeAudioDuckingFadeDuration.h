#ifndef _ROS_SERVICE_ChangeAudioDuckingFadeDuration_h
#define _ROS_SERVICE_ChangeAudioDuckingFadeDuration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char CHANGEAUDIODUCKINGFADEDURATION[] = "idmind_tabletop_msgs/ChangeAudioDuckingFadeDuration";

  class ChangeAudioDuckingFadeDurationRequest : public ros::Msg
  {
    public:
      typedef float _fade_duration_type;
      _fade_duration_type fade_duration;

    ChangeAudioDuckingFadeDurationRequest():
      fade_duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
     return offset;
    }

    virtual const char * getType() override { return CHANGEAUDIODUCKINGFADEDURATION; };
    virtual const char * getMD5() override { return "49ab1e29f8479ef9c1774973e7220f02"; };

  };

  class ChangeAudioDuckingFadeDurationResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;

    ChangeAudioDuckingFadeDurationResponse():
      message(""),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return CHANGEAUDIODUCKINGFADEDURATION; };
    virtual const char * getMD5() override { return "9bf829f07d795d3f9e541a07897da2c4"; };

  };

  class ChangeAudioDuckingFadeDuration {
    public:
    typedef ChangeAudioDuckingFadeDurationRequest Request;
    typedef ChangeAudioDuckingFadeDurationResponse Response;
  };

}
#endif
