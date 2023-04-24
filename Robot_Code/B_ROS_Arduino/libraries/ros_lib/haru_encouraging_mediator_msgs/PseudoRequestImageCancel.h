#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoRequestImageCancel_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoRequestImageCancel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Bool.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoRequestImageCancel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Bool _cancel_type;
      _cancel_type cancel;

    PseudoRequestImageCancel():
      header(),
      cancel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cancel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cancel.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoRequestImageCancel"; };
    virtual const char * getMD5() override { return "82befc45d6983115a77f18db30ea20ad"; };

  };

}
#endif
