#ifndef _ROS_SERVICE_GetPersonBodyPartPosByName_h
#define _ROS_SERVICE_GetPersonBodyPartPosByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONBODYPARTPOSBYNAME[] = "strawberry_ros_msgs/GetPersonBodyPartPosByName";

  class GetPersonBodyPartPosByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;
      typedef const char* _body_part_type;
      _body_part_type body_part;

    GetPersonBodyPartPosByNameRequest():
      person_name(""),
      body_part("")
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
      uint32_t length_body_part = strlen(this->body_part);
      varToArr(outbuffer + offset, length_body_part);
      offset += 4;
      memcpy(outbuffer + offset, this->body_part, length_body_part);
      offset += length_body_part;
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
      uint32_t length_body_part;
      arrToVar(length_body_part, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_body_part; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_body_part-1]=0;
      this->body_part = (char *)(inbuffer + offset-1);
      offset += length_body_part;
     return offset;
    }

    virtual const char * getType() override { return GETPERSONBODYPARTPOSBYNAME; };
    virtual const char * getMD5() override { return "d9bb79698006847e0d649a30325c729d"; };

  };

  class GetPersonBodyPartPosByNameResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _body_part_pos_type;
      _body_part_pos_type body_part_pos;

    GetPersonBodyPartPosByNameResponse():
      body_part_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->body_part_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->body_part_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSONBODYPARTPOSBYNAME; };
    virtual const char * getMD5() override { return "72298cdb3ca4c3c914b09039cb6510e8"; };

  };

  class GetPersonBodyPartPosByName {
    public:
    typedef GetPersonBodyPartPosByNameRequest Request;
    typedef GetPersonBodyPartPosByNameResponse Response;
  };

}
#endif
