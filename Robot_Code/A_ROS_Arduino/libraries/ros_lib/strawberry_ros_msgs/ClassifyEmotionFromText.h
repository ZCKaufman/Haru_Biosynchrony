#ifndef _ROS_SERVICE_ClassifyEmotionFromText_h
#define _ROS_SERVICE_ClassifyEmotionFromText_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/EmotionClassification.h"

namespace strawberry_ros_msgs
{

static const char CLASSIFYEMOTIONFROMTEXT[] = "strawberry_ros_msgs/ClassifyEmotionFromText";

  class ClassifyEmotionFromTextRequest : public ros::Msg
  {
    public:
      typedef const char* _transcription_type;
      _transcription_type transcription;

    ClassifyEmotionFromTextRequest():
      transcription("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_transcription = strlen(this->transcription);
      varToArr(outbuffer + offset, length_transcription);
      offset += 4;
      memcpy(outbuffer + offset, this->transcription, length_transcription);
      offset += length_transcription;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_transcription;
      arrToVar(length_transcription, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transcription; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transcription-1]=0;
      this->transcription = (char *)(inbuffer + offset-1);
      offset += length_transcription;
     return offset;
    }

    virtual const char * getType() override { return CLASSIFYEMOTIONFROMTEXT; };
    virtual const char * getMD5() override { return "d87ceb831c5fd1ff2239ff1c5b3dfc96"; };

  };

  class ClassifyEmotionFromTextResponse : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::EmotionClassification _emotions_type;
      _emotions_type emotions;

    ClassifyEmotionFromTextResponse():
      emotions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->emotions.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->emotions.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CLASSIFYEMOTIONFROMTEXT; };
    virtual const char * getMD5() override { return "dae77bafa98b46e534dd7d57fea51640"; };

  };

  class ClassifyEmotionFromText {
    public:
    typedef ClassifyEmotionFromTextRequest Request;
    typedef ClassifyEmotionFromTextResponse Response;
  };

}
#endif
