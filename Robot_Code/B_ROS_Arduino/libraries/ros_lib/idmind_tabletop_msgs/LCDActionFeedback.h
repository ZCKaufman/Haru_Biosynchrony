#ifndef _ROS_idmind_tabletop_msgs_LCDActionFeedback_h
#define _ROS_idmind_tabletop_msgs_LCDActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "idmind_tabletop_msgs/LCDFeedback.h"

namespace idmind_tabletop_msgs
{

  class LCDActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef idmind_tabletop_msgs::LCDFeedback _feedback_type;
      _feedback_type feedback;

    LCDActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDActionFeedback"; };
    virtual const char * getMD5() override { return "81131b3fd659940bf18b36c55689b588"; };

  };

}
#endif
