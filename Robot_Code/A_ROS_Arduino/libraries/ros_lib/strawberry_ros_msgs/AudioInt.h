#ifndef _ROS_strawberry_ros_msgs_AudioInt_h
#define _ROS_strawberry_ros_msgs_AudioInt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int16MultiArray.h"

namespace strawberry_ros_msgs
{

  class AudioInt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Int16MultiArray _array_type;
      _array_type array;

    AudioInt():
      header(),
      array()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->array.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->array.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/AudioInt"; };
    virtual const char * getMD5() override { return "6306ca20bab5dfd7cc89cca8c25b5302"; };

  };

}
#endif
