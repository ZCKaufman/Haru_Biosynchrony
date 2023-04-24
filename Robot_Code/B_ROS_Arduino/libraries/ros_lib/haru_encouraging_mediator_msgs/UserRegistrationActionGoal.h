#ifndef _ROS_haru_encouraging_mediator_msgs_UserRegistrationActionGoal_h
#define _ROS_haru_encouraging_mediator_msgs_UserRegistrationActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "haru_encouraging_mediator_msgs/UserRegistrationGoal.h"

namespace haru_encouraging_mediator_msgs
{

  class UserRegistrationActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef haru_encouraging_mediator_msgs::UserRegistrationGoal _goal_type;
      _goal_type goal;

    UserRegistrationActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UserRegistrationActionGoal"; };
    virtual const char * getMD5() override { return "c50cbc3ad3d0731fa96a411855a245ca"; };

  };

}
#endif
