#ifndef _ROS_SERVICE_FaceLearning_h
#define _ROS_SERVICE_FaceLearning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char FACELEARNING[] = "strawberry_ros_msgs/FaceLearning";

  class FaceLearningRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _blocking_type;
      _blocking_type blocking;
      typedef uint32_t _iters_type;
      _iters_type iters;

    FaceLearningRequest():
      name(""),
      blocking(0),
      iters(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_blocking;
      u_blocking.real = this->blocking;
      *(outbuffer + offset + 0) = (u_blocking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blocking);
      *(outbuffer + offset + 0) = (this->iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iters);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_blocking;
      u_blocking.base = 0;
      u_blocking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blocking = u_blocking.real;
      offset += sizeof(this->blocking);
      this->iters =  ((uint32_t) (*(inbuffer + offset)));
      this->iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->iters);
     return offset;
    }

    virtual const char * getType() override { return FACELEARNING; };
    virtual const char * getMD5() override { return "7c268a4c45fff761880cedd06523bad5"; };

  };

  class FaceLearningResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    FaceLearningResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return FACELEARNING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class FaceLearning {
    public:
    typedef FaceLearningRequest Request;
    typedef FaceLearningResponse Response;
  };

}
#endif
