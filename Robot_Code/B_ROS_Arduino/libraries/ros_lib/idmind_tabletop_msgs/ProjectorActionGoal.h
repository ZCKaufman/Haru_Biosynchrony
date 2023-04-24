#ifndef _ROS_idmind_tabletop_msgs_ProjectorActionGoal_h
#define _ROS_idmind_tabletop_msgs_ProjectorActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "idmind_tabletop_msgs/ProjectorGoal.h"

namespace idmind_tabletop_msgs
{

  class ProjectorActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef idmind_tabletop_msgs::ProjectorGoal _goal_type;
      _goal_type goal;

    ProjectorActionGoal():
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

    virtual const char * getType() override { return "idmind_tabletop_msgs/ProjectorActionGoal"; };
    virtual const char * getMD5() override { return "48d2df491afb1e719ef18b899f25bd03"; };

  };

}
#endif
