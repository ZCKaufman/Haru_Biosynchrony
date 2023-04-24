#ifndef _ROS_SERVICE_ASRControlSpeakerDiarization_h
#define _ROS_SERVICE_ASRControlSpeakerDiarization_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char ASRCONTROLSPEAKERDIARIZATION[] = "strawberry_ros_msgs/ASRControlSpeakerDiarization";

  class ASRControlSpeakerDiarizationRequest : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;
      typedef int8_t _min_speaker_count_type;
      _min_speaker_count_type min_speaker_count;
      typedef int8_t _max_speaker_count_type;
      _max_speaker_count_type max_speaker_count;

    ASRControlSpeakerDiarizationRequest():
      enable(0),
      min_speaker_count(0),
      max_speaker_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      union {
        int8_t real;
        uint8_t base;
      } u_min_speaker_count;
      u_min_speaker_count.real = this->min_speaker_count;
      *(outbuffer + offset + 0) = (u_min_speaker_count.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->min_speaker_count);
      union {
        int8_t real;
        uint8_t base;
      } u_max_speaker_count;
      u_max_speaker_count.real = this->max_speaker_count;
      *(outbuffer + offset + 0) = (u_max_speaker_count.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max_speaker_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
      union {
        int8_t real;
        uint8_t base;
      } u_min_speaker_count;
      u_min_speaker_count.base = 0;
      u_min_speaker_count.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->min_speaker_count = u_min_speaker_count.real;
      offset += sizeof(this->min_speaker_count);
      union {
        int8_t real;
        uint8_t base;
      } u_max_speaker_count;
      u_max_speaker_count.base = 0;
      u_max_speaker_count.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->max_speaker_count = u_max_speaker_count.real;
      offset += sizeof(this->max_speaker_count);
     return offset;
    }

    virtual const char * getType() override { return ASRCONTROLSPEAKERDIARIZATION; };
    virtual const char * getMD5() override { return "7a45b8858712d7f9013acc82ac0e3d31"; };

  };

  class ASRControlSpeakerDiarizationResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    ASRControlSpeakerDiarizationResponse():
      success(0),
      message("")
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
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
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
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return ASRCONTROLSPEAKERDIARIZATION; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class ASRControlSpeakerDiarization {
    public:
    typedef ASRControlSpeakerDiarizationRequest Request;
    typedef ASRControlSpeakerDiarizationResponse Response;
  };

}
#endif
