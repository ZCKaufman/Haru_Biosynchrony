#ifndef _ROS_haru_encouraging_mediator_msgs_DialogGoal_h
#define _ROS_haru_encouraging_mediator_msgs_DialogGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class DialogGoal : public ros::Msg
  {
    public:
      typedef const char* _user_sentence_type;
      _user_sentence_type user_sentence;

    DialogGoal():
      user_sentence("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_user_sentence = strlen(this->user_sentence);
      varToArr(outbuffer + offset, length_user_sentence);
      offset += 4;
      memcpy(outbuffer + offset, this->user_sentence, length_user_sentence);
      offset += length_user_sentence;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_user_sentence;
      arrToVar(length_user_sentence, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_sentence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_sentence-1]=0;
      this->user_sentence = (char *)(inbuffer + offset-1);
      offset += length_user_sentence;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/DialogGoal"; };
    virtual const char * getMD5() override { return "4a8b6da8b32e2a4d0776d0493018ad7b"; };

  };

}
#endif
