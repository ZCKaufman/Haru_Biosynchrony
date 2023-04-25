#ifndef _ROS_strawberry_ros_msgs_Gestures_h
#define _ROS_strawberry_ros_msgs_Gestures_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/Gesture.h"

namespace strawberry_ros_msgs
{

  class Gestures : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t gestures_length;
      typedef strawberry_ros_msgs::Gesture _gestures_type;
      _gestures_type st_gestures;
      _gestures_type * gestures;

    Gestures():
      header(),
      gestures_length(0), st_gestures(), gestures(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->gestures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gestures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gestures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gestures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gestures_length);
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->gestures[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t gestures_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gestures_length);
      if(gestures_lengthT > gestures_length)
        this->gestures = (strawberry_ros_msgs::Gesture*)realloc(this->gestures, gestures_lengthT * sizeof(strawberry_ros_msgs::Gesture));
      gestures_length = gestures_lengthT;
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->st_gestures.deserialize(inbuffer + offset);
        memcpy( &(this->gestures[i]), &(this->st_gestures), sizeof(strawberry_ros_msgs::Gesture));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Gestures"; };
    virtual const char * getMD5() override { return "34a4c03fb37cbf645f115354186f87a0"; };

  };

}
#endif
