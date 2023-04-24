#ifndef _ROS_SERVICE_TelegramSendAudio_h
#define _ROS_SERVICE_TelegramSendAudio_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMSENDAUDIO[] = "idmind_tabletop_msgs/TelegramSendAudio";

  class TelegramSendAudioRequest : public ros::Msg
  {
    public:
      typedef const char* _file_path_type;
      _file_path_type file_path;
      typedef int64_t _chat_id_type;
      _chat_id_type chat_id;

    TelegramSendAudioRequest():
      file_path(""),
      chat_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
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
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
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

    virtual const char * getType() override { return TELEGRAMSENDAUDIO; };
    virtual const char * getMD5() override { return "a031f3abb7b5284a44651d9d6b91fbe1"; };

  };

  class TelegramSendAudioResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TelegramSendAudioResponse():
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

    virtual const char * getType() override { return TELEGRAMSENDAUDIO; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TelegramSendAudio {
    public:
    typedef TelegramSendAudioRequest Request;
    typedef TelegramSendAudioResponse Response;
  };

}
#endif
