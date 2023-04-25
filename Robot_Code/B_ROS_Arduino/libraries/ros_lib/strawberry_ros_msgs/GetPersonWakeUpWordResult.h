#ifndef _ROS_strawberry_ros_msgs_GetPersonWakeUpWordResult_h
#define _ROS_strawberry_ros_msgs_GetPersonWakeUpWordResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class GetPersonWakeUpWordResult : public ros::Msg
  {
    public:
      typedef bool _person_found_type;
      _person_found_type person_found;
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _person_name_type;
      _person_name_type person_name;
      typedef bool _wake_up_word_type;
      _wake_up_word_type wake_up_word;
      typedef uint32_t _speech_seq_type;
      _speech_seq_type speech_seq;
      typedef const char* _speech_text_type;
      _speech_text_type speech_text;
      typedef float _speech_confidence_type;
      _speech_confidence_type speech_confidence;
      typedef float _speaker_confidence_type;
      _speaker_confidence_type speaker_confidence;

    GetPersonWakeUpWordResult():
      person_found(0),
      person_id(0),
      person_name(""),
      wake_up_word(0),
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
      } u_person_found;
      u_person_found.real = this->person_found;
      *(outbuffer + offset + 0) = (u_person_found.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->person_found);
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      uint32_t length_person_name = strlen(this->person_name);
      varToArr(outbuffer + offset, length_person_name);
      offset += 4;
      memcpy(outbuffer + offset, this->person_name, length_person_name);
      offset += length_person_name;
      union {
        bool real;
        uint8_t base;
      } u_wake_up_word;
      u_wake_up_word.real = this->wake_up_word;
      *(outbuffer + offset + 0) = (u_wake_up_word.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wake_up_word);
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
      } u_person_found;
      u_person_found.base = 0;
      u_person_found.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->person_found = u_person_found.real;
      offset += sizeof(this->person_found);
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
      uint32_t length_person_name;
      arrToVar(length_person_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_person_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_person_name-1]=0;
      this->person_name = (char *)(inbuffer + offset-1);
      offset += length_person_name;
      union {
        bool real;
        uint8_t base;
      } u_wake_up_word;
      u_wake_up_word.base = 0;
      u_wake_up_word.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wake_up_word = u_wake_up_word.real;
      offset += sizeof(this->wake_up_word);
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonWakeUpWordResult"; };
    virtual const char * getMD5() override { return "f7c8f06978fbdbbc94523f165655d9ca"; };

  };

}
#endif
