#ifndef _ROS_SERVICE_GetPersonGestureById_h
#define _ROS_SERVICE_GetPersonGestureById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONGESTUREBYID[] = "strawberry_ros_msgs/GetPersonGestureById";

  class GetPersonGestureByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    GetPersonGestureByIdRequest():
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

    virtual const char * getType() override { return GETPERSONGESTUREBYID; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class GetPersonGestureByIdResponse : public ros::Msg
  {
    public:
      typedef const char* _gesture_type;
      _gesture_type gesture;

    GetPersonGestureByIdResponse():
      gesture("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_gesture = strlen(this->gesture);
      varToArr(outbuffer + offset, length_gesture);
      offset += 4;
      memcpy(outbuffer + offset, this->gesture, length_gesture);
      offset += length_gesture;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_gesture;
      arrToVar(length_gesture, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gesture; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gesture-1]=0;
      this->gesture = (char *)(inbuffer + offset-1);
      offset += length_gesture;
     return offset;
    }

    virtual const char * getType() override { return GETPERSONGESTUREBYID; };
    virtual const char * getMD5() override { return "61f2a41b9e73483e6fa26641a58eaf74"; };

  };

  class GetPersonGestureById {
    public:
    typedef GetPersonGestureByIdRequest Request;
    typedef GetPersonGestureByIdResponse Response;
  };

}
#endif
