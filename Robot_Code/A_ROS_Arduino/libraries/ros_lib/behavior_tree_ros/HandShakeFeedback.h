#ifndef _ROS_behavior_tree_ros_HandShakeFeedback_h
#define _ROS_behavior_tree_ros_HandShakeFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

  class HandShakeFeedback : public ros::Msg
  {
    public:

    HandShakeFeedback()
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

    virtual const char * getType() override { return "behavior_tree_ros/HandShakeFeedback"; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
