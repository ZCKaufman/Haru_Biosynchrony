#ifndef _ROS_behavior_tree_ros_BehaviorTreeFeedback_h
#define _ROS_behavior_tree_ros_BehaviorTreeFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace behavior_tree_ros
{

  class BehaviorTreeFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::String _status_type;
      _status_type status;

    BehaviorTreeFeedback():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/BehaviorTreeFeedback"; };
    virtual const char * getMD5() override { return "da740a2c07d1e6cb851fc1b477c8705a"; };

  };

}
#endif
