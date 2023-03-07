#ifndef _ROS_idmind_tabletop_msgs_LCDPlaylistCommand_h
#define _ROS_idmind_tabletop_msgs_LCDPlaylistCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/LCDCommand.h"

namespace idmind_tabletop_msgs
{

  class LCDPlaylistCommand : public ros::Msg
  {
    public:
      uint32_t playlist_length;
      typedef idmind_tabletop_msgs::LCDCommand _playlist_type;
      _playlist_type st_playlist;
      _playlist_type * playlist;

    LCDPlaylistCommand():
      playlist_length(0), st_playlist(), playlist(nullptr)
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
        this->playlist = (idmind_tabletop_msgs::LCDCommand*)realloc(this->playlist, playlist_lengthT * sizeof(idmind_tabletop_msgs::LCDCommand));
      playlist_length = playlist_lengthT;
      for( uint32_t i = 0; i < playlist_length; i++){
      offset += this->st_playlist.deserialize(inbuffer + offset);
        memcpy( &(this->playlist[i]), &(this->st_playlist), sizeof(idmind_tabletop_msgs::LCDCommand));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDPlaylistCommand"; };
    virtual const char * getMD5() override { return "0da9939ec7695866660d63f0511cfe96"; };

  };

}
#endif
