#ifndef _ROS_haru_encouraging_mediator_msgs_DialogResult_h
#define _ROS_haru_encouraging_mediator_msgs_DialogResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class DialogResult : public ros::Msg
  {
    public:
      typedef const char* _haru_sentence_type;
      _haru_sentence_type haru_sentence;
      typedef const char* _direction_type;
      _direction_type direction;

    DialogResult():
      haru_sentence(""),
      direction("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_haru_sentence = strlen(this->haru_sentence);
      varToArr(outbuffer + offset, length_haru_sentence);
      offset += 4;
      memcpy(outbuffer + offset, this->haru_sentence, length_haru_sentence);
      offset += length_haru_sentence;
      uint32_t length_direction = strlen(this->direction);
      varToArr(outbuffer + offset, length_direction);
      offset += 4;
      memcpy(outbuffer + offset, this->direction, length_direction);
      offset += length_direction;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_haru_sentence;
      arrToVar(length_haru_sentence, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_haru_sentence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_haru_sentence-1]=0;
      this->haru_sentence = (char *)(inbuffer + offset-1);
      offset += length_haru_sentence;
      uint32_t length_direction;
      arrToVar(length_direction, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_direction; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_direction-1]=0;
      this->direction = (char *)(inbuffer + offset-1);
      offset += length_direction;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/DialogResult"; };
    virtual const char * getMD5() override { return "ee38732fda90cec1eb225a97ebbecc7b"; };

  };

}
#endif
