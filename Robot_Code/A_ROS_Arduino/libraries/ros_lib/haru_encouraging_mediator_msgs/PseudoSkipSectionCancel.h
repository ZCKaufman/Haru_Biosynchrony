#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoSkipSectionCancel_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoSkipSectionCancel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Bool.h"
#include "std_msgs/UInt32.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoSkipSectionCancel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Bool _cancel_type;
      _cancel_type cancel;
      typedef std_msgs::UInt32 _stage_id_type;
      _stage_id_type stage_id;

    PseudoSkipSectionCancel():
      header(),
      cancel(),
      stage_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cancel.serialize(outbuffer + offset);
      offset += this->stage_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cancel.deserialize(inbuffer + offset);
      offset += this->stage_id.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoSkipSectionCancel"; };
    virtual const char * getMD5() override { return "83c554c543b8e8781d819d856cd5ed20"; };

  };

}
#endif
