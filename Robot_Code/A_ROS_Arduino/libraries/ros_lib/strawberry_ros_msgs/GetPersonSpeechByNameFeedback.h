#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechByNameFeedback_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechByNameFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechByNameFeedback : public ros::Msg
  {
    public:
      typedef bool _person_found_type;
      _person_found_type person_found;
      typedef float _speaker_confidence_type;
      _speaker_confidence_type speaker_confidence;

    GetPersonSpeechByNameFeedback():
      person_found(0),
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechByNameFeedback"; };
    virtual const char * getMD5() override { return "da872a9862f041622368a42d499d5e85"; };

  };

}
#endif
