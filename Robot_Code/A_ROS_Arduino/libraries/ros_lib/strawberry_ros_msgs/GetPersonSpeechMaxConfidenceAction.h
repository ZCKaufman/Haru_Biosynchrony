#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceAction_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceActionGoal.h"
#include "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceActionResult.h"
#include "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceActionFeedback.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechMaxConfidenceAction : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::GetPersonSpeechMaxConfidenceActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef strawberry_ros_msgs::GetPersonSpeechMaxConfidenceActionResult _action_result_type;
      _action_result_type action_result;
      typedef strawberry_ros_msgs::GetPersonSpeechMaxConfidenceActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GetPersonSpeechMaxConfidenceAction():
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceAction"; };
    virtual const char * getMD5() override { return "61418b3ffe4455373f3842aed1e01ca0"; };

  };

}
#endif
