#ifndef _ROS_SERVICE_GetPersonEmotionById_h
#define _ROS_SERVICE_GetPersonEmotionById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONEMOTIONBYID[] = "strawberry_ros_msgs/GetPersonEmotionById";

  class GetPersonEmotionByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    GetPersonEmotionByIdRequest():
      person_id(0)
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
     return offset;
    }

    virtual const char * getType() override { return GETPERSONEMOTIONBYID; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class GetPersonEmotionByIdResponse : public ros::Msg
  {
    public:
      typedef const char* _emotion_type;
      _emotion_type emotion;

    GetPersonEmotionByIdResponse():
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

    virtual const char * getType() override { return GETPERSONEMOTIONBYID; };
    virtual const char * getMD5() override { return "320a4a5f8df4421af3ae0d4c52f87ab8"; };

  };

  class GetPersonEmotionById {
    public:
    typedef GetPersonEmotionByIdRequest Request;
    typedef GetPersonEmotionByIdResponse Response;
  };

}
#endif
