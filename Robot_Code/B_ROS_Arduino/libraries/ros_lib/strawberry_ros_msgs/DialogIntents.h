#ifndef _ROS_strawberry_ros_msgs_DialogIntents_h
#define _ROS_strawberry_ros_msgs_DialogIntents_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/DialogIntent.h"

namespace strawberry_ros_msgs
{

  class DialogIntents : public ros::Msg
  {
    public:
      uint32_t intents_length;
      typedef strawberry_ros_msgs::DialogIntent _intents_type;
      _intents_type st_intents;
      _intents_type * intents;

    DialogIntents():
      intents_length(0), st_intents(), intents(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->intents_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->intents_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->intents_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->intents_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intents_length);
      for( uint32_t i = 0; i < intents_length; i++){
      offset += this->intents[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t intents_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      intents_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      intents_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      intents_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->intents_length);
      if(intents_lengthT > intents_length)
        this->intents = (strawberry_ros_msgs::DialogIntent*)realloc(this->intents, intents_lengthT * sizeof(strawberry_ros_msgs::DialogIntent));
      intents_length = intents_lengthT;
      for( uint32_t i = 0; i < intents_length; i++){
      offset += this->st_intents.deserialize(inbuffer + offset);
        memcpy( &(this->intents[i]), &(this->st_intents), sizeof(strawberry_ros_msgs::DialogIntent));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogIntents"; };
    virtual const char * getMD5() override { return "881cc1a9525596587d440575d374f1ec"; };

  };

}
#endif
