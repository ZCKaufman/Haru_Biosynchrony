#ifndef _ROS_behavior_tree_ros_ExchangeInfoActionGoal_h
#define _ROS_behavior_tree_ros_ExchangeInfoActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "behavior_tree_ros/ExchangeInfoGoal.h"

namespace behavior_tree_ros
{

  class ExchangeInfoActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef behavior_tree_ros::ExchangeInfoGoal _goal_type;
      _goal_type goal;

    ExchangeInfoActionGoal():
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

    virtual const char * getType() override { return "behavior_tree_ros/ExchangeInfoActionGoal"; };
    virtual const char * getMD5() override { return "17adb261647850951c2a137d6889d9ff"; };

  };

}
#endif
