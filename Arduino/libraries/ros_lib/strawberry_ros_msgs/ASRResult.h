#ifndef _ROS_strawberry_ros_msgs_ASRResult_h
#define _ROS_strawberry_ros_msgs_ASRResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace strawberry_ros_msgs
{

  class ASRResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _transcript_type;
      _transcript_type transcript;
      typedef float _confidence_type;
      _confidence_type confidence;

    ASRResult():
      header(),
      transcript(""),
      confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_transcript = strlen(this->transcript);
      varToArr(outbuffer + offset, length_transcript);
      offset += 4;
      memcpy(outbuffer + offset, this->transcript, length_transcript);
      offset += length_transcript;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_transcript;
      arrToVar(length_transcript, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transcript; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transcript-1]=0;
      this->transcript = (char *)(inbuffer + offset-1);
      offset += length_transcript;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/ASRResult"; };
    virtual const char * getMD5() override { return "8c4f0196f507dd29a0487aaea17e72b2"; };

  };

}
#endif
