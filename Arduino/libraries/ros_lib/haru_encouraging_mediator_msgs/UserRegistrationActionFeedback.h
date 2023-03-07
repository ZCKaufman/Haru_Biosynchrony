#ifndef _ROS_haru_encouraging_mediator_msgs_UserRegistrationActionFeedback_h
#define _ROS_haru_encouraging_mediator_msgs_UserRegistrationActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "haru_encouraging_mediator_msgs/UserRegistrationFeedback.h"

namespace haru_encouraging_mediator_msgs
{

  class UserRegistrationActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef haru_encouraging_mediator_msgs::UserRegistrationFeedback _feedback_type;
      _feedback_type feedback;

    UserRegistrationActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UserRegistrationActionFeedback"; };
    virtual const char * getMD5() override { return "3fc91d83b4fe5ed67be2620e4fb3a89d"; };

  };

}
#endif
