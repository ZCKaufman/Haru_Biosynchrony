#ifndef _ROS_strawberry_ros_msgs_FaceSubframe_h
#define _ROS_strawberry_ros_msgs_FaceSubframe_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/BoundingBox.h"
#include "sensor_msgs/CompressedImage.h"

namespace strawberry_ros_msgs
{

  class FaceSubframe : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::BoundingBox _bb_type;
      _bb_type bb;
      typedef sensor_msgs::CompressedImage _img_type;
      _img_type img;

    FaceSubframe():
      bb(),
      img()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->bb.serialize(outbuffer + offset);
      offset += this->img.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->bb.deserialize(inbuffer + offset);
      offset += this->img.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/FaceSubframe"; };
    virtual const char * getMD5() override { return "6824ef4b89f29f6ae755cf3c21f1d2fb"; };

  };

}
#endif
