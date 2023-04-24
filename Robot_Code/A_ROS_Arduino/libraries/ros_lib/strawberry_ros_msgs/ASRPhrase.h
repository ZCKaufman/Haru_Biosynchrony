#ifndef _ROS_strawberry_ros_msgs_ASRPhrase_h
#define _ROS_strawberry_ros_msgs_ASRPhrase_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class ASRPhrase : public ros::Msg
  {
    public:
      typedef const char* _value_type;
      _value_type value;
      typedef float _boost_type;
      _boost_type boost;

    ASRPhrase():
      value(""),
      boost(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      union {
        float real;
        uint32_t base;
      } u_boost;
      u_boost.real = this->boost;
      *(outbuffer + offset + 0) = (u_boost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_boost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_boost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_boost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boost);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
      union {
        float real;
        uint32_t base;
      } u_boost;
      u_boost.base = 0;
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->boost = u_boost.real;
      offset += sizeof(this->boost);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/ASRPhrase"; };
    virtual const char * getMD5() override { return "39483eb65dd1564ab85ce88ec1df58d4"; };

  };

}
#endif
