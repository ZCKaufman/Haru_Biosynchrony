#ifndef _ROS_idmind_tabletop_msgs_MultiRoutineAction_h
#define _ROS_idmind_tabletop_msgs_MultiRoutineAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/MultiRoutineActionGoal.h"
#include "idmind_tabletop_msgs/MultiRoutineActionResult.h"
#include "idmind_tabletop_msgs/MultiRoutineActionFeedback.h"

namespace idmind_tabletop_msgs
{

  class MultiRoutineAction : public ros::Msg
  {
    public:
      typedef idmind_tabletop_msgs::MultiRoutineActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef idmind_tabletop_msgs::MultiRoutineActionResult _action_result_type;
      _action_result_type action_result;
      typedef idmind_tabletop_msgs::MultiRoutineActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MultiRoutineAction():
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

    virtual const char * getType() override { return "idmind_tabletop_msgs/MultiRoutineAction"; };
    virtual const char * getMD5() override { return "9384370da1fddf84ba26778d1344b867"; };

  };

}
#endif
