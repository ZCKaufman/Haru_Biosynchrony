#ifndef _ROS_SERVICE_ShowProfilePage_h
#define _ROS_SERVICE_ShowProfilePage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SHOWPROFILEPAGE[] = "idmind_tabletop_msgs/ShowProfilePage";

  class ShowProfilePageRequest : public ros::Msg
  {
    public:
      typedef const char* _image_location_type;
      _image_location_type image_location;
      typedef const char* _guest_name_type;
      _guest_name_type guest_name;
      typedef const char* _position_type;
      _position_type position;
      typedef const char* _company_type;
      _company_type company;

    ShowProfilePageRequest():
      image_location(""),
      guest_name(""),
      position(""),
      company("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_image_location = strlen(this->image_location);
      varToArr(outbuffer + offset, length_image_location);
      offset += 4;
      memcpy(outbuffer + offset, this->image_location, length_image_location);
      offset += length_image_location;
      uint32_t length_guest_name = strlen(this->guest_name);
      varToArr(outbuffer + offset, length_guest_name);
      offset += 4;
      memcpy(outbuffer + offset, this->guest_name, length_guest_name);
      offset += length_guest_name;
      uint32_t length_position = strlen(this->position);
      varToArr(outbuffer + offset, length_position);
      offset += 4;
      memcpy(outbuffer + offset, this->position, length_position);
      offset += length_position;
      uint32_t length_company = strlen(this->company);
      varToArr(outbuffer + offset, length_company);
      offset += 4;
      memcpy(outbuffer + offset, this->company, length_company);
      offset += length_company;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_image_location;
      arrToVar(length_image_location, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_image_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_image_location-1]=0;
      this->image_location = (char *)(inbuffer + offset-1);
      offset += length_image_location;
      uint32_t length_guest_name;
      arrToVar(length_guest_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_guest_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_guest_name-1]=0;
      this->guest_name = (char *)(inbuffer + offset-1);
      offset += length_guest_name;
      uint32_t length_position;
      arrToVar(length_position, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_position; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_position-1]=0;
      this->position = (char *)(inbuffer + offset-1);
      offset += length_position;
      uint32_t length_company;
      arrToVar(length_company, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_company; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_company-1]=0;
      this->company = (char *)(inbuffer + offset-1);
      offset += length_company;
     return offset;
    }

    virtual const char * getType() override { return SHOWPROFILEPAGE; };
    virtual const char * getMD5() override { return "563fb8d64c6eedd6d20f692a87ee29f7"; };

  };

  class ShowProfilePageResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _website_url_type;
      _website_url_type website_url;

    ShowProfilePageResponse():
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

    virtual const char * getType() override { return SHOWPROFILEPAGE; };
    virtual const char * getMD5() override { return "b8d05eda8d87801f080b0332298ab644"; };

  };

  class ShowProfilePage {
    public:
    typedef ShowProfilePageRequest Request;
    typedef ShowProfilePageResponse Response;
  };

}
#endif
