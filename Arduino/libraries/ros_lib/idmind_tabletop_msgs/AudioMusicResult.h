#ifndef _ROS_idmind_tabletop_msgs_AudioMusicResult_h
#define _ROS_idmind_tabletop_msgs_AudioMusicResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioMusicResult : public ros::Msg
  {
    public:
      typedef const char* _music_file_type;
      _music_file_type music_file;
      typedef bool _music_file_played_type;
      _music_file_played_type music_file_played;

    AudioMusicResult():
      music_file(""),
      music_file_played(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_music_file = strlen(this->music_file);
      varToArr(outbuffer + offset, length_music_file);
      offset += 4;
      memcpy(outbuffer + offset, this->music_file, length_music_file);
      offset += length_music_file;
      union {
        bool real;
        uint8_t base;
      } u_music_file_played;
      u_music_file_played.real = this->music_file_played;
      *(outbuffer + offset + 0) = (u_music_file_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->music_file_played);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_music_file;
      arrToVar(length_music_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_music_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_music_file-1]=0;
      this->music_file = (char *)(inbuffer + offset-1);
      offset += length_music_file;
      union {
        bool real;
        uint8_t base;
      } u_music_file_played;
      u_music_file_played.base = 0;
      u_music_file_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->music_file_played = u_music_file_played.real;
      offset += sizeof(this->music_file_played);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioMusicResult"; };
    virtual const char * getMD5() override { return "bf8888d5627474fe7e6d0fc7734776a0"; };

  };

}
#endif
