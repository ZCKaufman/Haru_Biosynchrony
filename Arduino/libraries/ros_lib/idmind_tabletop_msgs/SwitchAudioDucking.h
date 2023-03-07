#ifndef _ROS_SERVICE_SwitchAudioDucking_h
#define _ROS_SERVICE_SwitchAudioDucking_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SWITCHAUDIODUCKING[] = "idmind_tabletop_msgs/SwitchAudioDucking";

  class SwitchAudioDuckingRequest : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;
      typedef uint32_t _main_channel_id_type;
      _main_channel_id_type main_channel_id;

    SwitchAudioDuckingRequest():
      enable(0),
      main_channel_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      *(outbuffer + offset + 0) = (this->main_channel_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->main_channel_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->main_channel_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->main_channel_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->main_channel_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
      this->main_channel_id =  ((uint32_t) (*(inbuffer + offset)));
      this->main_channel_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->main_channel_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->main_channel_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->main_channel_id);
     return offset;
    }

    virtual const char * getType() override { return SWITCHAUDIODUCKING; };
    virtual const char * getMD5() override { return "f808d32dce6d2d243757ccbc01658229"; };

  };

  class SwitchAudioDuckingResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SwitchAudioDuckingResponse():
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

    virtual const char * getType() override { return SWITCHAUDIODUCKING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SwitchAudioDucking {
    public:
    typedef SwitchAudioDuckingRequest Request;
    typedef SwitchAudioDuckingResponse Response;
  };

}
#endif
