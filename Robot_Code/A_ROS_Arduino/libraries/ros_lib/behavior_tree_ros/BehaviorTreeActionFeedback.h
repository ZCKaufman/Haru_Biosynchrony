#ifndef _ROS_behavior_tree_ros_BehaviorTreeActionFeedback_h
#define _ROS_behavior_tree_ros_BehaviorTreeActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "behavior_tree_ros/BehaviorTreeFeedback.h"

namespace behavior_tree_ros
{

  class BehaviorTreeActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef behavior_tree_ros::BehaviorTreeFeedback _feedback_type;
      _feedback_type feedback;

    BehaviorTreeActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/BehaviorTreeActionFeedback"; };
    virtual const char * getMD5() override { return "bc43b414526b84873c74e9493d64b628"; };

  };

}
#endif
