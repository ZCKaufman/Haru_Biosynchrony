#ifndef _ROS_SERVICE_TelegramMarkAsRead_h
#define _ROS_SERVICE_TelegramMarkAsRead_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMMARKASREAD[] = "idmind_tabletop_msgs/TelegramMarkAsRead";

  class TelegramMarkAsReadRequest : public ros::Msg
  {
    public:
      typedef int64_t _msg_id_type;
      _msg_id_type msg_id;

    TelegramMarkAsReadRequest():
      msg_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_msg_id;
      u_msg_id.real = this->msg_id;
      *(outbuffer + offset + 0) = (u_msg_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_msg_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_msg_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_msg_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_msg_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_msg_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_msg_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_msg_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->msg_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_msg_id;
      u_msg_id.base = 0;
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_msg_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->msg_id = u_msg_id.real;
      offset += sizeof(this->msg_id);
     return offset;
    }

    virtual const char * getType() override { return TELEGRAMMARKASREAD; };
    virtual const char * getMD5() override { return "4a67027f0b866226dd664c3ac3f82ba9"; };

  };

  class TelegramMarkAsReadResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TelegramMarkAsReadResponse():
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

    virtual const char * getType() override { return TELEGRAMMARKASREAD; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TelegramMarkAsRead {
    public:
    typedef TelegramMarkAsReadRequest Request;
    typedef TelegramMarkAsReadResponse Response;
  };

}
#endif
