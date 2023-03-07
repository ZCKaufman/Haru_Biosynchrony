#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceActionGoal_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceGoal.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechMaxConfidenceActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef strawberry_ros_msgs::GetPersonSpeechMaxConfidenceGoal _goal_type;
      _goal_type goal;

    GetPersonSpeechMaxConfidenceActionGoal():
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

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceActionGoal"; };
    virtual const char * getMD5() override { return "04343e7f5da44b9511fabad7d8d1db7b"; };

  };

}
#endif
