#ifndef _ROS_strawberry_ros_msgs_EntitySpan_h
#define _ROS_strawberry_ros_msgs_EntitySpan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class EntitySpan : public ros::Msg
  {
    public:
      typedef uint16_t _span_start_type;
      _span_start_type span_start;
      typedef uint16_t _span_end_type;
      _span_end_type span_end;
      typedef const char* _span_text_type;
      _span_text_type span_text;
      typedef const char* _entity_type_type;
      _entity_type_type entity_type;
      typedef const char* _related_word_type;
      _related_word_type related_word;

    EntitySpan():
      span_start(0),
      span_end(0),
      span_text(""),
      entity_type(""),
      related_word("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->span_start >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->span_start >> (8 * 1)) & 0xFF;
      offset += sizeof(this->span_start);
      *(outbuffer + offset + 0) = (this->span_end >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->span_end >> (8 * 1)) & 0xFF;
      offset += sizeof(this->span_end);
      uint32_t length_span_text = strlen(this->span_text);
      varToArr(outbuffer + offset, length_span_text);
      offset += 4;
      memcpy(outbuffer + offset, this->span_text, length_span_text);
      offset += length_span_text;
      uint32_t length_entity_type = strlen(this->entity_type);
      varToArr(outbuffer + offset, length_entity_type);
      offset += 4;
      memcpy(outbuffer + offset, this->entity_type, length_entity_type);
      offset += length_entity_type;
      uint32_t length_related_word = strlen(this->related_word);
      varToArr(outbuffer + offset, length_related_word);
      offset += 4;
      memcpy(outbuffer + offset, this->related_word, length_related_word);
      offset += length_related_word;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->span_start =  ((uint16_t) (*(inbuffer + offset)));
      this->span_start |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->span_start);
      this->span_end =  ((uint16_t) (*(inbuffer + offset)));
      this->span_end |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->span_end);
      uint32_t length_span_text;
      arrToVar(length_span_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_span_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_span_text-1]=0;
      this->span_text = (char *)(inbuffer + offset-1);
      offset += length_span_text;
      uint32_t length_entity_type;
      arrToVar(length_entity_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_entity_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_entity_type-1]=0;
      this->entity_type = (char *)(inbuffer + offset-1);
      offset += length_entity_type;
      uint32_t length_related_word;
      arrToVar(length_related_word, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_related_word; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_related_word-1]=0;
      this->related_word = (char *)(inbuffer + offset-1);
      offset += length_related_word;
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/EntitySpan"; };
    virtual const char * getMD5() override { return "7b4b41d129bce56b28839748c2fa3e21"; };

  };

}
#endif
