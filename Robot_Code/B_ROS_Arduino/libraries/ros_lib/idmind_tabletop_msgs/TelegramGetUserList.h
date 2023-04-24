#ifndef _ROS_SERVICE_TelegramGetUserList_h
#define _ROS_SERVICE_TelegramGetUserList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/TelegramUser.h"

namespace idmind_tabletop_msgs
{

static const char TELEGRAMGETUSERLIST[] = "idmind_tabletop_msgs/TelegramGetUserList";

  class TelegramGetUserListRequest : public ros::Msg
  {
    public:

    TelegramGetUserListRequest()
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

    virtual const char * getType() override { return TELEGRAMGETUSERLIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TelegramGetUserListResponse : public ros::Msg
  {
    public:
      uint32_t users_length;
      typedef idmind_tabletop_msgs::TelegramUser _users_type;
      _users_type st_users;
      _users_type * users;
      typedef bool _success_type;
      _success_type success;

    TelegramGetUserListResponse():
      users_length(0), st_users(), users(nullptr),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->users_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->users_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->users_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->users_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->users_length);
      for( uint32_t i = 0; i < users_length; i++){
      offset += this->users[i].serialize(outbuffer + offset);
      }
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
      uint32_t users_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      users_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      users_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      users_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->users_length);
      if(users_lengthT > users_length)
        this->users = (idmind_tabletop_msgs::TelegramUser*)realloc(this->users, users_lengthT * sizeof(idmind_tabletop_msgs::TelegramUser));
      users_length = users_lengthT;
      for( uint32_t i = 0; i < users_length; i++){
      offset += this->st_users.deserialize(inbuffer + offset);
        memcpy( &(this->users[i]), &(this->st_users), sizeof(idmind_tabletop_msgs::TelegramUser));
      }
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

    virtual const char * getType() override { return TELEGRAMGETUSERLIST; };
    virtual const char * getMD5() override { return "52069ba7e913403e555fc39ab7d8b6d3"; };

  };

  class TelegramGetUserList {
    public:
    typedef TelegramGetUserListRequest Request;
    typedef TelegramGetUserListResponse Response;
  };

}
#endif
