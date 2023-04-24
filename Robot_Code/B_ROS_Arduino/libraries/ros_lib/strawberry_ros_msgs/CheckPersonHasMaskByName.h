#ifndef _ROS_SERVICE_CheckPersonHasMaskByName_h
#define _ROS_SERVICE_CheckPersonHasMaskByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char CHECKPERSONHASMASKBYNAME[] = "strawberry_ros_msgs/CheckPersonHasMaskByName";

  class CheckPersonHasMaskByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    CheckPersonHasMaskByNameRequest():
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

    virtual const char * getType() override { return CHECKPERSONHASMASKBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class CheckPersonHasMaskByNameResponse : public ros::Msg
  {
    public:
      typedef bool _has_mask_type;
      _has_mask_type has_mask;

    CheckPersonHasMaskByNameResponse():
      has_mask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_has_mask;
      u_has_mask.real = this->has_mask;
      *(outbuffer + offset + 0) = (u_has_mask.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_mask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_has_mask;
      u_has_mask.base = 0;
      u_has_mask.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_mask = u_has_mask.real;
      offset += sizeof(this->has_mask);
     return offset;
    }

    virtual const char * getType() override { return CHECKPERSONHASMASKBYNAME; };
    virtual const char * getMD5() override { return "5ee48ba3e3a5c566a3c2465e77b4b83e"; };

  };

  class CheckPersonHasMaskByName {
    public:
    typedef CheckPersonHasMaskByNameRequest Request;
    typedef CheckPersonHasMaskByNameResponse Response;
  };

}
#endif
