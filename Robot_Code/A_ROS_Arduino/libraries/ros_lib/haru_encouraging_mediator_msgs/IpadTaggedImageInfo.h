#ifndef _ROS_SERVICE_IpadTaggedImageInfo_h
#define _ROS_SERVICE_IpadTaggedImageInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

static const char IPADTAGGEDIMAGEINFO[] = "haru_encouraging_mediator_msgs/IpadTaggedImageInfo";

  class IpadTaggedImageInfoRequest : public ros::Msg
  {
    public:

    IpadTaggedImageInfoRequest()
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

    virtual const char * getType() override { return IPADTAGGEDIMAGEINFO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class IpadTaggedImageInfoResponse : public ros::Msg
  {
    public:
      uint32_t ipad_ids_length;
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type st_ipad_ids;
      _ipad_ids_type * ipad_ids;
      uint32_t image_paths_length;
      typedef std_msgs::String _image_paths_type;
      _image_paths_type st_image_paths;
      _image_paths_type * image_paths;
      uint32_t image_tags_length;
      typedef std_msgs::String _image_tags_type;
      _image_tags_type st_image_tags;
      _image_tags_type * image_tags;

    IpadTaggedImageInfoResponse():
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr),
      image_paths_length(0), st_image_paths(), image_paths(nullptr),
      image_tags_length(0), st_image_tags(), image_tags(nullptr)
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
      *(outbuffer + offset + 0) = (this->image_paths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_paths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_paths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_paths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_paths_length);
      for( uint32_t i = 0; i < image_paths_length; i++){
      offset += this->image_paths[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->image_tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_tags_length);
      for( uint32_t i = 0; i < image_tags_length; i++){
      offset += this->image_tags[i].serialize(outbuffer + offset);
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
      uint32_t image_paths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      image_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      image_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      image_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->image_paths_length);
      if(image_paths_lengthT > image_paths_length)
        this->image_paths = (std_msgs::String*)realloc(this->image_paths, image_paths_lengthT * sizeof(std_msgs::String));
      image_paths_length = image_paths_lengthT;
      for( uint32_t i = 0; i < image_paths_length; i++){
      offset += this->st_image_paths.deserialize(inbuffer + offset);
        memcpy( &(this->image_paths[i]), &(this->st_image_paths), sizeof(std_msgs::String));
      }
      uint32_t image_tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      image_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      image_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      image_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->image_tags_length);
      if(image_tags_lengthT > image_tags_length)
        this->image_tags = (std_msgs::String*)realloc(this->image_tags, image_tags_lengthT * sizeof(std_msgs::String));
      image_tags_length = image_tags_lengthT;
      for( uint32_t i = 0; i < image_tags_length; i++){
      offset += this->st_image_tags.deserialize(inbuffer + offset);
        memcpy( &(this->image_tags[i]), &(this->st_image_tags), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return IPADTAGGEDIMAGEINFO; };
    virtual const char * getMD5() override { return "9c621f0e4575f6137f89cedb733b7c50"; };

  };

  class IpadTaggedImageInfo {
    public:
    typedef IpadTaggedImageInfoRequest Request;
    typedef IpadTaggedImageInfoResponse Response;
  };

}
#endif
