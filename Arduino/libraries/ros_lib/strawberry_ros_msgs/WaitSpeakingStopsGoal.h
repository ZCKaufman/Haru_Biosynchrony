#ifndef _ROS_strawberry_ros_msgs_WaitSpeakingStopsGoal_h
#define _ROS_strawberry_ros_msgs_WaitSpeakingStopsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class WaitSpeakingStopsGoal : public ros::Msg
  {
    public:
      typedef int32_t _mics_id_type;
      _mics_id_type mics_id;
      typedef uint32_t _soft_timeout_type;
      _soft_timeout_type soft_timeout;
      typedef uint32_t _hard_timeout_type;
      _hard_timeout_type hard_timeout;

    WaitSpeakingStopsGoal():
      mics_id(0),
      soft_timeout(0),
      hard_timeout(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_mics_id;
      u_mics_id.real = this->mics_id;
      *(outbuffer + offset + 0) = (u_mics_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mics_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mics_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mics_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mics_id);
      *(outbuffer + offset + 0) = (this->soft_timeout >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->soft_timeout >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->soft_timeout >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->soft_timeout >> (8 * 3)) & 0xFF;
      offset += sizeof(this->soft_timeout);
      *(outbuffer + offset + 0) = (this->hard_timeout >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hard_timeout >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hard_timeout >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hard_timeout >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hard_timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_mics_id;
      u_mics_id.base = 0;
      u_mics_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mics_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mics_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mics_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mics_id = u_mics_id.real;
      offset += sizeof(this->mics_id);
      this->soft_timeout =  ((uint32_t) (*(inbuffer + offset)));
      this->soft_timeout |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->soft_timeout |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->soft_timeout |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->soft_timeout);
      this->hard_timeout =  ((uint32_t) (*(inbuffer + offset)));
      this->hard_timeout |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hard_timeout |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hard_timeout |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hard_timeout);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/WaitSpeakingStopsGoal"; };
    virtual const char * getMD5() override { return "354e900afdb68ab9062775ace754399f"; };

  };

}
#endif
