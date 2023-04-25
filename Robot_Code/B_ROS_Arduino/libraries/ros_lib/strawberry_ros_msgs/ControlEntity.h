#ifndef _ROS_SERVICE_ControlEntity_h
#define _ROS_SERVICE_ControlEntity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/DialogEntityType.h"

namespace strawberry_ros_msgs
{

static const char CONTROLENTITY[] = "strawberry_ros_msgs/ControlEntity";

  class ControlEntityRequest : public ros::Msg
  {
    public:
      typedef int8_t _action_type;
      _action_type action;
      typedef strawberry_ros_msgs::DialogEntityType _entity_type_type;
      _entity_type_type entity_type;
      enum { ADD =  0                            };
      enum { REMOVE =  1                         };

    ControlEntityRequest():
      action(0),
      entity_type()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      offset += this->entity_type.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action = u_action.real;
      offset += sizeof(this->action);
      offset += this->entity_type.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CONTROLENTITY; };
    virtual const char * getMD5() override { return "39a4e72af47c7c20e56fb7762bf120a3"; };

  };

  class ControlEntityResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    ControlEntityResponse():
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

    virtual const char * getType() override { return CONTROLENTITY; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class ControlEntity {
    public:
    typedef ControlEntityRequest Request;
    typedef ControlEntityResponse Response;
  };

}
#endif
