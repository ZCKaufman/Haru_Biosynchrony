#ifndef _ROS_idmind_tabletop_msgs_SendLogsFeedback_h
#define _ROS_idmind_tabletop_msgs_SendLogsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class SendLogsFeedback : public ros::Msg
  {
    public:
      typedef const char* _stdout_type;
      _stdout_type stdout;

    SendLogsFeedback():
      stdout("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_stdout = strlen(this->stdout);
      varToArr(outbuffer + offset, length_stdout);
      offset += 4;
      memcpy(outbuffer + offset, this->stdout, length_stdout);
      offset += length_stdout;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_stdout;
      arrToVar(length_stdout, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_stdout; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_stdout-1]=0;
      this->stdout = (char *)(inbuffer + offset-1);
      offset += length_stdout;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/SendLogsFeedback"; };
    virtual const char * getMD5() override { return "2e051adaaccf19778bd433e0871ee498"; };

  };

}
#endif
