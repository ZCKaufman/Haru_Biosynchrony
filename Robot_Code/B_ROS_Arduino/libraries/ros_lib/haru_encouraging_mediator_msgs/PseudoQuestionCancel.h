#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoQuestionCancel_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoQuestionCancel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoQuestionCancel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Bool _cancel_type;
      _cancel_type cancel;
      typedef std_msgs::String _user_id_type;
      _user_id_type user_id;
      typedef std_msgs::UInt8 _ipad_id_type;
      _ipad_id_type ipad_id;

    PseudoQuestionCancel():
      header(),
      cancel(),
      user_id(),
      ipad_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cancel.serialize(outbuffer + offset);
      offset += this->user_id.serialize(outbuffer + offset);
      offset += this->ipad_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cancel.deserialize(inbuffer + offset);
      offset += this->user_id.deserialize(inbuffer + offset);
      offset += this->ipad_id.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoQuestionCancel"; };
    virtual const char * getMD5() override { return "3ab05447012fdc42c0b1e6a6043c2c71"; };

  };

}
#endif
