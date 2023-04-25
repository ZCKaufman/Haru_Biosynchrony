#ifndef _ROS_SERVICE_GetPersonHeadPosById_h
#define _ROS_SERVICE_GetPersonHeadPosById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONHEADPOSBYID[] = "strawberry_ros_msgs/GetPersonHeadPosById";

  class GetPersonHeadPosByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    GetPersonHeadPosByIdRequest():
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

    virtual const char * getType() override { return GETPERSONHEADPOSBYID; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class GetPersonHeadPosByIdResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _head_pos_type;
      _head_pos_type head_pos;

    GetPersonHeadPosByIdResponse():
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

    virtual const char * getType() override { return GETPERSONHEADPOSBYID; };
    virtual const char * getMD5() override { return "761b3c3c580bc583a802eb5a62b3b881"; };

  };

  class GetPersonHeadPosById {
    public:
    typedef GetPersonHeadPosByIdRequest Request;
    typedef GetPersonHeadPosByIdResponse Response;
  };

}
#endif
