#ifndef _ROS_idmind_tabletop_msgs_LCDAction_h
#define _ROS_idmind_tabletop_msgs_LCDAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/LCDActionGoal.h"
#include "idmind_tabletop_msgs/LCDActionResult.h"
#include "idmind_tabletop_msgs/LCDActionFeedback.h"

namespace idmind_tabletop_msgs
{

  class LCDAction : public ros::Msg
  {
    public:
      typedef idmind_tabletop_msgs::LCDActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef idmind_tabletop_msgs::LCDActionResult _action_result_type;
      _action_result_type action_result;
      typedef idmind_tabletop_msgs::LCDActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    LCDAction():
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

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDAction"; };
    virtual const char * getMD5() override { return "6472b95954971a1b8de19b5a0ac83224"; };

  };

}
#endif
