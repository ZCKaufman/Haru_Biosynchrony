#ifndef _ROS_SERVICE_ControlSessionEntity_h
#define _ROS_SERVICE_ControlSessionEntity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/DialogSessionEntityType.h"

namespace strawberry_ros_msgs
{

static const char CONTROLSESSIONENTITY[] = "strawberry_ros_msgs/ControlSessionEntity";

  class ControlSessionEntityRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef int8_t _action_type;
      _action_type action;
      typedef strawberry_ros_msgs::DialogSessionEntityType _entity_type_type;
      _entity_type_type entity_type;
      enum { GET =  0                                 };
      enum { ADD =  1                                 };
      enum { REMOVE =  2                              };

    ControlSessionEntityRequest():
      person_id(0),
      action(0),
      entity_type()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
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
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
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

    virtual const char * getType() override { return CONTROLSESSIONENTITY; };
    virtual const char * getMD5() override { return "ace18bdca07968884d7ec0ffc05f42de"; };

  };

  class ControlSessionEntityResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;
      uint32_t entity_types_length;
      typedef strawberry_ros_msgs::DialogSessionEntityType _entity_types_type;
      _entity_types_type st_entity_types;
      _entity_types_type * entity_types;

    ControlSessionEntityResponse():
      success(0),
      message(""),
      entity_types_length(0), st_entity_types(), entity_types(nullptr)
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
      *(outbuffer + offset + 0) = (this->entity_types_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entity_types_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entity_types_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entity_types_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entity_types_length);
      for( uint32_t i = 0; i < entity_types_length; i++){
      offset += this->entity_types[i].serialize(outbuffer + offset);
      }
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
      uint32_t entity_types_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entity_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entity_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entity_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entity_types_length);
      if(entity_types_lengthT > entity_types_length)
        this->entity_types = (strawberry_ros_msgs::DialogSessionEntityType*)realloc(this->entity_types, entity_types_lengthT * sizeof(strawberry_ros_msgs::DialogSessionEntityType));
      entity_types_length = entity_types_lengthT;
      for( uint32_t i = 0; i < entity_types_length; i++){
      offset += this->st_entity_types.deserialize(inbuffer + offset);
        memcpy( &(this->entity_types[i]), &(this->st_entity_types), sizeof(strawberry_ros_msgs::DialogSessionEntityType));
      }
     return offset;
    }

    virtual const char * getType() override { return CONTROLSESSIONENTITY; };
    virtual const char * getMD5() override { return "a610bcc130cf0a131d6403db2684e35d"; };

  };

  class ControlSessionEntity {
    public:
    typedef ControlSessionEntityRequest Request;
    typedef ControlSessionEntityResponse Response;
  };

}
#endif
