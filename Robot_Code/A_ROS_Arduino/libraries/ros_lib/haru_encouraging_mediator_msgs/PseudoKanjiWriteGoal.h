#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoKanjiWriteGoal_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoKanjiWriteGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoKanjiWriteGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _message_type;
      _message_type message;
      typedef std_msgs::Float64 _timeout_type;
      _timeout_type timeout;

    PseudoKanjiWriteGoal():
      header(),
      message(),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->message.serialize(outbuffer + offset);
      offset += this->timeout.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->message.deserialize(inbuffer + offset);
      offset += this->timeout.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoKanjiWriteGoal"; };
    virtual const char * getMD5() override { return "e59e0b3ee56920012a5b8a52d2eec59e"; };

  };

}
#endif
