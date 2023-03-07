#ifndef _ROS_haru_encouraging_mediator_msgs_UserRegistrationGoal_h
#define _ROS_haru_encouraging_mediator_msgs_UserRegistrationGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace haru_encouraging_mediator_msgs
{

  class UserRegistrationGoal : public ros::Msg
  {
    public:
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type ipad_ids;
      typedef std_msgs::Float64 _timeout_type;
      _timeout_type timeout;

    UserRegistrationGoal():
      ipad_ids(),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->ipad_ids.serialize(outbuffer + offset);
      offset += this->timeout.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->ipad_ids.deserialize(inbuffer + offset);
      offset += this->timeout.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UserRegistrationGoal"; };
    virtual const char * getMD5() override { return "fbe87a284a111bf585b4770d8aa05b0d"; };

  };

}
#endif
