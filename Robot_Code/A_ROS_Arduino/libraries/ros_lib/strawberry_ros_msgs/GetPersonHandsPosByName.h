#ifndef _ROS_SERVICE_GetPersonHandsPosByName_h
#define _ROS_SERVICE_GetPersonHandsPosByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONHANDSPOSBYNAME[] = "strawberry_ros_msgs/GetPersonHandsPosByName";

  class GetPersonHandsPosByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetPersonHandsPosByNameRequest():
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

    virtual const char * getType() override { return GETPERSONHANDSPOSBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class GetPersonHandsPosByNameResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _r_hand_pos_type;
      _r_hand_pos_type r_hand_pos;
      typedef geometry_msgs::Point _l_hand_pos_type;
      _l_hand_pos_type l_hand_pos;

    GetPersonHandsPosByNameResponse():
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

    virtual const char * getType() override { return GETPERSONHANDSPOSBYNAME; };
    virtual const char * getMD5() override { return "5ce3a212f4c2aca814acfd4c025346b3"; };

  };

  class GetPersonHandsPosByName {
    public:
    typedef GetPersonHandsPosByNameRequest Request;
    typedef GetPersonHandsPosByNameResponse Response;
  };

}
#endif
