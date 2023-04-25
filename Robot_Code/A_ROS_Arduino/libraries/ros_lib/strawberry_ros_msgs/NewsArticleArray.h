#ifndef _ROS_strawberry_ros_msgs_NewsArticleArray_h
#define _ROS_strawberry_ros_msgs_NewsArticleArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/NewsArticle.h"

namespace strawberry_ros_msgs
{

  class NewsArticleArray : public ros::Msg
  {
    public:
      uint32_t articles_length;
      typedef strawberry_ros_msgs::NewsArticle _articles_type;
      _articles_type st_articles;
      _articles_type * articles;

    NewsArticleArray():
      articles_length(0), st_articles(), articles(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->articles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->articles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->articles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->articles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->articles_length);
      for( uint32_t i = 0; i < articles_length; i++){
      offset += this->articles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t articles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      articles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      articles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      articles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->articles_length);
      if(articles_lengthT > articles_length)
        this->articles = (strawberry_ros_msgs::NewsArticle*)realloc(this->articles, articles_lengthT * sizeof(strawberry_ros_msgs::NewsArticle));
      articles_length = articles_lengthT;
      for( uint32_t i = 0; i < articles_length; i++){
      offset += this->st_articles.deserialize(inbuffer + offset);
        memcpy( &(this->articles[i]), &(this->st_articles), sizeof(strawberry_ros_msgs::NewsArticle));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/NewsArticleArray"; };
    virtual const char * getMD5() override { return "f6c67ca87204e4faf012936e24010fd7"; };

  };

}
#endif
