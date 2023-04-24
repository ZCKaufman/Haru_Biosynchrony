#ifndef _ROS_SERVICE_TriggerDialogEvent_h
#define _ROS_SERVICE_TriggerDialogEvent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"
#include "strawberry_ros_msgs/DialogResult.h"

namespace strawberry_ros_msgs
{

static const char TRIGGERDIALOGEVENT[] = "strawberry_ros_msgs/TriggerDialogEvent";

  class TriggerDialogEventRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _event_name_type;
      _event_name_type event_name;
      typedef const char* _language_code_type;
      _language_code_type language_code;
      uint32_t parameters_length;
      typedef diagnostic_msgs::KeyValue _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;

    TriggerDialogEventRequest():
      person_id(0),
      event_name(""),
      language_code(""),
      parameters_length(0), st_parameters(), parameters(nullptr)
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
      uint32_t length_event_name = strlen(this->event_name);
      varToArr(outbuffer + offset, length_event_name);
      offset += 4;
      memcpy(outbuffer + offset, this->event_name, length_event_name);
      offset += length_event_name;
      uint32_t length_language_code = strlen(this->language_code);
      varToArr(outbuffer + offset, length_language_code);
      offset += 4;
      memcpy(outbuffer + offset, this->language_code, length_language_code);
      offset += length_language_code;
      *(outbuffer + offset + 0) = (this->parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameters_length);
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_event_name;
      arrToVar(length_event_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_event_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_event_name-1]=0;
      this->event_name = (char *)(inbuffer + offset-1);
      offset += length_event_name;
      uint32_t length_language_code;
      arrToVar(length_language_code, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language_code-1]=0;
      this->language_code = (char *)(inbuffer + offset-1);
      offset += length_language_code;
      uint32_t parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parameters_length);
      if(parameters_lengthT > parameters_length)
        this->parameters = (diagnostic_msgs::KeyValue*)realloc(this->parameters, parameters_lengthT * sizeof(diagnostic_msgs::KeyValue));
      parameters_length = parameters_lengthT;
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(diagnostic_msgs::KeyValue));
      }
     return offset;
    }

    virtual const char * getType() override { return TRIGGERDIALOGEVENT; };
    virtual const char * getMD5() override { return "c0c4e7850ae6f91dabadf6c772e669c8"; };

  };

  class TriggerDialogEventResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;
      typedef strawberry_ros_msgs::DialogResult _result_type;
      _result_type result;

    TriggerDialogEventResponse():
      success(0),
      message(""),
      result()
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
      offset += this->result.serialize(outbuffer + offset);
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
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TRIGGERDIALOGEVENT; };
    virtual const char * getMD5() override { return "4deeccbb0c8789567f97c74c1f2ba07a"; };

  };

  class TriggerDialogEvent {
    public:
    typedef TriggerDialogEventRequest Request;
    typedef TriggerDialogEventResponse Response;
  };

}
#endif
