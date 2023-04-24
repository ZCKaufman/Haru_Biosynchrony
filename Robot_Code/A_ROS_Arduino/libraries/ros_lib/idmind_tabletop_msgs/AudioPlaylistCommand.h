#ifndef _ROS_idmind_tabletop_msgs_AudioPlaylistCommand_h
#define _ROS_idmind_tabletop_msgs_AudioPlaylistCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/AudioCommand.h"

namespace idmind_tabletop_msgs
{

  class AudioPlaylistCommand : public ros::Msg
  {
    public:
      uint32_t playlist_length;
      typedef idmind_tabletop_msgs::AudioCommand _playlist_type;
      _playlist_type st_playlist;
      _playlist_type * playlist;
      typedef uint8_t _channel_type;
      _channel_type channel;
      enum { MUSIC_CHANNEL =  0 };
      enum { SPEECH_CHANNEL =  1 };

    AudioPlaylistCommand():
      playlist_length(0), st_playlist(), playlist(nullptr),
      channel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->playlist_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->playlist_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->playlist_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->playlist_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->playlist_length);
      for( uint32_t i = 0; i < playlist_length; i++){
      offset += this->playlist[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t playlist_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      playlist_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      playlist_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      playlist_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->playlist_length);
      if(playlist_lengthT > playlist_length)
        this->playlist = (idmind_tabletop_msgs::AudioCommand*)realloc(this->playlist, playlist_lengthT * sizeof(idmind_tabletop_msgs::AudioCommand));
      playlist_length = playlist_lengthT;
      for( uint32_t i = 0; i < playlist_length; i++){
      offset += this->st_playlist.deserialize(inbuffer + offset);
        memcpy( &(this->playlist[i]), &(this->st_playlist), sizeof(idmind_tabletop_msgs::AudioCommand));
      }
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioPlaylistCommand"; };
    virtual const char * getMD5() override { return "d7635ff232c5fef93ce4e2ed033084d2"; };

  };

}
#endif
