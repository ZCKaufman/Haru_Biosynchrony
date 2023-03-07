#ifndef _ROS_strawberry_ros_msgs_Speech_h
#define _ROS_strawberry_ros_msgs_Speech_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/ASRResult.h"

namespace strawberry_ros_msgs
{

  class Speech : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef float _speaker_confidence_type;
      _speaker_confidence_type speaker_confidence;
      typedef strawberry_ros_msgs::ASRResult _asr_result_type;
      _asr_result_type asr_result;
      typedef bool _wake_up_word_type;
      _wake_up_word_type wake_up_word;

    Speech():
      person_id(0),
      speaker_confidence(0),
      asr_result(),
      wake_up_word(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
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
      offset += this->asr_result.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_wake_up_word;
      u_wake_up_word.real = this->wake_up_word;
      *(outbuffer + offset + 0) = (u_wake_up_word.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wake_up_word);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
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
      offset += this->asr_result.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_wake_up_word;
      u_wake_up_word.base = 0;
      u_wake_up_word.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wake_up_word = u_wake_up_word.real;
      offset += sizeof(this->wake_up_word);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Speech"; };
    virtual const char * getMD5() override { return "2ee791aa7a5d0142efa00383b5b9843e"; };

  };

}
#endif
