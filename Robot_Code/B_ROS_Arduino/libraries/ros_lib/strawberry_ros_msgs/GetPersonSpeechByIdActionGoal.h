#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechByIdActionGoal_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechByIdActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "strawberry_ros_msgs/GetPersonSpeechByIdGoal.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechByIdActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef strawberry_ros_msgs::GetPersonSpeechByIdGoal _goal_type;
      _goal_type goal;

    GetPersonSpeechByIdActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechByIdActionGoal"; };
    virtual const char * getMD5() override { return "7b5236dd382c9a1b7e28fada87bef425"; };

  };

}
#endif
