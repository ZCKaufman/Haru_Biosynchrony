#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetChatMessage_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetChatMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetChatMessage : public ros::Msg
  {
    public:
      uint32_t ipad_ids_length;
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type st_ipad_ids;
      _ipad_ids_type * ipad_ids;
      uint32_t messages_length;
      typedef std_msgs::String _messages_type;
      _messages_type st_messages;
      _messages_type * messages;

    UnityProjectorSetChatMessage():
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr),
      messages_length(0), st_messages(), messages(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ipad_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ipad_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ipad_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ipad_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ipad_ids_length);
      for( uint32_t i = 0; i < ipad_ids_length; i++){
      offset += this->ipad_ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->messages_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->messages_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->messages_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->messages_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->messages_length);
      for( uint32_t i = 0; i < messages_length; i++){
      offset += this->messages[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t ipad_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ipad_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ipad_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ipad_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ipad_ids_length);
      if(ipad_ids_lengthT > ipad_ids_length)
        this->ipad_ids = (std_msgs::String*)realloc(this->ipad_ids, ipad_ids_lengthT * sizeof(std_msgs::String));
      ipad_ids_length = ipad_ids_lengthT;
      for( uint32_t i = 0; i < ipad_ids_length; i++){
      offset += this->st_ipad_ids.deserialize(inbuffer + offset);
        memcpy( &(this->ipad_ids[i]), &(this->st_ipad_ids), sizeof(std_msgs::String));
      }
      uint32_t messages_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->messages_length);
      if(messages_lengthT > messages_length)
        this->messages = (std_msgs::String*)realloc(this->messages, messages_lengthT * sizeof(std_msgs::String));
      messages_length = messages_lengthT;
      for( uint32_t i = 0; i < messages_length; i++){
      offset += this->st_messages.deserialize(inbuffer + offset);
        memcpy( &(this->messages[i]), &(this->st_messages), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetChatMessage"; };
    virtual const char * getMD5() override { return "10d0e9024baa9c1ef2783b747f190889"; };

  };

}
#endif
