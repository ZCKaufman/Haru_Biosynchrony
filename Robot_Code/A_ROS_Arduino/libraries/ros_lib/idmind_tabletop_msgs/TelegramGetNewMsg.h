#ifndef _ROS_SERVICE_TelegramGetNewMsg_h
#define _ROS_SERVICE_TelegramGetNewMsg_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/TelegramMsg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMGETNEWMSG[] = "idmind_tabletop_msgs/TelegramGetNewMsg";

  class TelegramGetNewMsgRequest : public ros::Msg
  {
    public:

    TelegramGetNewMsgRequest()
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

    virtual const char * getType() override { return TELEGRAMGETNEWMSG; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TelegramGetNewMsgResponse : public ros::Msg
  {
    public:
      typedef int64_t _total_msgs_num_type;
      _total_msgs_num_type total_msgs_num;
      typedef int64_t _unread_msgs_num_type;
      _unread_msgs_num_type unread_msgs_num;
      typedef idmind_tabletop_msgs::TelegramMsg _msg_type;
      _msg_type msg;

    TelegramGetNewMsgResponse():
      total_msgs_num(0),
      unread_msgs_num(0),
      msg()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_total_msgs_num;
      u_total_msgs_num.real = this->total_msgs_num;
      *(outbuffer + offset + 0) = (u_total_msgs_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_msgs_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_msgs_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_msgs_num.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_total_msgs_num.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_total_msgs_num.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_total_msgs_num.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_total_msgs_num.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->total_msgs_num);
      union {
        int64_t real;
        uint64_t base;
      } u_unread_msgs_num;
      u_unread_msgs_num.real = this->unread_msgs_num;
      *(outbuffer + offset + 0) = (u_unread_msgs_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_unread_msgs_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_unread_msgs_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_unread_msgs_num.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_unread_msgs_num.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_unread_msgs_num.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_unread_msgs_num.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_unread_msgs_num.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->unread_msgs_num);
      offset += this->msg.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_total_msgs_num;
      u_total_msgs_num.base = 0;
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_total_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->total_msgs_num = u_total_msgs_num.real;
      offset += sizeof(this->total_msgs_num);
      union {
        int64_t real;
        uint64_t base;
      } u_unread_msgs_num;
      u_unread_msgs_num.base = 0;
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_unread_msgs_num.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->unread_msgs_num = u_unread_msgs_num.real;
      offset += sizeof(this->unread_msgs_num);
      offset += this->msg.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TELEGRAMGETNEWMSG; };
    virtual const char * getMD5() override { return "256501f3f3441bd680fabd060726c361"; };

  };

  class TelegramGetNewMsg {
    public:
    typedef TelegramGetNewMsgRequest Request;
    typedef TelegramGetNewMsgResponse Response;
  };

}
#endif
