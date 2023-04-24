#ifndef _ROS_SERVICE_ShowGenericPage_h
#define _ROS_SERVICE_ShowGenericPage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SHOWGENERICPAGE[] = "idmind_tabletop_msgs/ShowGenericPage";

  class ShowGenericPageRequest : public ros::Msg
  {
    public:

    ShowGenericPageRequest()
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

    virtual const char * getType() override { return SHOWGENERICPAGE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ShowGenericPageResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _website_url_type;
      _website_url_type website_url;

    ShowGenericPageResponse():
      success(0),
      website_url("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_website_url = strlen(this->website_url);
      varToArr(outbuffer + offset, length_website_url);
      offset += 4;
      memcpy(outbuffer + offset, this->website_url, length_website_url);
      offset += length_website_url;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_website_url;
      arrToVar(length_website_url, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_website_url; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_website_url-1]=0;
      this->website_url = (char *)(inbuffer + offset-1);
      offset += length_website_url;
     return offset;
    }

    virtual const char * getType() override { return SHOWGENERICPAGE; };
    virtual const char * getMD5() override { return "b8d05eda8d87801f080b0332298ab644"; };

  };

  class ShowGenericPage {
    public:
    typedef ShowGenericPageRequest Request;
    typedef ShowGenericPageResponse Response;
  };

}
#endif
