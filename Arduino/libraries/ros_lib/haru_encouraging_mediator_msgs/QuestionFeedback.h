#ifndef _ROS_haru_encouraging_mediator_msgs_QuestionFeedback_h
#define _ROS_haru_encouraging_mediator_msgs_QuestionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

  class QuestionFeedback : public ros::Msg
  {
    public:
      uint32_t answers_length;
      typedef std_msgs::String _answers_type;
      _answers_type st_answers;
      _answers_type * answers;
      uint32_t ipad_ids_length;
      typedef std_msgs::String _ipad_ids_type;
      _ipad_ids_type st_ipad_ids;
      _ipad_ids_type * ipad_ids;
      uint32_t user_ids_length;
      typedef std_msgs::String _user_ids_type;
      _user_ids_type st_user_ids;
      _user_ids_type * user_ids;

    QuestionFeedback():
      answers_length(0), st_answers(), answers(nullptr),
      ipad_ids_length(0), st_ipad_ids(), ipad_ids(nullptr),
      user_ids_length(0), st_user_ids(), user_ids(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->answers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->answers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->answers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->answers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->answers_length);
      for( uint32_t i = 0; i < answers_length; i++){
      offset += this->answers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->ipad_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ipad_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ipad_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ipad_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ipad_ids_length);
      for( uint32_t i = 0; i < ipad_ids_length; i++){
      offset += this->ipad_ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->user_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_ids_length);
      for( uint32_t i = 0; i < user_ids_length; i++){
      offset += this->user_ids[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t answers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      answers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      answers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      answers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->answers_length);
      if(answers_lengthT > answers_length)
        this->answers = (std_msgs::String*)realloc(this->answers, answers_lengthT * sizeof(std_msgs::String));
      answers_length = answers_lengthT;
      for( uint32_t i = 0; i < answers_length; i++){
      offset += this->st_answers.deserialize(inbuffer + offset);
        memcpy( &(this->answers[i]), &(this->st_answers), sizeof(std_msgs::String));
      }
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
      uint32_t user_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      user_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      user_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      user_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->user_ids_length);
      if(user_ids_lengthT > user_ids_length)
        this->user_ids = (std_msgs::String*)realloc(this->user_ids, user_ids_lengthT * sizeof(std_msgs::String));
      user_ids_length = user_ids_lengthT;
      for( uint32_t i = 0; i < user_ids_length; i++){
      offset += this->st_user_ids.deserialize(inbuffer + offset);
        memcpy( &(this->user_ids[i]), &(this->st_user_ids), sizeof(std_msgs::String));
      }
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/QuestionFeedback"; };
    virtual const char * getMD5() override { return "a3b89c7ef308d500e5ecb869dec36cb4"; };

  };

}
#endif
