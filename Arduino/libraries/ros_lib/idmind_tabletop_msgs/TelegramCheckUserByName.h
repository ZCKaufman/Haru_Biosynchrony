#ifndef _ROS_SERVICE_TelegramCheckUserByName_h
#define _ROS_SERVICE_TelegramCheckUserByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMCHECKUSERBYNAME[] = "idmind_tabletop_msgs/TelegramCheckUserByName";

  class TelegramCheckUserByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _user_name_type;
      _user_name_type user_name;

    TelegramCheckUserByNameRequest():
      user_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_user_name = strlen(this->user_name);
      varToArr(outbuffer + offset, length_user_name);
      offset += 4;
      memcpy(outbuffer + offset, this->user_name, length_user_name);
      offset += length_user_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_user_name;
      arrToVar(length_user_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_name-1]=0;
      this->user_name = (char *)(inbuffer + offset-1);
      offset += length_user_name;
     return offset;
    }

    virtual const char * getType() override { return TELEGRAMCHECKUSERBYNAME; };
    virtual const char * getMD5() override { return "159b36609af19853383ab1313ed185b0"; };

  };

  class TelegramCheckUserByNameResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TelegramCheckUserByNameResponse():
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

    virtual const char * getType() override { return TELEGRAMCHECKUSERBYNAME; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TelegramCheckUserByName {
    public:
    typedef TelegramCheckUserByNameRequest Request;
    typedef TelegramCheckUserByNameResponse Response;
  };

}
#endif
