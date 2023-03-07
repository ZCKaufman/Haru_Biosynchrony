#ifndef _ROS_SERVICE_TelegramCheckUserByID_h
#define _ROS_SERVICE_TelegramCheckUserByID_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMCHECKUSERBYID[] = "idmind_tabletop_msgs/TelegramCheckUserByID";

  class TelegramCheckUserByIDRequest : public ros::Msg
  {
    public:
      typedef uint64_t _user_id_type;
      _user_id_type user_id;

    TelegramCheckUserByIDRequest():
      user_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->user_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_id >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->user_id >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->user_id >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->user_id >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->user_id >> (8 * 7)) & 0xFF;
      offset += sizeof(this->user_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->user_id =  ((uint64_t) (*(inbuffer + offset)));
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->user_id |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->user_id);
     return offset;
    }

    virtual const char * getType() override { return TELEGRAMCHECKUSERBYID; };
    virtual const char * getMD5() override { return "fc5586579d39faabca72add097f97c10"; };

  };

  class TelegramCheckUserByIDResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TelegramCheckUserByIDResponse():
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

    virtual const char * getType() override { return TELEGRAMCHECKUSERBYID; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TelegramCheckUserByID {
    public:
    typedef TelegramCheckUserByIDRequest Request;
    typedef TelegramCheckUserByIDResponse Response;
  };

}
#endif
