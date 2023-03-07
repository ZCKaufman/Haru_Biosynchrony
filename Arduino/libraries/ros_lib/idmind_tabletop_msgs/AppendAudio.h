#ifndef _ROS_SERVICE_AppendAudio_h
#define _ROS_SERVICE_AppendAudio_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char APPENDAUDIO[] = "idmind_tabletop_msgs/AppendAudio";

  class AppendAudioRequest : public ros::Msg
  {
    public:
      typedef const char* _file_name_type;
      _file_name_type file_name;
      typedef uint8_t _channel_type;
      _channel_type channel;

    AppendAudioRequest():
      file_name(""),
      channel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file_name = strlen(this->file_name);
      varToArr(outbuffer + offset, length_file_name);
      offset += 4;
      memcpy(outbuffer + offset, this->file_name, length_file_name);
      offset += length_file_name;
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file_name;
      arrToVar(length_file_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_name-1]=0;
      this->file_name = (char *)(inbuffer + offset-1);
      offset += length_file_name;
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
     return offset;
    }

    virtual const char * getType() override { return APPENDAUDIO; };
    virtual const char * getMD5() override { return "896bab2851c8da28f8c1c31b082f693b"; };

  };

  class AppendAudioResponse : public ros::Msg
  {
    public:

    AppendAudioResponse()
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

    virtual const char * getType() override { return APPENDAUDIO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AppendAudio {
    public:
    typedef AppendAudioRequest Request;
    typedef AppendAudioResponse Response;
  };

}
#endif
