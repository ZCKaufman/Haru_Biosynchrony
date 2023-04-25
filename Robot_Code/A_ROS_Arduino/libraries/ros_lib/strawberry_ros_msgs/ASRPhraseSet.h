#ifndef _ROS_strawberry_ros_msgs_ASRPhraseSet_h
#define _ROS_strawberry_ros_msgs_ASRPhraseSet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/ASRPhrase.h"

namespace strawberry_ros_msgs
{

  class ASRPhraseSet : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t phrases_length;
      typedef strawberry_ros_msgs::ASRPhrase _phrases_type;
      _phrases_type st_phrases;
      _phrases_type * phrases;
      typedef float _boost_type;
      _boost_type boost;

    ASRPhraseSet():
      name(""),
      phrases_length(0), st_phrases(), phrases(nullptr),
      boost(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->phrases_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->phrases_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->phrases_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->phrases_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phrases_length);
      for( uint32_t i = 0; i < phrases_length; i++){
      offset += this->phrases[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_boost;
      u_boost.real = this->boost;
      *(outbuffer + offset + 0) = (u_boost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_boost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_boost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_boost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boost);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t phrases_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      phrases_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      phrases_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      phrases_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->phrases_length);
      if(phrases_lengthT > phrases_length)
        this->phrases = (strawberry_ros_msgs::ASRPhrase*)realloc(this->phrases, phrases_lengthT * sizeof(strawberry_ros_msgs::ASRPhrase));
      phrases_length = phrases_lengthT;
      for( uint32_t i = 0; i < phrases_length; i++){
      offset += this->st_phrases.deserialize(inbuffer + offset);
        memcpy( &(this->phrases[i]), &(this->st_phrases), sizeof(strawberry_ros_msgs::ASRPhrase));
      }
      union {
        float real;
        uint32_t base;
      } u_boost;
      u_boost.base = 0;
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_boost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->boost = u_boost.real;
      offset += sizeof(this->boost);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/ASRPhraseSet"; };
    virtual const char * getMD5() override { return "c0e8b039b5469e6416fd3763b12226cc"; };

  };

}
#endif
