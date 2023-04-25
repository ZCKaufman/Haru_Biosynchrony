#ifndef _ROS_haru_encouraging_mediator_msgs_DialogAction_h
#define _ROS_haru_encouraging_mediator_msgs_DialogAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "haru_encouraging_mediator_msgs/DialogActionGoal.h"
#include "haru_encouraging_mediator_msgs/DialogActionResult.h"
#include "haru_encouraging_mediator_msgs/DialogActionFeedback.h"

namespace haru_encouraging_mediator_msgs
{

  class DialogAction : public ros::Msg
  {
    public:
      typedef haru_encouraging_mediator_msgs::DialogActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef haru_encouraging_mediator_msgs::DialogActionResult _action_result_type;
      _action_result_type action_result;
      typedef haru_encouraging_mediator_msgs::DialogActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    DialogAction():
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

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/DialogAction"; };
    virtual const char * getMD5() override { return "43486826c328bb590bc123c95a84d98c"; };

  };

}
#endif
