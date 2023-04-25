#ifndef _ROS_behavior_tree_ros_BehaviorTreeAction_h
#define _ROS_behavior_tree_ros_BehaviorTreeAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "behavior_tree_ros/BehaviorTreeActionGoal.h"
#include "behavior_tree_ros/BehaviorTreeActionResult.h"
#include "behavior_tree_ros/BehaviorTreeActionFeedback.h"

namespace behavior_tree_ros
{

  class BehaviorTreeAction : public ros::Msg
  {
    public:
      typedef behavior_tree_ros::BehaviorTreeActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef behavior_tree_ros::BehaviorTreeActionResult _action_result_type;
      _action_result_type action_result;
      typedef behavior_tree_ros::BehaviorTreeActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    BehaviorTreeAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/BehaviorTreeAction"; };
    virtual const char * getMD5() override { return "537c0a0821c770ce216974f50c6bd6d7"; };

  };

}
#endif
