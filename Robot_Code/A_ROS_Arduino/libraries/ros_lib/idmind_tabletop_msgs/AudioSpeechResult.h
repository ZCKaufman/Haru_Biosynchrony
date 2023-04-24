#ifndef _ROS_idmind_tabletop_msgs_AudioSpeechResult_h
#define _ROS_idmind_tabletop_msgs_AudioSpeechResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioSpeechResult : public ros::Msg
  {
    public:
      typedef const char* _speech_file_type;
      _speech_file_type speech_file;
      typedef bool _speech_file_played_type;
      _speech_file_played_type speech_file_played;

    AudioSpeechResult():
      speech_file(""),
      speech_file_played(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_speech_file = strlen(this->speech_file);
      varToArr(outbuffer + offset, length_speech_file);
      offset += 4;
      memcpy(outbuffer + offset, this->speech_file, length_speech_file);
      offset += length_speech_file;
      union {
        bool real;
        uint8_t base;
      } u_speech_file_played;
      u_speech_file_played.real = this->speech_file_played;
      *(outbuffer + offset + 0) = (u_speech_file_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speech_file_played);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_speech_file;
      arrToVar(length_speech_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_speech_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_speech_file-1]=0;
      this->speech_file = (char *)(inbuffer + offset-1);
      offset += length_speech_file;
      union {
        bool real;
        uint8_t base;
      } u_speech_file_played;
      u_speech_file_played.base = 0;
      u_speech_file_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speech_file_played = u_speech_file_played.real;
      offset += sizeof(this->speech_file_played);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioSpeechResult"; };
    virtual const char * getMD5() override { return "183ba50ad6eab369cf2b0efa73167052"; };

  };

}
#endif
