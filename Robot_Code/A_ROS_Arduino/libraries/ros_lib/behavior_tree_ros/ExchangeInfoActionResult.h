#ifndef _ROS_behavior_tree_ros_ExchangeInfoActionResult_h
#define _ROS_behavior_tree_ros_ExchangeInfoActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "behavior_tree_ros/ExchangeInfoResult.h"

namespace behavior_tree_ros
{

  class ExchangeInfoActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef behavior_tree_ros::ExchangeInfoResult _result_type;
      _result_type result;

    ExchangeInfoActionResult():
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

    virtual const char * getType() override { return "behavior_tree_ros/ExchangeInfoActionResult"; };
    virtual const char * getMD5() override { return "b00ae5d283f044e619f880f61f9567d2"; };

  };

}
#endif
