#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoRequestImageGoal_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoRequestImageGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoRequestImageGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _message_type;
      _message_type message;
      uint32_t available_tags_length;
      typedef std_msgs::String _available_tags_type;
      _available_tags_type st_available_tags;
      _available_tags_type * available_tags;
      typedef std_msgs::Float64 _timeout_type;
      _timeout_type timeout;

    PseudoRequestImageGoal():
      header(),
      message(),
      available_tags_length(0), st_available_tags(), available_tags(nullptr),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->message.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->available_tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->available_tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->available_tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->available_tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->available_tags_length);
      for( uint32_t i = 0; i < available_tags_length; i++){
      offset += this->available_tags[i].serialize(outbuffer + offset);
      }
      offset += this->timeout.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->message.deserialize(inbuffer + offset);
      uint32_t available_tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      available_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      available_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      available_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->available_tags_length);
      if(available_tags_lengthT > available_tags_length)
        this->available_tags = (std_msgs::String*)realloc(this->available_tags, available_tags_lengthT * sizeof(std_msgs::String));
      available_tags_length = available_tags_lengthT;
      for( uint32_t i = 0; i < available_tags_length; i++){
      offset += this->st_available_tags.deserialize(inbuffer + offset);
        memcpy( &(this->available_tags[i]), &(this->st_available_tags), sizeof(std_msgs::String));
      }
      offset += this->timeout.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoRequestImageGoal"; };
    virtual const char * getMD5() override { return "2890a6d19e8347af94025004f2d139c9"; };

  };

}
#endif
