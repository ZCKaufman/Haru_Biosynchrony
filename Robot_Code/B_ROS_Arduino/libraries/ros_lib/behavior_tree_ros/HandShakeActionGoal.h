#ifndef _ROS_behavior_tree_ros_HandShakeActionGoal_h
#define _ROS_behavior_tree_ros_HandShakeActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "behavior_tree_ros/HandShakeGoal.h"

namespace behavior_tree_ros
{

  class HandShakeActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef behavior_tree_ros::HandShakeGoal _goal_type;
      _goal_type goal;

    HandShakeActionGoal():
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

    virtual const char * getType() override { return "behavior_tree_ros/HandShakeActionGoal"; };
    virtual const char * getMD5() override { return "11a3900a9f450117e9007e55ee533ed9"; };

  };

}
#endif
