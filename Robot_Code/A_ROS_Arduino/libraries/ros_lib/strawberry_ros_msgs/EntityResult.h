#ifndef _ROS_strawberry_ros_msgs_EntityResult_h
#define _ROS_strawberry_ros_msgs_EntityResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/EntitySpan.h"

namespace strawberry_ros_msgs
{

  class EntityResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _utterance_type;
      _utterance_type utterance;
      uint32_t spans_length;
      typedef strawberry_ros_msgs::EntitySpan _spans_type;
      _spans_type st_spans;
      _spans_type * spans;

    EntityResult():
      header(),
      person_id(0),
      utterance(""),
      spans_length(0), st_spans(), spans(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      uint32_t length_utterance = strlen(this->utterance);
      varToArr(outbuffer + offset, length_utterance);
      offset += 4;
      memcpy(outbuffer + offset, this->utterance, length_utterance);
      offset += length_utterance;
      *(outbuffer + offset + 0) = (this->spans_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->spans_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->spans_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->spans_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spans_length);
      for( uint32_t i = 0; i < spans_length; i++){
      offset += this->spans[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
      uint32_t length_utterance;
      arrToVar(length_utterance, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_utterance; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_utterance-1]=0;
      this->utterance = (char *)(inbuffer + offset-1);
      offset += length_utterance;
      uint32_t spans_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      spans_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      spans_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      spans_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->spans_length);
      if(spans_lengthT > spans_length)
        this->spans = (strawberry_ros_msgs::EntitySpan*)realloc(this->spans, spans_lengthT * sizeof(strawberry_ros_msgs::EntitySpan));
      spans_length = spans_lengthT;
      for( uint32_t i = 0; i < spans_length; i++){
      offset += this->st_spans.deserialize(inbuffer + offset);
        memcpy( &(this->spans[i]), &(this->st_spans), sizeof(strawberry_ros_msgs::EntitySpan));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/EntityResult"; };
    virtual const char * getMD5() override { return "a80d8f081129a560b83c9b463e5e0c77"; };

  };

}
#endif
