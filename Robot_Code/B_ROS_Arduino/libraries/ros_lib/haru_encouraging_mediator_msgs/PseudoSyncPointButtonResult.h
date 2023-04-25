#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoSyncPointButtonResult_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoSyncPointButtonResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoSyncPointButtonResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;

    PseudoSyncPointButtonResult():
      header()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoSyncPointButtonResult"; };
    virtual const char * getMD5() override { return "d7be0bb39af8fb9129d5a76e6b63a290"; };

  };

}
#endif
