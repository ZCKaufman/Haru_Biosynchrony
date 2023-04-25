#ifndef _ROS_SERVICE_TelegramSendImage_h
#define _ROS_SERVICE_TelegramSendImage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMSENDIMAGE[] = "idmind_tabletop_msgs/TelegramSendImage";

  class TelegramSendImageRequest : public ros::Msg
  {
    public:
      typedef bool _accepted_type;
      _accepted_type accepted;
      typedef const char* _camera_topic_name_type;
      _camera_topic_name_type camera_topic_name;
      typedef int64_t _chat_id_type;
      _chat_id_type chat_id;

    TelegramSendImageRequest():
      accepted(0),
      camera_topic_name(""),
      chat_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_accepted;
      u_accepted.real = this->accepted;
      *(outbuffer + offset + 0) = (u_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accepted);
      uint32_t length_camera_topic_name = strlen(this->camera_topic_name);
      varToArr(outbuffer + offset, length_camera_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->camera_topic_name, length_camera_topic_name);
      offset += length_camera_topic_name;
      union {
        int64_t real;
        uint64_t base;
      } u_chat_id;
      u_chat_id.real = this->chat_id;
      *(outbuffer + offset + 0) = (u_chat_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_chat_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_chat_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_chat_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_chat_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_chat_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_chat_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_chat_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->chat_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_accepted;
      u_accepted.base = 0;
      u_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->accepted = u_accepted.real;
      offset += sizeof(this->accepted);
      uint32_t length_camera_topic_name;
      arrToVar(length_camera_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_topic_name-1]=0;
      this->camera_topic_name = (char *)(inbuffer + offset-1);
      offset += length_camera_topic_name;
      union {
        int64_t real;
        uint64_t base;
      } u_chat_id;
      u_chat_id.base = 0;
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_chat_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->chat_id = u_chat_id.real;
      offset += sizeof(this->chat_id);
     return offset;
    }

    virtual const char * getType() override { return TELEGRAMSENDIMAGE; };
    virtual const char * getMD5() override { return "f7a228ccf055d3597cae8514d8cb4023"; };

  };

  class TelegramSendImageResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TelegramSendImageResponse():
      success(0)
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
     return offset;
    }

    virtual const char * getType() override { return TELEGRAMSENDIMAGE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TelegramSendImage {
    public:
    typedef TelegramSendImageRequest Request;
    typedef TelegramSendImageResponse Response;
  };

}
#endif
