#ifndef _ROS_SERVICE_GetPersonHandsDirByName_h
#define _ROS_SERVICE_GetPersonHandsDirByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONHANDSDIRBYNAME[] = "strawberry_ros_msgs/GetPersonHandsDirByName";

  class GetPersonHandsDirByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;

    GetPersonHandsDirByNameRequest():
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

    virtual const char * getType() override { return GETPERSONHANDSDIRBYNAME; };
    virtual const char * getMD5() override { return "e2d6bff7c373fbffae616009ee6a2c27"; };

  };

  class GetPersonHandsDirByNameResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _r_hand_dir_type;
      _r_hand_dir_type r_hand_dir;
      typedef geometry_msgs::Point _l_hand_dir_type;
      _l_hand_dir_type l_hand_dir;

    GetPersonHandsDirByNameResponse():
      r_hand_dir(),
      l_hand_dir()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->r_hand_dir.serialize(outbuffer + offset);
      offset += this->l_hand_dir.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->r_hand_dir.deserialize(inbuffer + offset);
      offset += this->l_hand_dir.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSONHANDSDIRBYNAME; };
    virtual const char * getMD5() override { return "6f79be997041e6bab376a9db4f58a4f4"; };

  };

  class GetPersonHandsDirByName {
    public:
    typedef GetPersonHandsDirByNameRequest Request;
    typedef GetPersonHandsDirByNameResponse Response;
  };

}
#endif
