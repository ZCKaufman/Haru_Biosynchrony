#ifndef _ROS_idmind_tabletop_msgs_AudioStatus_h
#define _ROS_idmind_tabletop_msgs_AudioStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/AudioStatusAux.h"

namespace idmind_tabletop_msgs
{

  class AudioStatus : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      typedef const char* _music_file_type;
      _music_file_type music_file;
      typedef float _music_progress_type;
      _music_progress_type music_progress;
      typedef float _music_current_time_type;
      _music_current_time_type music_current_time;
      typedef const char* _speech_file_type;
      _speech_file_type speech_file;
      typedef float _speech_progress_type;
      _speech_progress_type speech_progress;
      typedef float _speech_current_time_type;
      _speech_current_time_type speech_current_time;
      typedef idmind_tabletop_msgs::AudioStatusAux _aux_channels_status_type;
      _aux_channels_status_type aux_channels_status;
      enum { PLAYING =  0 };
      enum { STOPPED =  1 };

    AudioStatus():
      status(0),
      music_file(""),
      music_progress(0),
      music_current_time(0),
      speech_file(""),
      speech_progress(0),
      speech_current_time(0),
      aux_channels_status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      uint32_t length_music_file = strlen(this->music_file);
      varToArr(outbuffer + offset, length_music_file);
      offset += 4;
      memcpy(outbuffer + offset, this->music_file, length_music_file);
      offset += length_music_file;
      offset += serializeAvrFloat64(outbuffer + offset, this->music_progress);
      offset += serializeAvrFloat64(outbuffer + offset, this->music_current_time);
      uint32_t length_speech_file = strlen(this->speech_file);
      varToArr(outbuffer + offset, length_speech_file);
      offset += 4;
      memcpy(outbuffer + offset, this->speech_file, length_speech_file);
      offset += length_speech_file;
      offset += serializeAvrFloat64(outbuffer + offset, this->speech_progress);
      offset += serializeAvrFloat64(outbuffer + offset, this->speech_current_time);
      offset += this->aux_channels_status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      uint32_t length_music_file;
      arrToVar(length_music_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_music_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_music_file-1]=0;
      this->music_file = (char *)(inbuffer + offset-1);
      offset += length_music_file;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->music_progress));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->music_current_time));
      uint32_t length_speech_file;
      arrToVar(length_speech_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_speech_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_speech_file-1]=0;
      this->speech_file = (char *)(inbuffer + offset-1);
      offset += length_speech_file;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speech_progress));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speech_current_time));
      offset += this->aux_channels_status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioStatus"; };
    virtual const char * getMD5() override { return "d100319bd20b2a6a94f31e36a5c53b4e"; };

  };

}
#endif
