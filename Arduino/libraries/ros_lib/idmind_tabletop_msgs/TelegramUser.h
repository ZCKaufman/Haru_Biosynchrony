#ifndef _ROS_idmind_tabletop_msgs_TelegramUser_h
#define _ROS_idmind_tabletop_msgs_TelegramUser_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TelegramUser : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef const char* _username_type;
      _username_type username;
      typedef const char* _firstname_type;
      _firstname_type firstname;
      uint32_t akas_length;
      typedef char* _akas_type;
      _akas_type st_akas;
      _akas_type * akas;

    TelegramUser():
      id(""),
      username(""),
      firstname(""),
      akas_length(0), st_akas(), akas(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_username = strlen(this->username);
      varToArr(outbuffer + offset, length_username);
      offset += 4;
      memcpy(outbuffer + offset, this->username, length_username);
      offset += length_username;
      uint32_t length_firstname = strlen(this->firstname);
      varToArr(outbuffer + offset, length_firstname);
      offset += 4;
      memcpy(outbuffer + offset, this->firstname, length_firstname);
      offset += length_firstname;
      *(outbuffer + offset + 0) = (this->akas_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->akas_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->akas_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->akas_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->akas_length);
      for( uint32_t i = 0; i < akas_length; i++){
      uint32_t length_akasi = strlen(this->akas[i]);
      varToArr(outbuffer + offset, length_akasi);
      offset += 4;
      memcpy(outbuffer + offset, this->akas[i], length_akasi);
      offset += length_akasi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_username;
      arrToVar(length_username, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_username; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_username-1]=0;
      this->username = (char *)(inbuffer + offset-1);
      offset += length_username;
      uint32_t length_firstname;
      arrToVar(length_firstname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firstname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firstname-1]=0;
      this->firstname = (char *)(inbuffer + offset-1);
      offset += length_firstname;
      uint32_t akas_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      akas_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      akas_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      akas_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->akas_length);
      if(akas_lengthT > akas_length)
        this->akas = (char**)realloc(this->akas, akas_lengthT * sizeof(char*));
      akas_length = akas_lengthT;
      for( uint32_t i = 0; i < akas_length; i++){
      uint32_t length_st_akas;
      arrToVar(length_st_akas, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_akas; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_akas-1]=0;
      this->st_akas = (char *)(inbuffer + offset-1);
      offset += length_st_akas;
        memcpy( &(this->akas[i]), &(this->st_akas), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TelegramUser"; };
    virtual const char * getMD5() override { return "5cdd03ddd97d7e5b3d83421f91068426"; };

  };

}
#endif
