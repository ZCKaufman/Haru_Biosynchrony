#ifndef _ROS_haru_encouraging_mediator_msgs_RequestImageResult_h
#define _ROS_haru_encouraging_mediator_msgs_RequestImageResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"

namespace haru_encouraging_mediator_msgs
{

  class RequestImageResult : public ros::Msg
  {
    public:
      uint32_t ipad_ids_length;
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type st_ipad_ids;
      _ipad_ids_type * ipad_ids;
      uint32_t user_names_length;
      typedef std_msgs::String _user_names_type;
      _user_names_type st_user_names;
      _user_names_type * user_names;
      uint32_t images_length;
      typedef sensor_msgs::Image _images_type;
      _images_type st_images;
      _images_type * images;
      uint32_t tags_length;
      typedef std_msgs::String _tags_type;
      _tags_type st_tags;
      _tags_type * tags;
      uint32_t images_path_length;
      typedef std_msgs::String _images_path_type;
      _images_path_type st_images_path;
      _images_path_type * images_path;

    RequestImageResult():
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr),
      user_names_length(0), st_user_names(), user_names(nullptr),
      images_length(0), st_images(), images(nullptr),
      tags_length(0), st_tags(), tags(nullptr),
      images_path_length(0), st_images_path(), images_path(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ipad_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ipad_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ipad_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ipad_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ipad_ids_length);
      for( uint32_t i = 0; i < ipad_ids_length; i++){
      offset += this->ipad_ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->user_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_names_length);
      for( uint32_t i = 0; i < user_names_length; i++){
      offset += this->user_names[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->images_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->images_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->images_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->images_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->images_length);
      for( uint32_t i = 0; i < images_length; i++){
      offset += this->images[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_length);
      for( uint32_t i = 0; i < tags_length; i++){
      offset += this->tags[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->images_path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->images_path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->images_path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->images_path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->images_path_length);
      for( uint32_t i = 0; i < images_path_length; i++){
      offset += this->images_path[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t ipad_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ipad_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ipad_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ipad_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ipad_ids_length);
      if(ipad_ids_lengthT > ipad_ids_length)
        this->ipad_ids = (std_msgs::String*)realloc(this->ipad_ids, ipad_ids_lengthT * sizeof(std_msgs::String));
      ipad_ids_length = ipad_ids_lengthT;
      for( uint32_t i = 0; i < ipad_ids_length; i++){
      offset += this->st_ipad_ids.deserialize(inbuffer + offset);
        memcpy( &(this->ipad_ids[i]), &(this->st_ipad_ids), sizeof(std_msgs::String));
      }
      uint32_t user_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      user_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      user_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      user_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->user_names_length);
      if(user_names_lengthT > user_names_length)
        this->user_names = (std_msgs::String*)realloc(this->user_names, user_names_lengthT * sizeof(std_msgs::String));
      user_names_length = user_names_lengthT;
      for( uint32_t i = 0; i < user_names_length; i++){
      offset += this->st_user_names.deserialize(inbuffer + offset);
        memcpy( &(this->user_names[i]), &(this->st_user_names), sizeof(std_msgs::String));
      }
      uint32_t images_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      images_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      images_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      images_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->images_length);
      if(images_lengthT > images_length)
        this->images = (sensor_msgs::Image*)realloc(this->images, images_lengthT * sizeof(sensor_msgs::Image));
      images_length = images_lengthT;
      for( uint32_t i = 0; i < images_length; i++){
      offset += this->st_images.deserialize(inbuffer + offset);
        memcpy( &(this->images[i]), &(this->st_images), sizeof(sensor_msgs::Image));
      }
      uint32_t tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_length);
      if(tags_lengthT > tags_length)
        this->tags = (std_msgs::String*)realloc(this->tags, tags_lengthT * sizeof(std_msgs::String));
      tags_length = tags_lengthT;
      for( uint32_t i = 0; i < tags_length; i++){
      offset += this->st_tags.deserialize(inbuffer + offset);
        memcpy( &(this->tags[i]), &(this->st_tags), sizeof(std_msgs::String));
      }
      uint32_t images_path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      images_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      images_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      images_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->images_path_length);
      if(images_path_lengthT > images_path_length)
        this->images_path = (std_msgs::String*)realloc(this->images_path, images_path_lengthT * sizeof(std_msgs::String));
      images_path_length = images_path_lengthT;
      for( uint32_t i = 0; i < images_path_length; i++){
      offset += this->st_images_path.deserialize(inbuffer + offset);
        memcpy( &(this->images_path[i]), &(this->st_images_path), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/RequestImageResult"; };
    virtual const char * getMD5() override { return "5cc30448d485af3584c06250382fb57c"; };

  };

}
#endif
