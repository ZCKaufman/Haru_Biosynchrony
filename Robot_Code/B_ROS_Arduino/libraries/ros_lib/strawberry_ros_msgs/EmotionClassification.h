#ifndef _ROS_strawberry_ros_msgs_EmotionClassification_h
#define _ROS_strawberry_ros_msgs_EmotionClassification_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/GenericClassificationResult.h"

namespace strawberry_ros_msgs
{

  class EmotionClassification : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _sentence_type;
      _sentence_type sentence;
      typedef strawberry_ros_msgs::GenericClassificationResult _emotions_type;
      _emotions_type emotions;

    EmotionClassification():
      header(),
      sentence(""),
      emotions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_sentence = strlen(this->sentence);
      varToArr(outbuffer + offset, length_sentence);
      offset += 4;
      memcpy(outbuffer + offset, this->sentence, length_sentence);
      offset += length_sentence;
      offset += this->emotions.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_sentence;
      arrToVar(length_sentence, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sentence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sentence-1]=0;
      this->sentence = (char *)(inbuffer + offset-1);
      offset += length_sentence;
      offset += this->emotions.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/EmotionClassification"; };
    virtual const char * getMD5() override { return "2f0213e0edcec4befd7961560a9ca229"; };

  };

}
#endif
