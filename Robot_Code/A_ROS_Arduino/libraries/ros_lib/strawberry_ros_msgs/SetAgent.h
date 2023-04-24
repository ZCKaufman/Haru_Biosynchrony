#ifndef _ROS_SERVICE_SetAgent_h
#define _ROS_SERVICE_SetAgent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char SETAGENT[] = "strawberry_ros_msgs/SetAgent";

  class SetAgentRequest : public ros::Msg
  {
    public:
      typedef const char* _selected_agent_type;
      _selected_agent_type selected_agent;
      enum { HARU_PRODUCTION = Haru-Production };
      enum { HARU_DEV = Haru-Dev };
      enum { HARU_GAMES = Haru-Games };

    SetAgentRequest():
      selected_agent("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_selected_agent = strlen(this->selected_agent);
      varToArr(outbuffer + offset, length_selected_agent);
      offset += 4;
      memcpy(outbuffer + offset, this->selected_agent, length_selected_agent);
      offset += length_selected_agent;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_selected_agent;
      arrToVar(length_selected_agent, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_selected_agent; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_selected_agent-1]=0;
      this->selected_agent = (char *)(inbuffer + offset-1);
      offset += length_selected_agent;
     return offset;
    }

    virtual const char * getType() override { return SETAGENT; };
    virtual const char * getMD5() override { return "fddc8d12d6d583929293f1ee534e46cb"; };

  };

  class SetAgentResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SetAgentResponse():
      success(0),
      message("")
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
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
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
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return SETAGENT; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SetAgent {
    public:
    typedef SetAgentRequest Request;
    typedef SetAgentResponse Response;
  };

}
#endif
