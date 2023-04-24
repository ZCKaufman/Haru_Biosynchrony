#ifndef _ROS_strawberry_ros_msgs_NewsArticle_h
#define _ROS_strawberry_ros_msgs_NewsArticle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/CompressedImage.h"

namespace strawberry_ros_msgs
{

  class NewsArticle : public ros::Msg
  {
    public:
      typedef const char* _title_type;
      _title_type title;
      typedef sensor_msgs::CompressedImage _image_type;
      _image_type image;
      typedef const char* _summary_type;
      _summary_type summary;
      typedef const char* _publication_date_type;
      _publication_date_type publication_date;
      typedef const char* _link_type;
      _link_type link;

    NewsArticle():
      title(""),
      image(),
      summary(""),
      publication_date(""),
      link("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_title = strlen(this->title);
      varToArr(outbuffer + offset, length_title);
      offset += 4;
      memcpy(outbuffer + offset, this->title, length_title);
      offset += length_title;
      offset += this->image.serialize(outbuffer + offset);
      uint32_t length_summary = strlen(this->summary);
      varToArr(outbuffer + offset, length_summary);
      offset += 4;
      memcpy(outbuffer + offset, this->summary, length_summary);
      offset += length_summary;
      uint32_t length_publication_date = strlen(this->publication_date);
      varToArr(outbuffer + offset, length_publication_date);
      offset += 4;
      memcpy(outbuffer + offset, this->publication_date, length_publication_date);
      offset += length_publication_date;
      uint32_t length_link = strlen(this->link);
      varToArr(outbuffer + offset, length_link);
      offset += 4;
      memcpy(outbuffer + offset, this->link, length_link);
      offset += length_link;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_title;
      arrToVar(length_title, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
      offset += this->image.deserialize(inbuffer + offset);
      uint32_t length_summary;
      arrToVar(length_summary, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_summary; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_summary-1]=0;
      this->summary = (char *)(inbuffer + offset-1);
      offset += length_summary;
      uint32_t length_publication_date;
      arrToVar(length_publication_date, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_publication_date; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_publication_date-1]=0;
      this->publication_date = (char *)(inbuffer + offset-1);
      offset += length_publication_date;
      uint32_t length_link;
      arrToVar(length_link, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link-1]=0;
      this->link = (char *)(inbuffer + offset-1);
      offset += length_link;
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/NewsArticle"; };
    virtual const char * getMD5() override { return "1a5290efbc846215e39d8a6735d08a1b"; };

  };

}
#endif
