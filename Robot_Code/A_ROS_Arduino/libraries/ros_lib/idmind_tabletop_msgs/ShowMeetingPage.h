#ifndef _ROS_SERVICE_ShowMeetingPage_h
#define _ROS_SERVICE_ShowMeetingPage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SHOWMEETINGPAGE[] = "idmind_tabletop_msgs/ShowMeetingPage";

  class ShowMeetingPageRequest : public ros::Msg
  {
    public:
      typedef const char* _meeting_name_type;
      _meeting_name_type meeting_name;
      typedef const char* _visitor_name_type;
      _visitor_name_type visitor_name;
      typedef const char* _hosts_type;
      _hosts_type hosts;
      typedef const char* _meeting_start_type;
      _meeting_start_type meeting_start;
      typedef const char* _meeting_end_type;
      _meeting_end_type meeting_end;
      typedef const char* _room_type;
      _room_type room;

    ShowMeetingPageRequest():
      meeting_name(""),
      visitor_name(""),
      hosts(""),
      meeting_start(""),
      meeting_end(""),
      room("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_meeting_name = strlen(this->meeting_name);
      varToArr(outbuffer + offset, length_meeting_name);
      offset += 4;
      memcpy(outbuffer + offset, this->meeting_name, length_meeting_name);
      offset += length_meeting_name;
      uint32_t length_visitor_name = strlen(this->visitor_name);
      varToArr(outbuffer + offset, length_visitor_name);
      offset += 4;
      memcpy(outbuffer + offset, this->visitor_name, length_visitor_name);
      offset += length_visitor_name;
      uint32_t length_hosts = strlen(this->hosts);
      varToArr(outbuffer + offset, length_hosts);
      offset += 4;
      memcpy(outbuffer + offset, this->hosts, length_hosts);
      offset += length_hosts;
      uint32_t length_meeting_start = strlen(this->meeting_start);
      varToArr(outbuffer + offset, length_meeting_start);
      offset += 4;
      memcpy(outbuffer + offset, this->meeting_start, length_meeting_start);
      offset += length_meeting_start;
      uint32_t length_meeting_end = strlen(this->meeting_end);
      varToArr(outbuffer + offset, length_meeting_end);
      offset += 4;
      memcpy(outbuffer + offset, this->meeting_end, length_meeting_end);
      offset += length_meeting_end;
      uint32_t length_room = strlen(this->room);
      varToArr(outbuffer + offset, length_room);
      offset += 4;
      memcpy(outbuffer + offset, this->room, length_room);
      offset += length_room;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_meeting_name;
      arrToVar(length_meeting_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_meeting_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_meeting_name-1]=0;
      this->meeting_name = (char *)(inbuffer + offset-1);
      offset += length_meeting_name;
      uint32_t length_visitor_name;
      arrToVar(length_visitor_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_visitor_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_visitor_name-1]=0;
      this->visitor_name = (char *)(inbuffer + offset-1);
      offset += length_visitor_name;
      uint32_t length_hosts;
      arrToVar(length_hosts, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hosts; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hosts-1]=0;
      this->hosts = (char *)(inbuffer + offset-1);
      offset += length_hosts;
      uint32_t length_meeting_start;
      arrToVar(length_meeting_start, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_meeting_start; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_meeting_start-1]=0;
      this->meeting_start = (char *)(inbuffer + offset-1);
      offset += length_meeting_start;
      uint32_t length_meeting_end;
      arrToVar(length_meeting_end, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_meeting_end; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_meeting_end-1]=0;
      this->meeting_end = (char *)(inbuffer + offset-1);
      offset += length_meeting_end;
      uint32_t length_room;
      arrToVar(length_room, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_room; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_room-1]=0;
      this->room = (char *)(inbuffer + offset-1);
      offset += length_room;
     return offset;
    }

    virtual const char * getType() override { return SHOWMEETINGPAGE; };
    virtual const char * getMD5() override { return "508dcd2b971476c90eae2edba9f7e531"; };

  };

  class ShowMeetingPageResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _website_url_type;
      _website_url_type website_url;

    ShowMeetingPageResponse():
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

    virtual const char * getType() override { return SHOWMEETINGPAGE; };
    virtual const char * getMD5() override { return "b8d05eda8d87801f080b0332298ab644"; };

  };

  class ShowMeetingPage {
    public:
    typedef ShowMeetingPageRequest Request;
    typedef ShowMeetingPageResponse Response;
  };

}
#endif
