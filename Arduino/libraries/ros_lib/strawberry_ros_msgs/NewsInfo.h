#ifndef _ROS_SERVICE_NewsInfo_h
#define _ROS_SERVICE_NewsInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/NewsArticleArray.h"

namespace strawberry_ros_msgs
{

static const char NEWSINFO[] = "strawberry_ros_msgs/NewsInfo";

  class NewsInfoRequest : public ros::Msg
  {
    public:
      typedef const char* _source_type;
      _source_type source;
      typedef const char* _topic_type;
      _topic_type topic;
      typedef int8_t _max_articles_type;
      _max_articles_type max_articles;

    NewsInfoRequest():
      source(""),
      topic(""),
      max_articles(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_source = strlen(this->source);
      varToArr(outbuffer + offset, length_source);
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      union {
        int8_t real;
        uint8_t base;
      } u_max_articles;
      u_max_articles.real = this->max_articles;
      *(outbuffer + offset + 0) = (u_max_articles.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max_articles);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_source;
      arrToVar(length_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
      union {
        int8_t real;
        uint8_t base;
      } u_max_articles;
      u_max_articles.base = 0;
      u_max_articles.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->max_articles = u_max_articles.real;
      offset += sizeof(this->max_articles);
     return offset;
    }

    virtual const char * getType() override { return NEWSINFO; };
    virtual const char * getMD5() override { return "69f9ca764d954572e435ac497af0874c"; };

  };

  class NewsInfoResponse : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::NewsArticleArray _news_info_type;
      _news_info_type news_info;

    NewsInfoResponse():
      news_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->news_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->news_info.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return NEWSINFO; };
    virtual const char * getMD5() override { return "c89e2decd1dd7b44793bc696a38e61fc"; };

  };

  class NewsInfo {
    public:
    typedef NewsInfoRequest Request;
    typedef NewsInfoResponse Response;
  };

}
#endif
