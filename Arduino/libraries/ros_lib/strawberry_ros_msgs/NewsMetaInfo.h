#ifndef _ROS_SERVICE_NewsMetaInfo_h
#define _ROS_SERVICE_NewsMetaInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char NEWSMETAINFO[] = "strawberry_ros_msgs/NewsMetaInfo";

  class NewsMetaInfoRequest : public ros::Msg
  {
    public:

    NewsMetaInfoRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return NEWSMETAINFO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NewsMetaInfoResponse : public ros::Msg
  {
    public:
      typedef const char* _state_type;
      _state_type state;
      typedef const char* _sources_type;
      _sources_type sources;
      typedef const char* _last_update_time_type;
      _last_update_time_type last_update_time;
      typedef const char* _next_update_time_type;
      _next_update_time_type next_update_time;

    NewsMetaInfoResponse():
      state(""),
      sources(""),
      last_update_time(""),
      next_update_time("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      uint32_t length_sources = strlen(this->sources);
      varToArr(outbuffer + offset, length_sources);
      offset += 4;
      memcpy(outbuffer + offset, this->sources, length_sources);
      offset += length_sources;
      uint32_t length_last_update_time = strlen(this->last_update_time);
      varToArr(outbuffer + offset, length_last_update_time);
      offset += 4;
      memcpy(outbuffer + offset, this->last_update_time, length_last_update_time);
      offset += length_last_update_time;
      uint32_t length_next_update_time = strlen(this->next_update_time);
      varToArr(outbuffer + offset, length_next_update_time);
      offset += 4;
      memcpy(outbuffer + offset, this->next_update_time, length_next_update_time);
      offset += length_next_update_time;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      uint32_t length_sources;
      arrToVar(length_sources, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sources; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sources-1]=0;
      this->sources = (char *)(inbuffer + offset-1);
      offset += length_sources;
      uint32_t length_last_update_time;
      arrToVar(length_last_update_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_last_update_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_last_update_time-1]=0;
      this->last_update_time = (char *)(inbuffer + offset-1);
      offset += length_last_update_time;
      uint32_t length_next_update_time;
      arrToVar(length_next_update_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_next_update_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_next_update_time-1]=0;
      this->next_update_time = (char *)(inbuffer + offset-1);
      offset += length_next_update_time;
     return offset;
    }

    virtual const char * getType() override { return NEWSMETAINFO; };
    virtual const char * getMD5() override { return "b156da530d1568275ad913c8eff6bd84"; };

  };

  class NewsMetaInfo {
    public:
    typedef NewsMetaInfoRequest Request;
    typedef NewsMetaInfoResponse Response;
  };

}
#endif
