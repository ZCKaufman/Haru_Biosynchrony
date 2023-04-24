#ifndef _ROS_SERVICE_Routine_h
#define _ROS_SERVICE_Routine_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char ROUTINE[] = "idmind_tabletop_msgs/Routine";

  class RoutineRequest : public ros::Msg
  {
    public:
      typedef uint32_t _routine_type;
      _routine_type routine;

    RoutineRequest():
      routine(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->routine >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->routine >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->routine >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->routine >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routine);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->routine =  ((uint32_t) (*(inbuffer + offset)));
      this->routine |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->routine |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->routine |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->routine);
     return offset;
    }

    virtual const char * getType() override { return ROUTINE; };
    virtual const char * getMD5() override { return "24b5f71693b73f25c85ee25a86cd5a12"; };

  };

  class RoutineResponse : public ros::Msg
  {
    public:

    RoutineResponse()
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

    virtual const char * getType() override { return ROUTINE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Routine {
    public:
    typedef RoutineRequest Request;
    typedef RoutineResponse Response;
  };

}
#endif
