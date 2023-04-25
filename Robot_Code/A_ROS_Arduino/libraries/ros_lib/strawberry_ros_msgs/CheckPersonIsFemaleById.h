#ifndef _ROS_SERVICE_CheckPersonIsFemaleById_h
#define _ROS_SERVICE_CheckPersonIsFemaleById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char CHECKPERSONISFEMALEBYID[] = "strawberry_ros_msgs/CheckPersonIsFemaleById";

  class CheckPersonIsFemaleByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    CheckPersonIsFemaleByIdRequest():
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

    virtual const char * getType() override { return CHECKPERSONISFEMALEBYID; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class CheckPersonIsFemaleByIdResponse : public ros::Msg
  {
    public:
      typedef bool _is_female_type;
      _is_female_type is_female;

    CheckPersonIsFemaleByIdResponse():
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

    virtual const char * getType() override { return CHECKPERSONISFEMALEBYID; };
    virtual const char * getMD5() override { return "fc4ce2d4122ae9d24924b7887828361b"; };

  };

  class CheckPersonIsFemaleById {
    public:
    typedef CheckPersonIsFemaleByIdRequest Request;
    typedef CheckPersonIsFemaleByIdResponse Response;
  };

}
#endif
