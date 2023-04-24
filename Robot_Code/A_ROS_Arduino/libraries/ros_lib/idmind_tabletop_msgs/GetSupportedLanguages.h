#ifndef _ROS_SERVICE_GetSupportedLanguages_h
#define _ROS_SERVICE_GetSupportedLanguages_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char GETSUPPORTEDLANGUAGES[] = "idmind_tabletop_msgs/GetSupportedLanguages";

  class GetSupportedLanguagesRequest : public ros::Msg
  {
    public:

    GetSupportedLanguagesRequest()
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

    virtual const char * getType() override { return GETSUPPORTEDLANGUAGES; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetSupportedLanguagesResponse : public ros::Msg
  {
    public:
      uint32_t languages_length;
      typedef char* _languages_type;
      _languages_type st_languages;
      _languages_type * languages;

    GetSupportedLanguagesResponse():
      languages_length(0), st_languages(), languages(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->languages_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->languages_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->languages_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->languages_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->languages_length);
      for( uint32_t i = 0; i < languages_length; i++){
      uint32_t length_languagesi = strlen(this->languages[i]);
      varToArr(outbuffer + offset, length_languagesi);
      offset += 4;
      memcpy(outbuffer + offset, this->languages[i], length_languagesi);
      offset += length_languagesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t languages_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      languages_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      languages_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      languages_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->languages_length);
      if(languages_lengthT > languages_length)
        this->languages = (char**)realloc(this->languages, languages_lengthT * sizeof(char*));
      languages_length = languages_lengthT;
      for( uint32_t i = 0; i < languages_length; i++){
      uint32_t length_st_languages;
      arrToVar(length_st_languages, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_languages; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_languages-1]=0;
      this->st_languages = (char *)(inbuffer + offset-1);
      offset += length_st_languages;
        memcpy( &(this->languages[i]), &(this->st_languages), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return GETSUPPORTEDLANGUAGES; };
    virtual const char * getMD5() override { return "67ec5f6090267af044650b7c7c6409d5"; };

  };

  class GetSupportedLanguages {
    public:
    typedef GetSupportedLanguagesRequest Request;
    typedef GetSupportedLanguagesResponse Response;
  };

}
#endif
