#ifndef _ROS_SERVICE_CountTime_h
#define _ROS_SERVICE_CountTime_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/UInt64.h"
#include "std_msgs/UInt8.h"

namespace idmind_tabletop_msgs
{

static const char COUNTTIME[] = "idmind_tabletop_msgs/CountTime";

  class CountTimeRequest : public ros::Msg
  {
    public:
      typedef std_msgs::UInt8 _timer_id_type;
      _timer_id_type timer_id;
      typedef std_msgs::UInt8 _command_type;
      _command_type command;
      enum { START =  0 };
      enum { STOP =  1 };

    CountTimeRequest():
      timer_id(),
      command()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->timer_id.serialize(outbuffer + offset);
      offset += this->command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->timer_id.deserialize(inbuffer + offset);
      offset += this->command.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return COUNTTIME; };
    virtual const char * getMD5() override { return "eda78739a31c3ad1ba897392579393a3"; };

  };

  class CountTimeResponse : public ros::Msg
  {
    public:
      typedef std_msgs::UInt64 _time_elapsed_type;
      _time_elapsed_type time_elapsed;

    CountTimeResponse():
      time_elapsed()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->time_elapsed.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->time_elapsed.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return COUNTTIME; };
    virtual const char * getMD5() override { return "226d06dd5fc890ab6af28b18e589550f"; };

  };

  class CountTime {
    public:
    typedef CountTimeRequest Request;
    typedef CountTimeResponse Response;
  };

}
#endif
