#ifndef _ROS_idmind_tabletop_msgs_TTSVoiceInfo_h
#define _ROS_idmind_tabletop_msgs_TTSVoiceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TTSVoiceInfo : public ros::Msg
  {
    public:
      typedef const char* _language_code_type;
      _language_code_type language_code;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _sex_type;
      _sex_type sex;
      typedef const char* _country_type;
      _country_type country;
      typedef const char* _region_type;
      _region_type region;

    TTSVoiceInfo():
      language_code(""),
      name(""),
      sex(""),
      country(""),
      region("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_language_code = strlen(this->language_code);
      varToArr(outbuffer + offset, length_language_code);
      offset += 4;
      memcpy(outbuffer + offset, this->language_code, length_language_code);
      offset += length_language_code;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_sex = strlen(this->sex);
      varToArr(outbuffer + offset, length_sex);
      offset += 4;
      memcpy(outbuffer + offset, this->sex, length_sex);
      offset += length_sex;
      uint32_t length_country = strlen(this->country);
      varToArr(outbuffer + offset, length_country);
      offset += 4;
      memcpy(outbuffer + offset, this->country, length_country);
      offset += length_country;
      uint32_t length_region = strlen(this->region);
      varToArr(outbuffer + offset, length_region);
      offset += 4;
      memcpy(outbuffer + offset, this->region, length_region);
      offset += length_region;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_language_code;
      arrToVar(length_language_code, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language_code-1]=0;
      this->language_code = (char *)(inbuffer + offset-1);
      offset += length_language_code;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_sex;
      arrToVar(length_sex, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sex; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sex-1]=0;
      this->sex = (char *)(inbuffer + offset-1);
      offset += length_sex;
      uint32_t length_country;
      arrToVar(length_country, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_country; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_country-1]=0;
      this->country = (char *)(inbuffer + offset-1);
      offset += length_country;
      uint32_t length_region;
      arrToVar(length_region, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_region; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_region-1]=0;
      this->region = (char *)(inbuffer + offset-1);
      offset += length_region;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSVoiceInfo"; };
    virtual const char * getMD5() override { return "d4f37805c4c3467065b6752790183305"; };

  };

}
#endif
