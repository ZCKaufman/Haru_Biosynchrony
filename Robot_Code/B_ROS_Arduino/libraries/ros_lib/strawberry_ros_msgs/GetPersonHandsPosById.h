#ifndef _ROS_SERVICE_GetPersonHandsPosById_h
#define _ROS_SERVICE_GetPersonHandsPosById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONHANDSPOSBYID[] = "strawberry_ros_msgs/GetPersonHandsPosById";

  class GetPersonHandsPosByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    GetPersonHandsPosByIdRequest():
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

    virtual const char * getType() override { return GETPERSONHANDSPOSBYID; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class GetPersonHandsPosByIdResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _r_hand_pos_type;
      _r_hand_pos_type r_hand_pos;
      typedef geometry_msgs::Point _l_hand_pos_type;
      _l_hand_pos_type l_hand_pos;

    GetPersonHandsPosByIdResponse():
      r_hand_pos(),
      l_hand_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->r_hand_pos.serialize(outbuffer + offset);
      offset += this->l_hand_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->r_hand_pos.deserialize(inbuffer + offset);
      offset += this->l_hand_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSONHANDSPOSBYID; };
    virtual const char * getMD5() override { return "5ce3a212f4c2aca814acfd4c025346b3"; };

  };

  class GetPersonHandsPosById {
    public:
    typedef GetPersonHandsPosByIdRequest Request;
    typedef GetPersonHandsPosByIdResponse Response;
  };

}
#endif
