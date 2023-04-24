#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorShowChat_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorShowChat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorShowChat : public ros::Msg
  {
    public:
      typedef bool _show_chat_type;
      _show_chat_type show_chat;
      typedef float _message_delay_type;
      _message_delay_type message_delay;
      typedef int32_t _show_mode_type;
      _show_mode_type show_mode;

    UnityProjectorShowChat():
      show_chat(0),
      message_delay(0),
      show_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show_chat;
      u_show_chat.real = this->show_chat;
      *(outbuffer + offset + 0) = (u_show_chat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show_chat);
      union {
        float real;
        uint32_t base;
      } u_message_delay;
      u_message_delay.real = this->message_delay;
      *(outbuffer + offset + 0) = (u_message_delay.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_message_delay.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_message_delay.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_message_delay.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->message_delay);
      union {
        int32_t real;
        uint32_t base;
      } u_show_mode;
      u_show_mode.real = this->show_mode;
      *(outbuffer + offset + 0) = (u_show_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_show_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_show_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_show_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->show_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_show_chat;
      u_show_chat.base = 0;
      u_show_chat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show_chat = u_show_chat.real;
      offset += sizeof(this->show_chat);
      union {
        float real;
        uint32_t base;
      } u_message_delay;
      u_message_delay.base = 0;
      u_message_delay.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_message_delay.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_message_delay.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_message_delay.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->message_delay = u_message_delay.real;
      offset += sizeof(this->message_delay);
      union {
        int32_t real;
        uint32_t base;
      } u_show_mode;
      u_show_mode.base = 0;
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->show_mode = u_show_mode.real;
      offset += sizeof(this->show_mode);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorShowChat"; };
    virtual const char * getMD5() override { return "d752223f9b09753322840606d3ccf06f"; };

  };

}
#endif
