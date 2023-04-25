#ifndef _ROS_strawberry_ros_msgs_DialogEvent_h
#define _ROS_strawberry_ros_msgs_DialogEvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"

namespace strawberry_ros_msgs
{

  class DialogEvent : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _intent_name_type;
      _intent_name_type intent_name;
      uint32_t parameters_length;
      typedef diagnostic_msgs::KeyValue _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;

    DialogEvent():
      name(""),
      description(""),
      intent_name(""),
      parameters_length(0), st_parameters(), parameters(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_intent_name = strlen(this->intent_name);
      varToArr(outbuffer + offset, length_intent_name);
      offset += 4;
      memcpy(outbuffer + offset, this->intent_name, length_intent_name);
      offset += length_intent_name;
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
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_intent_name;
      arrToVar(length_intent_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_intent_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_intent_name-1]=0;
      this->intent_name = (char *)(inbuffer + offset-1);
      offset += length_intent_name;
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

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogEvent"; };
    virtual const char * getMD5() override { return "9dbe9d24c94708b3bba653f73e4db2f4"; };

  };

}
#endif
