#ifndef _ROS_SERVICE_GetPersonBodyPartPosById_h
#define _ROS_SERVICE_GetPersonBodyPartPosById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONBODYPARTPOSBYID[] = "strawberry_ros_msgs/GetPersonBodyPartPosById";

  class GetPersonBodyPartPosByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _body_part_type;
      _body_part_type body_part;

    GetPersonBodyPartPosByIdRequest():
      person_id(0),
      body_part("")
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
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
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

    virtual const char * getType() override { return GETPERSONBODYPARTPOSBYID; };
    virtual const char * getMD5() override { return "76e4042e628266b6a9624495f5f68203"; };

  };

  class GetPersonBodyPartPosByIdResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _body_part_pos_type;
      _body_part_pos_type body_part_pos;

    GetPersonBodyPartPosByIdResponse():
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

    virtual const char * getType() override { return GETPERSONBODYPARTPOSBYID; };
    virtual const char * getMD5() override { return "72298cdb3ca4c3c914b09039cb6510e8"; };

  };

  class GetPersonBodyPartPosById {
    public:
    typedef GetPersonBodyPartPosByIdRequest Request;
    typedef GetPersonBodyPartPosByIdResponse Response;
  };

}
#endif
