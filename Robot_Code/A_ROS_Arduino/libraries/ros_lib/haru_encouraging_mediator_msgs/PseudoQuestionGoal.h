#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoQuestionGoal_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoQuestionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoQuestionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::UInt8 _ipad_id_type;
      _ipad_id_type ipad_id;
      typedef std_msgs::UInt8 _user_input_type_type;
      _user_input_type_type user_input_type;
      typedef std_msgs::String _question_type;
      _question_type question;
      uint32_t choices_length;
      typedef std_msgs::String _choices_type;
      _choices_type st_choices;
      _choices_type * choices;
      typedef std_msgs::Float64 _timeout_type;
      _timeout_type timeout;
      enum { YES_NO =  0 };
      enum { MUL_CHOICE =  1 };
      enum { FREE_INPUT =  2 };

    PseudoQuestionGoal():
      header(),
      ipad_id(),
      user_input_type(),
      question(),
      choices_length(0), st_choices(), choices(nullptr),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->ipad_id.serialize(outbuffer + offset);
      offset += this->user_input_type.serialize(outbuffer + offset);
      offset += this->question.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->choices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->choices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->choices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->choices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->choices_length);
      for( uint32_t i = 0; i < choices_length; i++){
      offset += this->choices[i].serialize(outbuffer + offset);
      }
      offset += this->timeout.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->ipad_id.deserialize(inbuffer + offset);
      offset += this->user_input_type.deserialize(inbuffer + offset);
      offset += this->question.deserialize(inbuffer + offset);
      uint32_t choices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      choices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      choices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      choices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->choices_length);
      if(choices_lengthT > choices_length)
        this->choices = (std_msgs::String*)realloc(this->choices, choices_lengthT * sizeof(std_msgs::String));
      choices_length = choices_lengthT;
      for( uint32_t i = 0; i < choices_length; i++){
      offset += this->st_choices.deserialize(inbuffer + offset);
        memcpy( &(this->choices[i]), &(this->st_choices), sizeof(std_msgs::String));
      }
      offset += this->timeout.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoQuestionGoal"; };
    virtual const char * getMD5() override { return "1d08a80286894d700a89470e92f0e5d8"; };

  };

}
#endif
