#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechByIdActionResult_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechByIdActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "strawberry_ros_msgs/GetPersonSpeechByIdResult.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechByIdActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef strawberry_ros_msgs::GetPersonSpeechByIdResult _result_type;
      _result_type result;

    GetPersonSpeechByIdActionResult():
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechByIdActionResult"; };
    virtual const char * getMD5() override { return "606717e805c1331e8f20bd28555b3efb"; };

  };

}
#endif
