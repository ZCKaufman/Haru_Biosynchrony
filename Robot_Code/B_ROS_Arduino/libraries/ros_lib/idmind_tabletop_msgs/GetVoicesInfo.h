#ifndef _ROS_SERVICE_GetVoicesInfo_h
#define _ROS_SERVICE_GetVoicesInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/TTSVoiceInfo.h"

namespace idmind_tabletop_msgs
{

static const char GETVOICESINFO[] = "idmind_tabletop_msgs/GetVoicesInfo";

  class GetVoicesInfoRequest : public ros::Msg
  {
    public:

    GetVoicesInfoRequest()
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

    virtual const char * getType() override { return GETVOICESINFO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetVoicesInfoResponse : public ros::Msg
  {
    public:
      uint32_t voices_length;
      typedef idmind_tabletop_msgs::TTSVoiceInfo _voices_type;
      _voices_type st_voices;
      _voices_type * voices;

    GetVoicesInfoResponse():
      voices_length(0), st_voices(), voices(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->voices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->voices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->voices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voices_length);
      for( uint32_t i = 0; i < voices_length; i++){
      offset += this->voices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t voices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      voices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      voices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      voices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->voices_length);
      if(voices_lengthT > voices_length)
        this->voices = (idmind_tabletop_msgs::TTSVoiceInfo*)realloc(this->voices, voices_lengthT * sizeof(idmind_tabletop_msgs::TTSVoiceInfo));
      voices_length = voices_lengthT;
      for( uint32_t i = 0; i < voices_length; i++){
      offset += this->st_voices.deserialize(inbuffer + offset);
        memcpy( &(this->voices[i]), &(this->st_voices), sizeof(idmind_tabletop_msgs::TTSVoiceInfo));
      }
     return offset;
    }

    virtual const char * getType() override { return GETVOICESINFO; };
    virtual const char * getMD5() override { return "f5a6111bae811a2eae7ab1a4359a938a"; };

  };

  class GetVoicesInfo {
    public:
    typedef GetVoicesInfoRequest Request;
    typedef GetVoicesInfoResponse Response;
  };

}
#endif
