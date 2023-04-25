#ifndef _ROS_idmind_tabletop_msgs_SendLogsActionResult_h
#define _ROS_idmind_tabletop_msgs_SendLogsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "idmind_tabletop_msgs/SendLogsResult.h"

namespace idmind_tabletop_msgs
{

  class SendLogsActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef idmind_tabletop_msgs::SendLogsResult _result_type;
      _result_type result;

    SendLogsActionResult():
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

    virtual const char * getType() override { return "idmind_tabletop_msgs/SendLogsActionResult"; };
    virtual const char * getMD5() override { return "13bb5dcccf2afdf371a6a33d32581dfd"; };

  };

}
#endif
