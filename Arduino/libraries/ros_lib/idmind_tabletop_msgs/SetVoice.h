#ifndef _ROS_SERVICE_SetVoice_h
#define _ROS_SERVICE_SetVoice_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char SETVOICE[] = "idmind_tabletop_msgs/SetVoice";

  class SetVoiceRequest : public ros::Msg
  {
    public:
      typedef const char* _voice_type;
      _voice_type voice;

    SetVoiceRequest():
      voice("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_voice = strlen(this->voice);
      varToArr(outbuffer + offset, length_voice);
      offset += 4;
      memcpy(outbuffer + offset, this->voice, length_voice);
      offset += length_voice;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_voice;
      arrToVar(length_voice, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_voice; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_voice-1]=0;
      this->voice = (char *)(inbuffer + offset-1);
      offset += length_voice;
     return offset;
    }

    virtual const char * getType() override { return SETVOICE; };
    virtual const char * getMD5() override { return "7b2832b7351cc77d2400704e53c0e931"; };

  };

  class SetVoiceResponse : public ros::Msg
  {
    public:

    SetVoiceResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SETVOICE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetVoice {
    public:
    typedef SetVoiceRequest Request;
    typedef SetVoiceResponse Response;
  };

}
#endif
