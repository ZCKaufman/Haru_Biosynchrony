#ifndef _ROS_strawberry_ros_msgs_ClassificationResults_h
#define _ROS_strawberry_ros_msgs_ClassificationResults_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/ClassificationResult.h"

namespace strawberry_ros_msgs
{

  class ClassificationResults : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::ClassificationResult _best_match_type;
      _best_match_type best_match;
      uint32_t results_length;
      typedef strawberry_ros_msgs::ClassificationResult _results_type;
      _results_type st_results;
      _results_type * results;

    ClassificationResults():
      best_match(),
      results_length(0), st_results(), results(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->best_match.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->results_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->results_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->results_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->results_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->results_length);
      for( uint32_t i = 0; i < results_length; i++){
      offset += this->results[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->best_match.deserialize(inbuffer + offset);
      uint32_t results_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->results_length);
      if(results_lengthT > results_length)
        this->results = (strawberry_ros_msgs::ClassificationResult*)realloc(this->results, results_lengthT * sizeof(strawberry_ros_msgs::ClassificationResult));
      results_length = results_lengthT;
      for( uint32_t i = 0; i < results_length; i++){
      offset += this->st_results.deserialize(inbuffer + offset);
        memcpy( &(this->results[i]), &(this->st_results), sizeof(strawberry_ros_msgs::ClassificationResult));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/ClassificationResults"; };
    virtual const char * getMD5() override { return "9f74a3c11abc090884cf9bcc506a9580"; };

  };

}
#endif
