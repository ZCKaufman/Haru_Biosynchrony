#ifndef _ROS_strawberry_ros_msgs_GetPersonWakeUpWordFeedback_h
#define _ROS_strawberry_ros_msgs_GetPersonWakeUpWordFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class GetPersonWakeUpWordFeedback : public ros::Msg
  {
    public:
      typedef bool _person_found_type;
      _person_found_type person_found;
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _person_name_type;
      _person_name_type person_name;
      typedef float _speaker_confidence_type;
      _speaker_confidence_type speaker_confidence;

    GetPersonWakeUpWordFeedback():
      person_found(0),
      person_id(0),
      person_name(""),
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonWakeUpWordFeedback"; };
    virtual const char * getMD5() override { return "ccbb78c063a8bc324d17cd9d83f23ac2"; };

  };

}
#endif
