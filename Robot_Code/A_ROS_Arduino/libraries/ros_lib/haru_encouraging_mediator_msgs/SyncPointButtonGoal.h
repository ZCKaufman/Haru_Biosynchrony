#ifndef _ROS_haru_encouraging_mediator_msgs_SyncPointButtonGoal_h
#define _ROS_haru_encouraging_mediator_msgs_SyncPointButtonGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class SyncPointButtonGoal : public ros::Msg
  {
    public:

    SyncPointButtonGoal()
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

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/SyncPointButtonGoal"; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
