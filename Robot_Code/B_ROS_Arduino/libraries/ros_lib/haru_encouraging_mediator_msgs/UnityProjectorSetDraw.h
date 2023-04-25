#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetDraw_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetDraw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetDraw : public ros::Msg
  {
    public:
      uint32_t ipad_ids_length;
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type st_ipad_ids;
      _ipad_ids_type * ipad_ids;
      uint32_t draw_paths_length;
      typedef std_msgs::String _draw_paths_type;
      _draw_paths_type st_draw_paths;
      _draw_paths_type * draw_paths;
      uint32_t draw_imgs_length;
      typedef sensor_msgs::Image _draw_imgs_type;
      _draw_imgs_type st_draw_imgs;
      _draw_imgs_type * draw_imgs;
      uint32_t draw_tags_length;
      typedef std_msgs::String _draw_tags_type;
      _draw_tags_type st_draw_tags;
      _draw_tags_type * draw_tags;

    UnityProjectorSetDraw():
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr),
      draw_paths_length(0), st_draw_paths(), draw_paths(nullptr),
      draw_imgs_length(0), st_draw_imgs(), draw_imgs(nullptr),
      draw_tags_length(0), st_draw_tags(), draw_tags(nullptr)
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
      *(outbuffer + offset + 0) = (this->draw_paths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->draw_paths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->draw_paths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->draw_paths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->draw_paths_length);
      for( uint32_t i = 0; i < draw_paths_length; i++){
      offset += this->draw_paths[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->draw_imgs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->draw_imgs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->draw_imgs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->draw_imgs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->draw_imgs_length);
      for( uint32_t i = 0; i < draw_imgs_length; i++){
      offset += this->draw_imgs[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->draw_tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->draw_tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->draw_tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->draw_tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->draw_tags_length);
      for( uint32_t i = 0; i < draw_tags_length; i++){
      offset += this->draw_tags[i].serialize(outbuffer + offset);
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
      uint32_t draw_paths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      draw_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      draw_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      draw_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->draw_paths_length);
      if(draw_paths_lengthT > draw_paths_length)
        this->draw_paths = (std_msgs::String*)realloc(this->draw_paths, draw_paths_lengthT * sizeof(std_msgs::String));
      draw_paths_length = draw_paths_lengthT;
      for( uint32_t i = 0; i < draw_paths_length; i++){
      offset += this->st_draw_paths.deserialize(inbuffer + offset);
        memcpy( &(this->draw_paths[i]), &(this->st_draw_paths), sizeof(std_msgs::String));
      }
      uint32_t draw_imgs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      draw_imgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      draw_imgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      draw_imgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->draw_imgs_length);
      if(draw_imgs_lengthT > draw_imgs_length)
        this->draw_imgs = (sensor_msgs::Image*)realloc(this->draw_imgs, draw_imgs_lengthT * sizeof(sensor_msgs::Image));
      draw_imgs_length = draw_imgs_lengthT;
      for( uint32_t i = 0; i < draw_imgs_length; i++){
      offset += this->st_draw_imgs.deserialize(inbuffer + offset);
        memcpy( &(this->draw_imgs[i]), &(this->st_draw_imgs), sizeof(sensor_msgs::Image));
      }
      uint32_t draw_tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      draw_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      draw_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      draw_tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->draw_tags_length);
      if(draw_tags_lengthT > draw_tags_length)
        this->draw_tags = (std_msgs::String*)realloc(this->draw_tags, draw_tags_lengthT * sizeof(std_msgs::String));
      draw_tags_length = draw_tags_lengthT;
      for( uint32_t i = 0; i < draw_tags_length; i++){
      offset += this->st_draw_tags.deserialize(inbuffer + offset);
        memcpy( &(this->draw_tags[i]), &(this->st_draw_tags), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetDraw"; };
    virtual const char * getMD5() override { return "543c594eaac86fe29b4aae22e1831a7a"; };

  };

}
#endif
