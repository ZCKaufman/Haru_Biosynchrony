#ifndef _ROS_behavior_tree_ros_BehaviorTreeActionResult_h
#define _ROS_behavior_tree_ros_BehaviorTreeActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "behavior_tree_ros/BehaviorTreeResult.h"

namespace behavior_tree_ros
{

  class BehaviorTreeActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef behavior_tree_ros::BehaviorTreeResult _result_type;
      _result_type result;

    BehaviorTreeActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/BehaviorTreeActionResult"; };
    virtual const char * getMD5() override { return "e5f62eb2cecdccdb33834c1bf0d40a1c"; };

  };

}
#endif
