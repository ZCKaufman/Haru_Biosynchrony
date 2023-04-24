#ifndef _ROS_strawberry_ros_msgs_WaitSpeakingStartsGoal_h
#define _ROS_strawberry_ros_msgs_WaitSpeakingStartsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class WaitSpeakingStartsGoal : public ros::Msg
  {
    public:
      typedef int32_t _mics_id_type;
      _mics_id_type mics_id;
      typedef uint32_t _timeout_type;
      _timeout_type timeout;

    WaitSpeakingStartsGoal():
      mics_id(0),
      timeout(0)
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
      *(outbuffer + offset + 0) = (this->timeout >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
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
      this->timeout =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/WaitSpeakingStartsGoal"; };
    virtual const char * getMD5() override { return "3d3e56d44d25f3ac0a5b8c1a832da0d8"; };

  };

}
#endif
