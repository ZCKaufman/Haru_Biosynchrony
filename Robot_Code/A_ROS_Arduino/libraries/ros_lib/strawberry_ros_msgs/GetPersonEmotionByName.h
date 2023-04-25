#ifndef _ROS_SERVICE_GetPersonEmotionByName_h
#define _ROS_SERVICE_GetPersonEmotionByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONEMOTIONBYNAME[] = "strawberry_ros_msgs/GetPersonEmotionByName";

  class GetPersonEmotionByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetPersonEmotionByNameRequest():
      person_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_person_name = strlen(this->person_name);
      varToArr(outbuffer + offset, length_person_name);
      offset += 4;
      memcpy(outbuffer + offset, this->person_name, length_person_name);
      offset += length_person_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_person_name;
      arrToVar(length_person_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_person_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_person_name-1]=0;
      this->person_name = (char *)(inbuffer + offset-1);
      offset += length_person_name;
     return offset;
    }

    virtual const char * getType() override { return GETPERSONEMOTIONBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class GetPersonEmotionByNameResponse : public ros::Msg
  {
    public:
      typedef const char* _emotion_type;
      _emotion_type emotion;

    GetPersonEmotionByNameResponse():
      emotion("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_emotion = strlen(this->emotion);
      varToArr(outbuffer + offset, length_emotion);
      offset += 4;
      memcpy(outbuffer + offset, this->emotion, length_emotion);
      offset += length_emotion;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_emotion;
      arrToVar(length_emotion, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_emotion; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_emotion-1]=0;
      this->emotion = (char *)(inbuffer + offset-1);
      offset += length_emotion;
     return offset;
    }

    virtual const char * getType() override { return GETPERSONEMOTIONBYNAME; };
    virtual const char * getMD5() override { return "320a4a5f8df4421af3ae0d4c52f87ab8"; };

  };

  class GetPersonEmotionByName {
    public:
    typedef GetPersonEmotionByNameRequest Request;
    typedef GetPersonEmotionByNameResponse Response;
  };

}
#endif
