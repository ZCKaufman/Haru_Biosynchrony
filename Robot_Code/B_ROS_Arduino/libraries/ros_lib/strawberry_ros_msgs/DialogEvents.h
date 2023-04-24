#ifndef _ROS_strawberry_ros_msgs_DialogEvents_h
#define _ROS_strawberry_ros_msgs_DialogEvents_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/DialogEvent.h"

namespace strawberry_ros_msgs
{

  class DialogEvents : public ros::Msg
  {
    public:
      uint32_t events_length;
      typedef strawberry_ros_msgs::DialogEvent _events_type;
      _events_type st_events;
      _events_type * events;

    DialogEvents():
      events_length(0), st_events(), events(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->events_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->events_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->events_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->events_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->events_length);
      for( uint32_t i = 0; i < events_length; i++){
      offset += this->events[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t events_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      events_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      events_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      events_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->events_length);
      if(events_lengthT > events_length)
        this->events = (strawberry_ros_msgs::DialogEvent*)realloc(this->events, events_lengthT * sizeof(strawberry_ros_msgs::DialogEvent));
      events_length = events_lengthT;
      for( uint32_t i = 0; i < events_length; i++){
      offset += this->st_events.deserialize(inbuffer + offset);
        memcpy( &(this->events[i]), &(this->st_events), sizeof(strawberry_ros_msgs::DialogEvent));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogEvents"; };
    virtual const char * getMD5() override { return "8db956c6120bb5716a0270f95a8ea16c"; };

  };

}
#endif
