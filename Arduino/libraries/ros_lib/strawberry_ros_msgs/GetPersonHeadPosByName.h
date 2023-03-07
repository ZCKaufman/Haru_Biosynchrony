#ifndef _ROS_SERVICE_GetPersonHeadPosByName_h
#define _ROS_SERVICE_GetPersonHeadPosByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONHEADPOSBYNAME[] = "strawberry_ros_msgs/GetPersonHeadPosByName";

  class GetPersonHeadPosByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetPersonHeadPosByNameRequest():
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

    virtual const char * getType() override { return GETPERSONHEADPOSBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class GetPersonHeadPosByNameResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _head_pos_type;
      _head_pos_type head_pos;

    GetPersonHeadPosByNameResponse():
      head_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->head_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->head_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSONHEADPOSBYNAME; };
    virtual const char * getMD5() override { return "761b3c3c580bc583a802eb5a62b3b881"; };

  };

  class GetPersonHeadPosByName {
    public:
    typedef GetPersonHeadPosByNameRequest Request;
    typedef GetPersonHeadPosByNameResponse Response;
  };

}
#endif
