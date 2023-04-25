#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceGoal_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechMaxConfidenceGoal : public ros::Msg
  {
    public:
      typedef float _timeout_type;
      _timeout_type timeout;

    GetPersonSpeechMaxConfidenceGoal():
      timeout(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceGoal"; };
    virtual const char * getMD5() override { return "8e929ace7fd80dc265b8b96078f41e82"; };

  };

}
#endif
