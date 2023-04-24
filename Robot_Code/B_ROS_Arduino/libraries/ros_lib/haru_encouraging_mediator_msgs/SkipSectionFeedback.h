#ifndef _ROS_haru_encouraging_mediator_msgs_SkipSectionFeedback_h
#define _ROS_haru_encouraging_mediator_msgs_SkipSectionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

  class SkipSectionFeedback : public ros::Msg
  {
    public:
      uint32_t feedbacks_length;
      typedef std_msgs::String _feedbacks_type;
      _feedbacks_type st_feedbacks;
      _feedbacks_type * feedbacks;

    SkipSectionFeedback():
      feedbacks_length(0), st_feedbacks(), feedbacks(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->feedbacks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->feedbacks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->feedbacks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->feedbacks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->feedbacks_length);
      for( uint32_t i = 0; i < feedbacks_length; i++){
      offset += this->feedbacks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t feedbacks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      feedbacks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      feedbacks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      feedbacks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->feedbacks_length);
      if(feedbacks_lengthT > feedbacks_length)
        this->feedbacks = (std_msgs::String*)realloc(this->feedbacks, feedbacks_lengthT * sizeof(std_msgs::String));
      feedbacks_length = feedbacks_lengthT;
      for( uint32_t i = 0; i < feedbacks_length; i++){
      offset += this->st_feedbacks.deserialize(inbuffer + offset);
        memcpy( &(this->feedbacks[i]), &(this->st_feedbacks), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/SkipSectionFeedback"; };
    virtual const char * getMD5() override { return "60aa9bf88658157c34e3f62054b35fcb"; };

  };

}
#endif
