#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetConversationApp_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetConversationApp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetConversationApp : public ros::Msg
  {
    public:
      typedef bool _activate_url_type;
      _activate_url_type activate_url;
      typedef const char* _url_type;
      _url_type url;
      typedef const char* _app_name_type;
      _app_name_type app_name;

    UnityProjectorSetConversationApp():
      activate_url(0),
      url(""),
      app_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_url;
      u_activate_url.real = this->activate_url;
      *(outbuffer + offset + 0) = (u_activate_url.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->activate_url);
      uint32_t length_url = strlen(this->url);
      varToArr(outbuffer + offset, length_url);
      offset += 4;
      memcpy(outbuffer + offset, this->url, length_url);
      offset += length_url;
      uint32_t length_app_name = strlen(this->app_name);
      varToArr(outbuffer + offset, length_app_name);
      offset += 4;
      memcpy(outbuffer + offset, this->app_name, length_app_name);
      offset += length_app_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_url;
      u_activate_url.base = 0;
      u_activate_url.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->activate_url = u_activate_url.real;
      offset += sizeof(this->activate_url);
      uint32_t length_url;
      arrToVar(length_url, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_url; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_url-1]=0;
      this->url = (char *)(inbuffer + offset-1);
      offset += length_url;
      uint32_t length_app_name;
      arrToVar(length_app_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_app_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_app_name-1]=0;
      this->app_name = (char *)(inbuffer + offset-1);
      offset += length_app_name;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetConversationApp"; };
    virtual const char * getMD5() override { return "6f4ddc2e97487d1881304e6796b6e352"; };

  };

}
#endif
