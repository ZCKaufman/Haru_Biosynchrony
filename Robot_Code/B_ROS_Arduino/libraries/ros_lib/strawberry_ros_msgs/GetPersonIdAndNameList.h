#ifndef _ROS_SERVICE_GetPersonIdAndNameList_h
#define _ROS_SERVICE_GetPersonIdAndNameList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/NamedId.h"

namespace strawberry_ros_msgs
{

static const char GETPERSONIDANDNAMELIST[] = "strawberry_ros_msgs/GetPersonIdAndNameList";

  class GetPersonIdAndNameListRequest : public ros::Msg
  {
    public:

    GetPersonIdAndNameListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETPERSONIDANDNAMELIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPersonIdAndNameListResponse : public ros::Msg
  {
    public:
      uint32_t named_ids_length;
      typedef strawberry_ros_msgs::NamedId _named_ids_type;
      _named_ids_type st_named_ids;
      _named_ids_type * named_ids;

    GetPersonIdAndNameListResponse():
      named_ids_length(0), st_named_ids(), named_ids(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->named_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->named_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->named_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->named_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->named_ids_length);
      for( uint32_t i = 0; i < named_ids_length; i++){
      offset += this->named_ids[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t named_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      named_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      named_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      named_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->named_ids_length);
      if(named_ids_lengthT > named_ids_length)
        this->named_ids = (strawberry_ros_msgs::NamedId*)realloc(this->named_ids, named_ids_lengthT * sizeof(strawberry_ros_msgs::NamedId));
      named_ids_length = named_ids_lengthT;
      for( uint32_t i = 0; i < named_ids_length; i++){
      offset += this->st_named_ids.deserialize(inbuffer + offset);
        memcpy( &(this->named_ids[i]), &(this->st_named_ids), sizeof(strawberry_ros_msgs::NamedId));
      }
     return offset;
    }

    virtual const char * getType() override { return GETPERSONIDANDNAMELIST; };
    virtual const char * getMD5() override { return "816259e822e85ec4dac455e63407238b"; };

  };

  class GetPersonIdAndNameList {
    public:
    typedef GetPersonIdAndNameListRequest Request;
    typedef GetPersonIdAndNameListResponse Response;
  };

}
#endif
