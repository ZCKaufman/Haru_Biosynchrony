#ifndef _ROS_strawberry_ros_msgs_WaitSpeakingStartsActionResult_h
#define _ROS_strawberry_ros_msgs_WaitSpeakingStartsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "strawberry_ros_msgs/WaitSpeakingStartsResult.h"

namespace strawberry_ros_msgs
{

  class WaitSpeakingStartsActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef strawberry_ros_msgs::WaitSpeakingStartsResult _result_type;
      _result_type result;

    WaitSpeakingStartsActionResult():
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

    virtual const char * getType() override { return "strawberry_ros_msgs/WaitSpeakingStartsActionResult"; };
    virtual const char * getMD5() override { return "0b6fa314624cd54bbf0c7495c94063b7"; };

  };

}
#endif