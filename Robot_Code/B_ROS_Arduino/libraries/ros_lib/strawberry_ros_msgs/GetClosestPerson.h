#ifndef _ROS_SERVICE_GetClosestPerson_h
#define _ROS_SERVICE_GetClosestPerson_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETCLOSESTPERSON[] = "strawberry_ros_msgs/GetClosestPerson";

  class GetClosestPersonRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _source_pos_type;
      _source_pos_type source_pos;

    GetClosestPersonRequest():
      source_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->source_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->source_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETCLOSESTPERSON; };
    virtual const char * getMD5() override { return "e04b3b18e74a87ed7f32e4d53ab36dc5"; };

  };

  class GetClosestPersonResponse : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetClosestPersonResponse():
      person_id(0),
      person_name("")
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
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
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

    virtual const char * getType() override { return GETCLOSESTPERSON; };
    virtual const char * getMD5() override { return "37a20c357bb32e9bda9e77ad5f202a26"; };

  };

  class GetClosestPerson {
    public:
    typedef GetClosestPersonRequest Request;
    typedef GetClosestPersonResponse Response;
  };

}
#endif
