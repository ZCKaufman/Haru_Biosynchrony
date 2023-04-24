#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetProfiles_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetProfiles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetProfiles : public ros::Msg
  {
    public:
      uint32_t user_names_length;
      typedef std_msgs::String _user_names_type;
      _user_names_type st_user_names;
      _user_names_type * user_names;
      uint32_t avatar_paths_length;
      typedef std_msgs::String _avatar_paths_type;
      _avatar_paths_type st_avatar_paths;
      _avatar_paths_type * avatar_paths;
      uint32_t avatar_imgs_length;
      typedef sensor_msgs::Image _avatar_imgs_type;
      _avatar_imgs_type st_avatar_imgs;
      _avatar_imgs_type * avatar_imgs;
      uint32_t ipad_ids_length;
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type st_ipad_ids;
      _ipad_ids_type * ipad_ids;

    UnityProjectorSetProfiles():
      user_names_length(0), st_user_names(), user_names(nullptr),
      avatar_paths_length(0), st_avatar_paths(), avatar_paths(nullptr),
      avatar_imgs_length(0), st_avatar_imgs(), avatar_imgs(nullptr),
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->user_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_names_length);
      for( uint32_t i = 0; i < user_names_length; i++){
      offset += this->user_names[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->avatar_paths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->avatar_paths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->avatar_paths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->avatar_paths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->avatar_paths_length);
      for( uint32_t i = 0; i < avatar_paths_length; i++){
      offset += this->avatar_paths[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->avatar_imgs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->avatar_imgs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->avatar_imgs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->avatar_imgs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->avatar_imgs_length);
      for( uint32_t i = 0; i < avatar_imgs_length; i++){
      offset += this->avatar_imgs[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->ipad_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ipad_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ipad_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ipad_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ipad_ids_length);
      for( uint32_t i = 0; i < ipad_ids_length; i++){
      offset += this->ipad_ids[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      uint32_t avatar_paths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      avatar_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      avatar_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      avatar_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->avatar_paths_length);
      if(avatar_paths_lengthT > avatar_paths_length)
        this->avatar_paths = (std_msgs::String*)realloc(this->avatar_paths, avatar_paths_lengthT * sizeof(std_msgs::String));
      avatar_paths_length = avatar_paths_lengthT;
      for( uint32_t i = 0; i < avatar_paths_length; i++){
      offset += this->st_avatar_paths.deserialize(inbuffer + offset);
        memcpy( &(this->avatar_paths[i]), &(this->st_avatar_paths), sizeof(std_msgs::String));
      }
      uint32_t avatar_imgs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      avatar_imgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      avatar_imgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      avatar_imgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->avatar_imgs_length);
      if(avatar_imgs_lengthT > avatar_imgs_length)
        this->avatar_imgs = (sensor_msgs::Image*)realloc(this->avatar_imgs, avatar_imgs_lengthT * sizeof(sensor_msgs::Image));
      avatar_imgs_length = avatar_imgs_lengthT;
      for( uint32_t i = 0; i < avatar_imgs_length; i++){
      offset += this->st_avatar_imgs.deserialize(inbuffer + offset);
        memcpy( &(this->avatar_imgs[i]), &(this->st_avatar_imgs), sizeof(sensor_msgs::Image));
      }
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
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetProfiles"; };
    virtual const char * getMD5() override { return "2fb29b719f23ec875cbd26ee5912b14a"; };

  };

}
#endif
