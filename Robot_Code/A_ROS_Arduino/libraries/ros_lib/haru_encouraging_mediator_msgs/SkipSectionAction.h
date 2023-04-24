#ifndef _ROS_haru_encouraging_mediator_msgs_SkipSectionAction_h
#define _ROS_haru_encouraging_mediator_msgs_SkipSectionAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "haru_encouraging_mediator_msgs/SkipSectionActionGoal.h"
#include "haru_encouraging_mediator_msgs/SkipSectionActionResult.h"
#include "haru_encouraging_mediator_msgs/SkipSectionActionFeedback.h"

namespace haru_encouraging_mediator_msgs
{

  class SkipSectionAction : public ros::Msg
  {
    public:
      typedef haru_encouraging_mediator_msgs::SkipSectionActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef haru_encouraging_mediator_msgs::SkipSectionActionResult _action_result_type;
      _action_result_type action_result;
      typedef haru_encouraging_mediator_msgs::SkipSectionActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SkipSectionAction():
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

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/SkipSectionAction"; };
    virtual const char * getMD5() override { return "fd9148774717d14607b9bc017c252565"; };

  };

}
#endif
