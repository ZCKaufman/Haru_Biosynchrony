#ifndef _ROS_SERVICE_GetPersonGestureByName_h
#define _ROS_SERVICE_GetPersonGestureByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONGESTUREBYNAME[] = "strawberry_ros_msgs/GetPersonGestureByName";

  class GetPersonGestureByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetPersonGestureByNameRequest():
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

    virtual const char * getType() override { return GETPERSONGESTUREBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class GetPersonGestureByNameResponse : public ros::Msg
  {
    public:
      typedef const char* _gesture_type;
      _gesture_type gesture;

    GetPersonGestureByNameResponse():
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

    virtual const char * getType() override { return GETPERSONGESTUREBYNAME; };
    virtual const char * getMD5() override { return "61f2a41b9e73483e6fa26641a58eaf74"; };

  };

  class GetPersonGestureByName {
    public:
    typedef GetPersonGestureByNameRequest Request;
    typedef GetPersonGestureByNameResponse Response;
  };

}
#endif
