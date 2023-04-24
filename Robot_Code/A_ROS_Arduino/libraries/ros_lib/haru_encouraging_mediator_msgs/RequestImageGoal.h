#ifndef _ROS_haru_encouraging_mediator_msgs_RequestImageGoal_h
#define _ROS_haru_encouraging_mediator_msgs_RequestImageGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace haru_encouraging_mediator_msgs
{

  class RequestImageGoal : public ros::Msg
  {
    public:
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type ipad_ids;
      typedef std_msgs::String _message_type;
      _message_type message;
      typedef std_msgs::String _available_tags_type;
      _available_tags_type available_tags;
      typedef std_msgs::Float64 _timeout_type;
      _timeout_type timeout;

    RequestImageGoal():
      ipad_ids(),
      message(),
      available_tags(),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->ipad_ids.serialize(outbuffer + offset);
      offset += this->message.serialize(outbuffer + offset);
      offset += this->available_tags.serialize(outbuffer + offset);
      offset += this->timeout.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->ipad_ids.deserialize(inbuffer + offset);
      offset += this->message.deserialize(inbuffer + offset);
      offset += this->available_tags.deserialize(inbuffer + offset);
      offset += this->timeout.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/RequestImageGoal"; };
    virtual const char * getMD5() override { return "333e1745560f23c230551b7c8ca99cd8"; };

  };

}
#endif
