#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetVideoPlayer_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetVideoPlayer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetVideoPlayer : public ros::Msg
  {
    public:
      typedef bool _activate_video_player_type;
      _activate_video_player_type activate_video_player;
      typedef const char* _video_file_type;
      _video_file_type video_file;

    UnityProjectorSetVideoPlayer():
      activate_video_player(0),
      video_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_video_player;
      u_activate_video_player.real = this->activate_video_player;
      *(outbuffer + offset + 0) = (u_activate_video_player.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->activate_video_player);
      uint32_t length_video_file = strlen(this->video_file);
      varToArr(outbuffer + offset, length_video_file);
      offset += 4;
      memcpy(outbuffer + offset, this->video_file, length_video_file);
      offset += length_video_file;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_video_player;
      u_activate_video_player.base = 0;
      u_activate_video_player.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->activate_video_player = u_activate_video_player.real;
      offset += sizeof(this->activate_video_player);
      uint32_t length_video_file;
      arrToVar(length_video_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_video_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_video_file-1]=0;
      this->video_file = (char *)(inbuffer + offset-1);
      offset += length_video_file;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetVideoPlayer"; };
    virtual const char * getMD5() override { return "9a1b54aa101f522336281891ee96ded9"; };

  };

}
#endif
