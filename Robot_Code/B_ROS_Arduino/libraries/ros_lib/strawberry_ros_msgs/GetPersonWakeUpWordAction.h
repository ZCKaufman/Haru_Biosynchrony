#ifndef _ROS_strawberry_ros_msgs_GetPersonWakeUpWordAction_h
#define _ROS_strawberry_ros_msgs_GetPersonWakeUpWordAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/GetPersonWakeUpWordActionGoal.h"
#include "strawberry_ros_msgs/GetPersonWakeUpWordActionResult.h"
#include "strawberry_ros_msgs/GetPersonWakeUpWordActionFeedback.h"

namespace strawberry_ros_msgs
{

  class GetPersonWakeUpWordAction : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::GetPersonWakeUpWordActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef strawberry_ros_msgs::GetPersonWakeUpWordActionResult _action_result_type;
      _action_result_type action_result;
      typedef strawberry_ros_msgs::GetPersonWakeUpWordActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GetPersonWakeUpWordAction():
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonWakeUpWordAction"; };
    virtual const char * getMD5() override { return "edeeb8fcdeb2ee132ce37d195dac55e7"; };

  };

}
#endif
