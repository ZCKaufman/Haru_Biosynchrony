#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoSyncPointButtonFeedback_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoSyncPointButtonFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoSyncPointButtonFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _feedback_type;
      _feedback_type feedback;

    PseudoSyncPointButtonFeedback():
      header(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoSyncPointButtonFeedback"; };
    virtual const char * getMD5() override { return "bd953e0d6d58f144a9121956f872055f"; };

  };

}
#endif
