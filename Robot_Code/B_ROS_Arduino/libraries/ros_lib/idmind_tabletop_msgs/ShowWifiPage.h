#ifndef _ROS_SERVICE_ShowWifiPage_h
#define _ROS_SERVICE_ShowWifiPage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SHOWWIFIPAGE[] = "idmind_tabletop_msgs/ShowWifiPage";

  class ShowWifiPageRequest : public ros::Msg
  {
    public:
      typedef const char* _network_type;
      _network_type network;
      typedef const char* _password_type;
      _password_type password;

    ShowWifiPageRequest():
      network(""),
      password("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_network = strlen(this->network);
      varToArr(outbuffer + offset, length_network);
      offset += 4;
      memcpy(outbuffer + offset, this->network, length_network);
      offset += length_network;
      uint32_t length_password = strlen(this->password);
      varToArr(outbuffer + offset, length_password);
      offset += 4;
      memcpy(outbuffer + offset, this->password, length_password);
      offset += length_password;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_network;
      arrToVar(length_network, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_network; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_network-1]=0;
      this->network = (char *)(inbuffer + offset-1);
      offset += length_network;
      uint32_t length_password;
      arrToVar(length_password, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_password; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_password-1]=0;
      this->password = (char *)(inbuffer + offset-1);
      offset += length_password;
     return offset;
    }

    virtual const char * getType() override { return SHOWWIFIPAGE; };
    virtual const char * getMD5() override { return "66cf5738732efe81b5ecb0a6dc7d780e"; };

  };

  class ShowWifiPageResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _website_url_type;
      _website_url_type website_url;

    ShowWifiPageResponse():
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

    virtual const char * getType() override { return SHOWWIFIPAGE; };
    virtual const char * getMD5() override { return "b8d05eda8d87801f080b0332298ab644"; };

  };

  class ShowWifiPage {
    public:
    typedef ShowWifiPageRequest Request;
    typedef ShowWifiPageResponse Response;
  };

}
#endif
