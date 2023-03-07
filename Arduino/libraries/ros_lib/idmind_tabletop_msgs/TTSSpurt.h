#ifndef _ROS_idmind_tabletop_msgs_TTSSpurt_h
#define _ROS_idmind_tabletop_msgs_TTSSpurt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/TTSConfig.h"

namespace idmind_tabletop_msgs
{

  class TTSSpurt : public ros::Msg
  {
    public:
      typedef idmind_tabletop_msgs::TTSConfig _config_type;
      _config_type config;
      typedef const char* _text_type;
      _text_type text;

    TTSSpurt():
      config(),
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->config.serialize(outbuffer + offset);
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->config.deserialize(inbuffer + offset);
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSSpurt"; };
    virtual const char * getMD5() override { return "a1a7114f807b13a3cc2fb50b413d63c8"; };

  };

}
#endif
