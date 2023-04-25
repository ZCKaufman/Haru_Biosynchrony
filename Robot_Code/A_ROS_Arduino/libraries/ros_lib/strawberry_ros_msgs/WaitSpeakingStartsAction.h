#ifndef _ROS_strawberry_ros_msgs_WaitSpeakingStartsAction_h
#define _ROS_strawberry_ros_msgs_WaitSpeakingStartsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/WaitSpeakingStartsActionGoal.h"
#include "strawberry_ros_msgs/WaitSpeakingStartsActionResult.h"
#include "strawberry_ros_msgs/WaitSpeakingStartsActionFeedback.h"

namespace strawberry_ros_msgs
{

  class WaitSpeakingStartsAction : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::WaitSpeakingStartsActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef strawberry_ros_msgs::WaitSpeakingStartsActionResult _action_result_type;
      _action_result_type action_result;
      typedef strawberry_ros_msgs::WaitSpeakingStartsActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    WaitSpeakingStartsAction():
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

    virtual const char * getType() override { return "strawberry_ros_msgs/WaitSpeakingStartsAction"; };
    virtual const char * getMD5() override { return "e8f51a32f29fa0ca6dd3fe52b342540d"; };

  };

}
#endif
