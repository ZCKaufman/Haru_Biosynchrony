#ifndef _ROS_behavior_tree_ros_BehaviorTreeGoal_h
#define _ROS_behavior_tree_ros_BehaviorTreeGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace behavior_tree_ros
{

  class BehaviorTreeGoal : public ros::Msg
  {
    public:
      typedef std_msgs::String _tree_file_type;
      _tree_file_type tree_file;

    BehaviorTreeGoal():
      tree_file()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->tree_file.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->tree_file.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/BehaviorTreeGoal"; };
    virtual const char * getMD5() override { return "0e2fd62a361b3692e54b4a6f66736b04"; };

  };

}
#endif
