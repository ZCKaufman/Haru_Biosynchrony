#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechByNameResult_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechByNameResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechByNameResult : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef uint32_t _speech_seq_type;
      _speech_seq_type speech_seq;
      typedef const char* _speech_text_type;
      _speech_text_type speech_text;
      typedef float _speech_confidence_type;
      _speech_confidence_type speech_confidence;
      typedef float _speaker_confidence_type;
      _speaker_confidence_type speaker_confidence;

    GetPersonSpeechByNameResult():
      success(0),
      speech_seq(0),
      speech_text(""),
      speech_confidence(0),
      speaker_confidence(0)
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
      *(outbuffer + offset + 0) = (this->speech_seq >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speech_seq >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->speech_seq >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->speech_seq >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speech_seq);
      uint32_t length_speech_text = strlen(this->speech_text);
      varToArr(outbuffer + offset, length_speech_text);
      offset += 4;
      memcpy(outbuffer + offset, this->speech_text, length_speech_text);
      offset += length_speech_text;
      union {
        float real;
        uint32_t base;
      } u_speech_confidence;
      u_speech_confidence.real = this->speech_confidence;
      *(outbuffer + offset + 0) = (u_speech_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speech_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speech_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speech_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speech_confidence);
      union {
        float real;
        uint32_t base;
      } u_speaker_confidence;
      u_speaker_confidence.real = this->speaker_confidence;
      *(outbuffer + offset + 0) = (u_speaker_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speaker_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speaker_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speaker_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speaker_confidence);
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
      this->speech_seq =  ((uint32_t) (*(inbuffer + offset)));
      this->speech_seq |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->speech_seq |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->speech_seq |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->speech_seq);
      uint32_t length_speech_text;
      arrToVar(length_speech_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_speech_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_speech_text-1]=0;
      this->speech_text = (char *)(inbuffer + offset-1);
      offset += length_speech_text;
      union {
        float real;
        uint32_t base;
      } u_speech_confidence;
      u_speech_confidence.base = 0;
      u_speech_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speech_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speech_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speech_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speech_confidence = u_speech_confidence.real;
      offset += sizeof(this->speech_confidence);
      union {
        float real;
        uint32_t base;
      } u_speaker_confidence;
      u_speaker_confidence.base = 0;
      u_speaker_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speaker_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speaker_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speaker_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speaker_confidence = u_speaker_confidence.real;
      offset += sizeof(this->speaker_confidence);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechByNameResult"; };
    virtual const char * getMD5() override { return "75549d1ebe2a35b7273dad003ee0e96b"; };

  };

}
#endif
