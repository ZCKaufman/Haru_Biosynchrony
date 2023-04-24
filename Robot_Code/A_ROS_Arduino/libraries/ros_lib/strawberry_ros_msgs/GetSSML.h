#ifndef _ROS_SERVICE_GetSSML_h
#define _ROS_SERVICE_GetSSML_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETSSML[] = "strawberry_ros_msgs/GetSSML";

  class GetSSMLRequest : public ros::Msg
  {
    public:
      typedef const char* _criteria_name_type;
      _criteria_name_type criteria_name;
      typedef const char* _routines_anger_type;
      _routines_anger_type routines_anger;
      typedef const char* _routines_disgust_type;
      _routines_disgust_type routines_disgust;
      typedef const char* _routines_fear_type;
      _routines_fear_type routines_fear;
      typedef const char* _routines_joy_type;
      _routines_joy_type routines_joy;
      typedef const char* _routines_neutral_type;
      _routines_neutral_type routines_neutral;
      typedef const char* _routines_sadness_type;
      _routines_sadness_type routines_sadness;
      typedef const char* _routines_surprise_type;
      _routines_surprise_type routines_surprise;

    GetSSMLRequest():
      criteria_name(""),
      routines_anger(""),
      routines_disgust(""),
      routines_fear(""),
      routines_joy(""),
      routines_neutral(""),
      routines_sadness(""),
      routines_surprise("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_criteria_name = strlen(this->criteria_name);
      varToArr(outbuffer + offset, length_criteria_name);
      offset += 4;
      memcpy(outbuffer + offset, this->criteria_name, length_criteria_name);
      offset += length_criteria_name;
      uint32_t length_routines_anger = strlen(this->routines_anger);
      varToArr(outbuffer + offset, length_routines_anger);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_anger, length_routines_anger);
      offset += length_routines_anger;
      uint32_t length_routines_disgust = strlen(this->routines_disgust);
      varToArr(outbuffer + offset, length_routines_disgust);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_disgust, length_routines_disgust);
      offset += length_routines_disgust;
      uint32_t length_routines_fear = strlen(this->routines_fear);
      varToArr(outbuffer + offset, length_routines_fear);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_fear, length_routines_fear);
      offset += length_routines_fear;
      uint32_t length_routines_joy = strlen(this->routines_joy);
      varToArr(outbuffer + offset, length_routines_joy);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_joy, length_routines_joy);
      offset += length_routines_joy;
      uint32_t length_routines_neutral = strlen(this->routines_neutral);
      varToArr(outbuffer + offset, length_routines_neutral);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_neutral, length_routines_neutral);
      offset += length_routines_neutral;
      uint32_t length_routines_sadness = strlen(this->routines_sadness);
      varToArr(outbuffer + offset, length_routines_sadness);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_sadness, length_routines_sadness);
      offset += length_routines_sadness;
      uint32_t length_routines_surprise = strlen(this->routines_surprise);
      varToArr(outbuffer + offset, length_routines_surprise);
      offset += 4;
      memcpy(outbuffer + offset, this->routines_surprise, length_routines_surprise);
      offset += length_routines_surprise;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_criteria_name;
      arrToVar(length_criteria_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_criteria_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_criteria_name-1]=0;
      this->criteria_name = (char *)(inbuffer + offset-1);
      offset += length_criteria_name;
      uint32_t length_routines_anger;
      arrToVar(length_routines_anger, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_anger; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_anger-1]=0;
      this->routines_anger = (char *)(inbuffer + offset-1);
      offset += length_routines_anger;
      uint32_t length_routines_disgust;
      arrToVar(length_routines_disgust, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_disgust; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_disgust-1]=0;
      this->routines_disgust = (char *)(inbuffer + offset-1);
      offset += length_routines_disgust;
      uint32_t length_routines_fear;
      arrToVar(length_routines_fear, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_fear; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_fear-1]=0;
      this->routines_fear = (char *)(inbuffer + offset-1);
      offset += length_routines_fear;
      uint32_t length_routines_joy;
      arrToVar(length_routines_joy, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_joy; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_joy-1]=0;
      this->routines_joy = (char *)(inbuffer + offset-1);
      offset += length_routines_joy;
      uint32_t length_routines_neutral;
      arrToVar(length_routines_neutral, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_neutral; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_neutral-1]=0;
      this->routines_neutral = (char *)(inbuffer + offset-1);
      offset += length_routines_neutral;
      uint32_t length_routines_sadness;
      arrToVar(length_routines_sadness, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_sadness; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_sadness-1]=0;
      this->routines_sadness = (char *)(inbuffer + offset-1);
      offset += length_routines_sadness;
      uint32_t length_routines_surprise;
      arrToVar(length_routines_surprise, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routines_surprise; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routines_surprise-1]=0;
      this->routines_surprise = (char *)(inbuffer + offset-1);
      offset += length_routines_surprise;
     return offset;
    }

    virtual const char * getType() override { return GETSSML; };
    virtual const char * getMD5() override { return "4e19f68bde12a6cb29117633a58571a0"; };

  };

  class GetSSMLResponse : public ros::Msg
  {
    public:
      typedef const char* _ssml_text_type;
      _ssml_text_type ssml_text;
      typedef uint32_t _routine_type;
      _routine_type routine;

    GetSSMLResponse():
      ssml_text(""),
      routine(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_ssml_text = strlen(this->ssml_text);
      varToArr(outbuffer + offset, length_ssml_text);
      offset += 4;
      memcpy(outbuffer + offset, this->ssml_text, length_ssml_text);
      offset += length_ssml_text;
      *(outbuffer + offset + 0) = (this->routine >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->routine >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->routine >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->routine >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routine);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_ssml_text;
      arrToVar(length_ssml_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ssml_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ssml_text-1]=0;
      this->ssml_text = (char *)(inbuffer + offset-1);
      offset += length_ssml_text;
      this->routine =  ((uint32_t) (*(inbuffer + offset)));
      this->routine |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->routine |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->routine |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->routine);
     return offset;
    }

    virtual const char * getType() override { return GETSSML; };
    virtual const char * getMD5() override { return "bb6f3ac66b86a0cfdf337c319b4bb549"; };

  };

  class GetSSML {
    public:
    typedef GetSSMLRequest Request;
    typedef GetSSMLResponse Response;
  };

}
#endif
