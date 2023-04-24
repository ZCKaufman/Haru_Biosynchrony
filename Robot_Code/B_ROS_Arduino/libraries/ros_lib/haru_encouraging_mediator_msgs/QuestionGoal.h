#ifndef _ROS_haru_encouraging_mediator_msgs_QuestionGoal_h
#define _ROS_haru_encouraging_mediator_msgs_QuestionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Float64.h"

namespace haru_encouraging_mediator_msgs
{

  class QuestionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type ipad_ids;
      typedef std_msgs::UInt8 _user_input_type_type;
      _user_input_type_type user_input_type;
      typedef std_msgs::String _question_type;
      _question_type question;
      typedef std_msgs::String _choices_type;
      _choices_type choices;
      typedef std_msgs::Float64 _timeout_type;
      _timeout_type timeout;
      enum { YES_NO =  0 };
      enum { MUL_CHOICE =  1 };
      enum { FREE_INPUT =  2 };

    QuestionGoal():
      ipad_ids(),
      user_input_type(),
      question(),
      choices(),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->ipad_ids.serialize(outbuffer + offset);
      offset += this->user_input_type.serialize(outbuffer + offset);
      offset += this->question.serialize(outbuffer + offset);
      offset += this->choices.serialize(outbuffer + offset);
      offset += this->timeout.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->ipad_ids.deserialize(inbuffer + offset);
      offset += this->user_input_type.deserialize(inbuffer + offset);
      offset += this->question.deserialize(inbuffer + offset);
      offset += this->choices.deserialize(inbuffer + offset);
      offset += this->timeout.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/QuestionGoal"; };
    virtual const char * getMD5() override { return "7fc25f9e8a6753c64ff358575fda01bc"; };

  };

}
#endif
