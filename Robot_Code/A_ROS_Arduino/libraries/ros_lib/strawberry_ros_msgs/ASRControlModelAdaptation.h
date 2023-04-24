#ifndef _ROS_SERVICE_ASRControlModelAdaptation_h
#define _ROS_SERVICE_ASRControlModelAdaptation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/ASRPhraseSet.h"
#include "strawberry_ros_msgs/ASRCustomClass.h"

namespace strawberry_ros_msgs
{

static const char ASRCONTROLMODELADAPTATION[] = "strawberry_ros_msgs/ASRControlModelAdaptation";

  class ASRControlModelAdaptationRequest : public ros::Msg
  {
    public:
      typedef int8_t _action_type;
      _action_type action;
      uint32_t custom_classes_length;
      typedef strawberry_ros_msgs::ASRCustomClass _custom_classes_type;
      _custom_classes_type st_custom_classes;
      _custom_classes_type * custom_classes;
      uint32_t phrase_sets_length;
      typedef strawberry_ros_msgs::ASRPhraseSet _phrase_sets_type;
      _phrase_sets_type st_phrase_sets;
      _phrase_sets_type * phrase_sets;
      enum { GET =  0                  };
      enum { LIST =  1                 };
      enum { ADD =  2                  };
      enum { DELETE =  3               };
      enum { ENABLE =  4               };
      enum { DISABLE =  5              };

    ASRControlModelAdaptationRequest():
      action(0),
      custom_classes_length(0), st_custom_classes(), custom_classes(nullptr),
      phrase_sets_length(0), st_phrase_sets(), phrase_sets(nullptr)
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
      *(outbuffer + offset + 0) = (this->custom_classes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->custom_classes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->custom_classes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->custom_classes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->custom_classes_length);
      for( uint32_t i = 0; i < custom_classes_length; i++){
      offset += this->custom_classes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->phrase_sets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->phrase_sets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->phrase_sets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->phrase_sets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phrase_sets_length);
      for( uint32_t i = 0; i < phrase_sets_length; i++){
      offset += this->phrase_sets[i].serialize(outbuffer + offset);
      }
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
      uint32_t custom_classes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      custom_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      custom_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      custom_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->custom_classes_length);
      if(custom_classes_lengthT > custom_classes_length)
        this->custom_classes = (strawberry_ros_msgs::ASRCustomClass*)realloc(this->custom_classes, custom_classes_lengthT * sizeof(strawberry_ros_msgs::ASRCustomClass));
      custom_classes_length = custom_classes_lengthT;
      for( uint32_t i = 0; i < custom_classes_length; i++){
      offset += this->st_custom_classes.deserialize(inbuffer + offset);
        memcpy( &(this->custom_classes[i]), &(this->st_custom_classes), sizeof(strawberry_ros_msgs::ASRCustomClass));
      }
      uint32_t phrase_sets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      phrase_sets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      phrase_sets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      phrase_sets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->phrase_sets_length);
      if(phrase_sets_lengthT > phrase_sets_length)
        this->phrase_sets = (strawberry_ros_msgs::ASRPhraseSet*)realloc(this->phrase_sets, phrase_sets_lengthT * sizeof(strawberry_ros_msgs::ASRPhraseSet));
      phrase_sets_length = phrase_sets_lengthT;
      for( uint32_t i = 0; i < phrase_sets_length; i++){
      offset += this->st_phrase_sets.deserialize(inbuffer + offset);
        memcpy( &(this->phrase_sets[i]), &(this->st_phrase_sets), sizeof(strawberry_ros_msgs::ASRPhraseSet));
      }
     return offset;
    }

    virtual const char * getType() override { return ASRCONTROLMODELADAPTATION; };
    virtual const char * getMD5() override { return "eed1e5771f3904087e67a7bf5c0cd500"; };

  };

  class ASRControlModelAdaptationResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;
      uint32_t custom_classes_length;
      typedef strawberry_ros_msgs::ASRCustomClass _custom_classes_type;
      _custom_classes_type st_custom_classes;
      _custom_classes_type * custom_classes;
      uint32_t phrase_sets_length;
      typedef strawberry_ros_msgs::ASRPhraseSet _phrase_sets_type;
      _phrase_sets_type st_phrase_sets;
      _phrase_sets_type * phrase_sets;

    ASRControlModelAdaptationResponse():
      success(0),
      message(""),
      custom_classes_length(0), st_custom_classes(), custom_classes(nullptr),
      phrase_sets_length(0), st_phrase_sets(), phrase_sets(nullptr)
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
      *(outbuffer + offset + 0) = (this->custom_classes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->custom_classes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->custom_classes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->custom_classes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->custom_classes_length);
      for( uint32_t i = 0; i < custom_classes_length; i++){
      offset += this->custom_classes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->phrase_sets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->phrase_sets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->phrase_sets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->phrase_sets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phrase_sets_length);
      for( uint32_t i = 0; i < phrase_sets_length; i++){
      offset += this->phrase_sets[i].serialize(outbuffer + offset);
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
      uint32_t custom_classes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      custom_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      custom_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      custom_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->custom_classes_length);
      if(custom_classes_lengthT > custom_classes_length)
        this->custom_classes = (strawberry_ros_msgs::ASRCustomClass*)realloc(this->custom_classes, custom_classes_lengthT * sizeof(strawberry_ros_msgs::ASRCustomClass));
      custom_classes_length = custom_classes_lengthT;
      for( uint32_t i = 0; i < custom_classes_length; i++){
      offset += this->st_custom_classes.deserialize(inbuffer + offset);
        memcpy( &(this->custom_classes[i]), &(this->st_custom_classes), sizeof(strawberry_ros_msgs::ASRCustomClass));
      }
      uint32_t phrase_sets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      phrase_sets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      phrase_sets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      phrase_sets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->phrase_sets_length);
      if(phrase_sets_lengthT > phrase_sets_length)
        this->phrase_sets = (strawberry_ros_msgs::ASRPhraseSet*)realloc(this->phrase_sets, phrase_sets_lengthT * sizeof(strawberry_ros_msgs::ASRPhraseSet));
      phrase_sets_length = phrase_sets_lengthT;
      for( uint32_t i = 0; i < phrase_sets_length; i++){
      offset += this->st_phrase_sets.deserialize(inbuffer + offset);
        memcpy( &(this->phrase_sets[i]), &(this->st_phrase_sets), sizeof(strawberry_ros_msgs::ASRPhraseSet));
      }
     return offset;
    }

    virtual const char * getType() override { return ASRCONTROLMODELADAPTATION; };
    virtual const char * getMD5() override { return "4c4f6f4511f40cce7140e941fb67ba71"; };

  };

  class ASRControlModelAdaptation {
    public:
    typedef ASRControlModelAdaptationRequest Request;
    typedef ASRControlModelAdaptationResponse Response;
  };

}
#endif
