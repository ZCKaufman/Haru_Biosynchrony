#ifndef _ROS_SERVICE_SetLanguage_h
#define _ROS_SERVICE_SetLanguage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETLANGUAGE[] = "idmind_tabletop_msgs/SetLanguage";

  class SetLanguageRequest : public ros::Msg
  {
    public:
      typedef const char* _language_type;
      _language_type language;

    SetLanguageRequest():
      language("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_language = strlen(this->language);
      varToArr(outbuffer + offset, length_language);
      offset += 4;
      memcpy(outbuffer + offset, this->language, length_language);
      offset += length_language;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_language;
      arrToVar(length_language, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language-1]=0;
      this->language = (char *)(inbuffer + offset-1);
      offset += length_language;
     return offset;
    }

    virtual const char * getType() override { return SETLANGUAGE; };
    virtual const char * getMD5() override { return "f9264c5bffd188939e827e658af68a0d"; };

  };

  class SetLanguageResponse : public ros::Msg
  {
    public:

    SetLanguageResponse()
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

    virtual const char * getType() override { return SETLANGUAGE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetLanguage {
    public:
    typedef SetLanguageRequest Request;
    typedef SetLanguageResponse Response;
  };

}
#endif
