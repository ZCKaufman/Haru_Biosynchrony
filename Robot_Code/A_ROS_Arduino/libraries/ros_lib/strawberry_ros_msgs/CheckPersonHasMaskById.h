#ifndef _ROS_SERVICE_CheckPersonHasMaskById_h
#define _ROS_SERVICE_CheckPersonHasMaskById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char CHECKPERSONHASMASKBYID[] = "strawberry_ros_msgs/CheckPersonHasMaskById";

  class CheckPersonHasMaskByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    CheckPersonHasMaskByIdRequest():
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

    virtual const char * getType() override { return CHECKPERSONHASMASKBYID; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class CheckPersonHasMaskByIdResponse : public ros::Msg
  {
    public:
      typedef bool _has_mask_type;
      _has_mask_type has_mask;

    CheckPersonHasMaskByIdResponse():
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

    virtual const char * getType() override { return CHECKPERSONHASMASKBYID; };
    virtual const char * getMD5() override { return "5ee48ba3e3a5c566a3c2465e77b4b83e"; };

  };

  class CheckPersonHasMaskById {
    public:
    typedef CheckPersonHasMaskByIdRequest Request;
    typedef CheckPersonHasMaskByIdResponse Response;
  };

}
#endif
