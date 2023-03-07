#ifndef _ROS_behavior_tree_ros_ExchangeInfoAction_h
#define _ROS_behavior_tree_ros_ExchangeInfoAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "behavior_tree_ros/ExchangeInfoActionGoal.h"
#include "behavior_tree_ros/ExchangeInfoActionResult.h"
#include "behavior_tree_ros/ExchangeInfoActionFeedback.h"

namespace behavior_tree_ros
{

  class ExchangeInfoAction : public ros::Msg
  {
    public:
      typedef behavior_tree_ros::ExchangeInfoActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef behavior_tree_ros::ExchangeInfoActionResult _action_result_type;
      _action_result_type action_result;
      typedef behavior_tree_ros::ExchangeInfoActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    ExchangeInfoAction():
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

    virtual const char * getType() override { return "behavior_tree_ros/ExchangeInfoAction"; };
    virtual const char * getMD5() override { return "a3949fdb181a5a135065befa4b6f2ea5"; };

  };

}
#endif
