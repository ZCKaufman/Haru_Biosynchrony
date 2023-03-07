#ifndef _ROS_behavior_tree_ros_HandShakeAction_h
#define _ROS_behavior_tree_ros_HandShakeAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "behavior_tree_ros/HandShakeActionGoal.h"
#include "behavior_tree_ros/HandShakeActionResult.h"
#include "behavior_tree_ros/HandShakeActionFeedback.h"

namespace behavior_tree_ros
{

  class HandShakeAction : public ros::Msg
  {
    public:
      typedef behavior_tree_ros::HandShakeActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef behavior_tree_ros::HandShakeActionResult _action_result_type;
      _action_result_type action_result;
      typedef behavior_tree_ros::HandShakeActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    HandShakeAction():
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

    virtual const char * getType() override { return "behavior_tree_ros/HandShakeAction"; };
    virtual const char * getMD5() override { return "7701d11d7e3d27e30b069c088cac81c8"; };

  };

}
#endif
