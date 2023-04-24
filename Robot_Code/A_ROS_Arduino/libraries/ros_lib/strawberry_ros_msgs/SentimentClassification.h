#ifndef _ROS_strawberry_ros_msgs_SentimentClassification_h
#define _ROS_strawberry_ros_msgs_SentimentClassification_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/GenericClassificationResult.h"

namespace strawberry_ros_msgs
{

  class SentimentClassification : public ros::Msg
  {
    public:
      typedef const char* _sentence_type;
      _sentence_type sentence;
      typedef strawberry_ros_msgs::GenericClassificationResult _sentiment_type;
      _sentiment_type sentiment;

    SentimentClassification():
      sentence(""),
      sentiment()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_sentence = strlen(this->sentence);
      varToArr(outbuffer + offset, length_sentence);
      offset += 4;
      memcpy(outbuffer + offset, this->sentence, length_sentence);
      offset += length_sentence;
      offset += this->sentiment.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_sentence;
      arrToVar(length_sentence, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sentence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sentence-1]=0;
      this->sentence = (char *)(inbuffer + offset-1);
      offset += length_sentence;
      offset += this->sentiment.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/SentimentClassification"; };
    virtual const char * getMD5() override { return "8cac9c1df3ebd33cef46c5f08e777a7a"; };

  };

}
#endif
