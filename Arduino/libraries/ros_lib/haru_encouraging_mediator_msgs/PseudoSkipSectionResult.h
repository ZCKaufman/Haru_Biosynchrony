#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoSkipSectionResult_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoSkipSectionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Bool.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoSkipSectionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Bool _skip_type;
      _skip_type skip;

    PseudoSkipSectionResult():
      header(),
      skip()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->skip.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->skip.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoSkipSectionResult"; };
    virtual const char * getMD5() override { return "f864e827c9bc14f5f17df4acd47440ba"; };

  };

}
#endif
