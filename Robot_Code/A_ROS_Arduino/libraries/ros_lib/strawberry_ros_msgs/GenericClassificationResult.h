#ifndef _ROS_strawberry_ros_msgs_GenericClassificationResult_h
#define _ROS_strawberry_ros_msgs_GenericClassificationResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/ClassificationResults.h"

namespace strawberry_ros_msgs
{

  class GenericClassificationResult : public ros::Msg
  {
    public:
      typedef const char* _classifier_name_type;
      _classifier_name_type classifier_name;
      typedef strawberry_ros_msgs::ClassificationResults _results_type;
      _results_type results;

    GenericClassificationResult():
      classifier_name(""),
      results()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_classifier_name = strlen(this->classifier_name);
      varToArr(outbuffer + offset, length_classifier_name);
      offset += 4;
      memcpy(outbuffer + offset, this->classifier_name, length_classifier_name);
      offset += length_classifier_name;
      offset += this->results.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_classifier_name;
      arrToVar(length_classifier_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_classifier_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_classifier_name-1]=0;
      this->classifier_name = (char *)(inbuffer + offset-1);
      offset += length_classifier_name;
      offset += this->results.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/GenericClassificationResult"; };
    virtual const char * getMD5() override { return "282bf8952cc3da0ed085db9c0a5fbbd5"; };

  };

}
#endif
