#ifndef _ROS_haru_encouraging_mediator_msgs_KanjiWriteResult_h
#define _ROS_haru_encouraging_mediator_msgs_KanjiWriteResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"

namespace haru_encouraging_mediator_msgs
{

  class KanjiWriteResult : public ros::Msg
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
      uint32_t kanjis_length;
      typedef sensor_msgs::Image _kanjis_type;
      _kanjis_type st_kanjis;
      _kanjis_type * kanjis;
      uint32_t kanjis_path_length;
      typedef std_msgs::String _kanjis_path_type;
      _kanjis_path_type st_kanjis_path;
      _kanjis_path_type * kanjis_path;

    KanjiWriteResult():
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr),
      user_names_length(0), st_user_names(), user_names(nullptr),
      kanjis_length(0), st_kanjis(), kanjis(nullptr),
      kanjis_path_length(0), st_kanjis_path(), kanjis_path(nullptr)
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
      *(outbuffer + offset + 0) = (this->kanjis_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kanjis_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->kanjis_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->kanjis_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kanjis_length);
      for( uint32_t i = 0; i < kanjis_length; i++){
      offset += this->kanjis[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->kanjis_path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kanjis_path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->kanjis_path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->kanjis_path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kanjis_path_length);
      for( uint32_t i = 0; i < kanjis_path_length; i++){
      offset += this->kanjis_path[i].serialize(outbuffer + offset);
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
      uint32_t kanjis_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      kanjis_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      kanjis_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      kanjis_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->kanjis_length);
      if(kanjis_lengthT > kanjis_length)
        this->kanjis = (sensor_msgs::Image*)realloc(this->kanjis, kanjis_lengthT * sizeof(sensor_msgs::Image));
      kanjis_length = kanjis_lengthT;
      for( uint32_t i = 0; i < kanjis_length; i++){
      offset += this->st_kanjis.deserialize(inbuffer + offset);
        memcpy( &(this->kanjis[i]), &(this->st_kanjis), sizeof(sensor_msgs::Image));
      }
      uint32_t kanjis_path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      kanjis_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      kanjis_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      kanjis_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->kanjis_path_length);
      if(kanjis_path_lengthT > kanjis_path_length)
        this->kanjis_path = (std_msgs::String*)realloc(this->kanjis_path, kanjis_path_lengthT * sizeof(std_msgs::String));
      kanjis_path_length = kanjis_path_lengthT;
      for( uint32_t i = 0; i < kanjis_path_length; i++){
      offset += this->st_kanjis_path.deserialize(inbuffer + offset);
        memcpy( &(this->kanjis_path[i]), &(this->st_kanjis_path), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/KanjiWriteResult"; };
    virtual const char * getMD5() override { return "0e24c0977b86826db2fb607f8b9e5dcc"; };

  };

}
#endif
