#ifndef _ROS_SERVICE_CheckPersonIsFemaleByName_h
#define _ROS_SERVICE_CheckPersonIsFemaleByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char CHECKPERSONISFEMALEBYNAME[] = "strawberry_ros_msgs/CheckPersonIsFemaleByName";

  class CheckPersonIsFemaleByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    CheckPersonIsFemaleByNameRequest():
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

    virtual const char * getType() override { return CHECKPERSONISFEMALEBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class CheckPersonIsFemaleByNameResponse : public ros::Msg
  {
    public:
      typedef bool _is_female_type;
      _is_female_type is_female;

    CheckPersonIsFemaleByNameResponse():
      is_female(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_female;
      u_is_female.real = this->is_female;
      *(outbuffer + offset + 0) = (u_is_female.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_female);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_female;
      u_is_female.base = 0;
      u_is_female.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_female = u_is_female.real;
      offset += sizeof(this->is_female);
     return offset;
    }

    virtual const char * getType() override { return CHECKPERSONISFEMALEBYNAME; };
    virtual const char * getMD5() override { return "fc4ce2d4122ae9d24924b7887828361b"; };

  };

  class CheckPersonIsFemaleByName {
    public:
    typedef CheckPersonIsFemaleByNameRequest Request;
    typedef CheckPersonIsFemaleByNameResponse Response;
  };

}
#endif
