#ifndef _ROS_idmind_tabletop_msgs_AudioSpeechFeedback_h
#define _ROS_idmind_tabletop_msgs_AudioSpeechFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioSpeechFeedback : public ros::Msg
  {
    public:
      typedef const char* _speech_file_type;
      _speech_file_type speech_file;
      typedef float _speech_progress_type;
      _speech_progress_type speech_progress;
      typedef float _speech_current_time_type;
      _speech_current_time_type speech_current_time;

    AudioSpeechFeedback():
      speech_file(""),
      speech_progress(0),
      speech_current_time(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->speech_progress);
      offset += serializeAvrFloat64(outbuffer + offset, this->speech_current_time);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speech_progress));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speech_current_time));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioSpeechFeedback"; };
    virtual const char * getMD5() override { return "2c15d60aa798dfcd00c9cb45ebe75001"; };

  };

}
#endif
