#ifndef _ROS_haru_encouraging_mediator_msgs_SkipSectionResult_h
#define _ROS_haru_encouraging_mediator_msgs_SkipSectionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Bool.h"

namespace haru_encouraging_mediator_msgs
{

  class SkipSectionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _skip_type;
      _skip_type skip;

    SkipSectionResult():
      skip()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->skip.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->skip.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/SkipSectionResult"; };
    virtual const char * getMD5() override { return "7d6bda5055122ae8a16e5cdb98b37595"; };

  };

}
#endif
