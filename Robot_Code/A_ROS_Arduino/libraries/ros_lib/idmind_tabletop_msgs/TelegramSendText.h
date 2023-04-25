#ifndef _ROS_SERVICE_TelegramSendText_h
#define _ROS_SERVICE_TelegramSendText_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMSENDTEXT[] = "idmind_tabletop_msgs/TelegramSendText";

  class TelegramSendTextRequest : public ros::Msg
  {
    public:
      typedef const char* _text_type;
      _text_type text;
      typedef int64_t _chat_id_type;
      _chat_id_type chat_id;

    TelegramSendTextRequest():
      text(""),
      chat_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
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
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
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

    virtual const char * getType() override { return TELEGRAMSENDTEXT; };
    virtual const char * getMD5() override { return "16d26b8a174a2290149052cc448ddedc"; };

  };

  class TelegramSendTextResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TelegramSendTextResponse():
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

    virtual const char * getType() override { return TELEGRAMSENDTEXT; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TelegramSendText {
    public:
    typedef TelegramSendTextRequest Request;
    typedef TelegramSendTextResponse Response;
  };

}
#endif
