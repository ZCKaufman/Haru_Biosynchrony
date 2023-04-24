#ifndef _ROS_SERVICE_GetLanguageCode_h
#define _ROS_SERVICE_GetLanguageCode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETLANGUAGECODE[] = "strawberry_ros_msgs/GetLanguageCode";

  class GetLanguageCodeRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    GetLanguageCodeRequest():
      person_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
     return offset;
    }

    virtual const char * getType() override { return GETLANGUAGECODE; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class GetLanguageCodeResponse : public ros::Msg
  {
    public:
      typedef const char* _primary_language_code_type;
      _primary_language_code_type primary_language_code;
      uint32_t alternative_language_codes_length;
      typedef char* _alternative_language_codes_type;
      _alternative_language_codes_type st_alternative_language_codes;
      _alternative_language_codes_type * alternative_language_codes;
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    GetLanguageCodeResponse():
      primary_language_code(""),
      alternative_language_codes_length(0), st_alternative_language_codes(), alternative_language_codes(nullptr),
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_primary_language_code = strlen(this->primary_language_code);
      varToArr(outbuffer + offset, length_primary_language_code);
      offset += 4;
      memcpy(outbuffer + offset, this->primary_language_code, length_primary_language_code);
      offset += length_primary_language_code;
      *(outbuffer + offset + 0) = (this->alternative_language_codes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alternative_language_codes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alternative_language_codes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alternative_language_codes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alternative_language_codes_length);
      for( uint32_t i = 0; i < alternative_language_codes_length; i++){
      uint32_t length_alternative_language_codesi = strlen(this->alternative_language_codes[i]);
      varToArr(outbuffer + offset, length_alternative_language_codesi);
      offset += 4;
      memcpy(outbuffer + offset, this->alternative_language_codes[i], length_alternative_language_codesi);
      offset += length_alternative_language_codesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_primary_language_code;
      arrToVar(length_primary_language_code, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_primary_language_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_primary_language_code-1]=0;
      this->primary_language_code = (char *)(inbuffer + offset-1);
      offset += length_primary_language_code;
      uint32_t alternative_language_codes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      alternative_language_codes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      alternative_language_codes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      alternative_language_codes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->alternative_language_codes_length);
      if(alternative_language_codes_lengthT > alternative_language_codes_length)
        this->alternative_language_codes = (char**)realloc(this->alternative_language_codes, alternative_language_codes_lengthT * sizeof(char*));
      alternative_language_codes_length = alternative_language_codes_lengthT;
      for( uint32_t i = 0; i < alternative_language_codes_length; i++){
      uint32_t length_st_alternative_language_codes;
      arrToVar(length_st_alternative_language_codes, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_alternative_language_codes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_alternative_language_codes-1]=0;
      this->st_alternative_language_codes = (char *)(inbuffer + offset-1);
      offset += length_st_alternative_language_codes;
        memcpy( &(this->alternative_language_codes[i]), &(this->st_alternative_language_codes), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return GETLANGUAGECODE; };
    virtual const char * getMD5() override { return "6e4a29e4813a3bbbeee2b8ef6b9c0132"; };

  };

  class GetLanguageCode {
    public:
    typedef GetLanguageCodeRequest Request;
    typedef GetLanguageCodeResponse Response;
  };

}
#endif
