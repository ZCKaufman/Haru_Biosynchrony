#ifndef _ROS_idmind_tabletop_msgs_AudioMusicFeedback_h
#define _ROS_idmind_tabletop_msgs_AudioMusicFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioMusicFeedback : public ros::Msg
  {
    public:
      typedef const char* _music_file_type;
      _music_file_type music_file;
      typedef float _music_progress_type;
      _music_progress_type music_progress;
      typedef float _music_current_time_type;
      _music_current_time_type music_current_time;

    AudioMusicFeedback():
      music_file(""),
      music_progress(0),
      music_current_time(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->music_progress);
      offset += serializeAvrFloat64(outbuffer + offset, this->music_current_time);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->music_progress));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->music_current_time));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioMusicFeedback"; };
    virtual const char * getMD5() override { return "86be8c2c21267fea7758a2cbe41110ed"; };

  };

}
#endif
