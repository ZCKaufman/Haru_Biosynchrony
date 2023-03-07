#ifndef _ROS_SERVICE_GetPersonHeadDirByName_h
#define _ROS_SERVICE_GetPersonHeadDirByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONHEADDIRBYNAME[] = "strawberry_ros_msgs/GetPersonHeadDirByName";

  class GetPersonHeadDirByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetPersonHeadDirByNameRequest():
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

    virtual const char * getType() override { return GETPERSONHEADDIRBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class GetPersonHeadDirByNameResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _head_dir_type;
      _head_dir_type head_dir;

    GetPersonHeadDirByNameResponse():
      head_dir()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->head_dir.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->head_dir.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSONHEADDIRBYNAME; };
    virtual const char * getMD5() override { return "ddaa610482987d137ed3d705fa4bcbde"; };

  };

  class GetPersonHeadDirByName {
    public:
    typedef GetPersonHeadDirByNameRequest Request;
    typedef GetPersonHeadDirByNameResponse Response;
  };

}
#endif
