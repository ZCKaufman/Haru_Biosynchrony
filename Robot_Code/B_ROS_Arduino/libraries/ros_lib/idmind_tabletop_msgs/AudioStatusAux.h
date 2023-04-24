#ifndef _ROS_idmind_tabletop_msgs_AudioStatusAux_h
#define _ROS_idmind_tabletop_msgs_AudioStatusAux_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioStatusAux : public ros::Msg
  {
    public:
      uint32_t channel_ids_length;
      typedef uint8_t _channel_ids_type;
      _channel_ids_type st_channel_ids;
      _channel_ids_type * channel_ids;
      uint32_t status_length;
      typedef uint8_t _status_type;
      _status_type st_status;
      _status_type * status;
      uint32_t audio_files_length;
      typedef char* _audio_files_type;
      _audio_files_type st_audio_files;
      _audio_files_type * audio_files;
      uint32_t audio_progress_length;
      typedef float _audio_progress_type;
      _audio_progress_type st_audio_progress;
      _audio_progress_type * audio_progress;
      uint32_t audio_current_times_length;
      typedef float _audio_current_times_type;
      _audio_current_times_type st_audio_current_times;
      _audio_current_times_type * audio_current_times;
      enum { PLAYING =  0 };
      enum { STOPPED =  1 };

    AudioStatusAux():
      channel_ids_length(0), st_channel_ids(), channel_ids(nullptr),
      status_length(0), st_status(), status(nullptr),
      audio_files_length(0), st_audio_files(), audio_files(nullptr),
      audio_progress_length(0), st_audio_progress(), audio_progress(nullptr),
      audio_current_times_length(0), st_audio_current_times(), audio_current_times(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->channel_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channel_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channel_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel_ids_length);
      for( uint32_t i = 0; i < channel_ids_length; i++){
      *(outbuffer + offset + 0) = (this->channel_ids[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel_ids[i]);
      }
      *(outbuffer + offset + 0) = (this->status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_length);
      for( uint32_t i = 0; i < status_length; i++){
      *(outbuffer + offset + 0) = (this->status[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status[i]);
      }
      *(outbuffer + offset + 0) = (this->audio_files_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->audio_files_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->audio_files_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->audio_files_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->audio_files_length);
      for( uint32_t i = 0; i < audio_files_length; i++){
      uint32_t length_audio_filesi = strlen(this->audio_files[i]);
      varToArr(outbuffer + offset, length_audio_filesi);
      offset += 4;
      memcpy(outbuffer + offset, this->audio_files[i], length_audio_filesi);
      offset += length_audio_filesi;
      }
      *(outbuffer + offset + 0) = (this->audio_progress_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->audio_progress_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->audio_progress_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->audio_progress_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->audio_progress_length);
      for( uint32_t i = 0; i < audio_progress_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->audio_progress[i]);
      }
      *(outbuffer + offset + 0) = (this->audio_current_times_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->audio_current_times_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->audio_current_times_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->audio_current_times_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->audio_current_times_length);
      for( uint32_t i = 0; i < audio_current_times_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->audio_current_times[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t channel_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channel_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channel_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channel_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->channel_ids_length);
      if(channel_ids_lengthT > channel_ids_length)
        this->channel_ids = (uint8_t*)realloc(this->channel_ids, channel_ids_lengthT * sizeof(uint8_t));
      channel_ids_length = channel_ids_lengthT;
      for( uint32_t i = 0; i < channel_ids_length; i++){
      this->st_channel_ids =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_channel_ids);
        memcpy( &(this->channel_ids[i]), &(this->st_channel_ids), sizeof(uint8_t));
      }
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_length);
      if(status_lengthT > status_length)
        this->status = (uint8_t*)realloc(this->status, status_lengthT * sizeof(uint8_t));
      status_length = status_lengthT;
      for( uint32_t i = 0; i < status_length; i++){
      this->st_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_status);
        memcpy( &(this->status[i]), &(this->st_status), sizeof(uint8_t));
      }
      uint32_t audio_files_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      audio_files_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      audio_files_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      audio_files_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->audio_files_length);
      if(audio_files_lengthT > audio_files_length)
        this->audio_files = (char**)realloc(this->audio_files, audio_files_lengthT * sizeof(char*));
      audio_files_length = audio_files_lengthT;
      for( uint32_t i = 0; i < audio_files_length; i++){
      uint32_t length_st_audio_files;
      arrToVar(length_st_audio_files, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_audio_files; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_audio_files-1]=0;
      this->st_audio_files = (char *)(inbuffer + offset-1);
      offset += length_st_audio_files;
        memcpy( &(this->audio_files[i]), &(this->st_audio_files), sizeof(char*));
      }
      uint32_t audio_progress_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      audio_progress_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      audio_progress_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      audio_progress_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->audio_progress_length);
      if(audio_progress_lengthT > audio_progress_length)
        this->audio_progress = (float*)realloc(this->audio_progress, audio_progress_lengthT * sizeof(float));
      audio_progress_length = audio_progress_lengthT;
      for( uint32_t i = 0; i < audio_progress_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_audio_progress));
        memcpy( &(this->audio_progress[i]), &(this->st_audio_progress), sizeof(float));
      }
      uint32_t audio_current_times_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      audio_current_times_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      audio_current_times_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      audio_current_times_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->audio_current_times_length);
      if(audio_current_times_lengthT > audio_current_times_length)
        this->audio_current_times = (float*)realloc(this->audio_current_times, audio_current_times_lengthT * sizeof(float));
      audio_current_times_length = audio_current_times_lengthT;
      for( uint32_t i = 0; i < audio_current_times_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_audio_current_times));
        memcpy( &(this->audio_current_times[i]), &(this->st_audio_current_times), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioStatusAux"; };
    virtual const char * getMD5() override { return "19ae5e381c62eb4ece2a0f228501a105"; };

  };

}
#endif
