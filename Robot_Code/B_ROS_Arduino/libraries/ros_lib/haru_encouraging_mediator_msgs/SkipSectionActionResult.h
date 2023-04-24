#ifndef _ROS_haru_encouraging_mediator_msgs_SkipSectionActionResult_h
#define _ROS_haru_encouraging_mediator_msgs_SkipSectionActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "haru_encouraging_mediator_msgs/SkipSectionResult.h"

namespace haru_encouraging_mediator_msgs
{

  class SkipSectionActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef haru_encouraging_mediator_msgs::SkipSectionResult _result_type;
      _result_type result;

    SkipSectionActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/SkipSectionActionResult"; };
    virtual const char * getMD5() override { return "2e13db0dacff3f3d7889fddd2d0fe230"; };

  };

}
#endif
