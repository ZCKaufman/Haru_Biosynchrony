#ifndef _ROS_haru_encouraging_mediator_msgs_SkipSectionGoal_h
#define _ROS_haru_encouraging_mediator_msgs_SkipSectionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/UInt32.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

  class SkipSectionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::UInt32 _stage_id_type;
      _stage_id_type stage_id;
      typedef std_msgs::String _stage_description_type;
      _stage_description_type stage_description;

    SkipSectionGoal():
      stage_id(),
      stage_description()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->stage_id.serialize(outbuffer + offset);
      offset += this->stage_description.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->stage_id.deserialize(inbuffer + offset);
      offset += this->stage_description.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/SkipSectionGoal"; };
    virtual const char * getMD5() override { return "068c565db856b1fc0e95c4574635934d"; };

  };

}
#endif
