#ifndef _ROS_idmind_tabletop_msgs_AudioPlaybackCommand_h
#define _ROS_idmind_tabletop_msgs_AudioPlaybackCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioPlaybackCommand : public ros::Msg
  {
    public:
      typedef uint8_t _command_type;
      _command_type command;
      typedef uint32_t _entry_index_type;
      _entry_index_type entry_index;
      typedef uint8_t _channel_type;
      _channel_type channel;
      enum { STOP =  0 };
      enum { STOP_ALL =  1 };
      enum { NEXT =  2 };
      enum { PREVIOUS =  3 };
      enum { JUMP_TO =  4 };
      enum { MUSIC_CHANNEL =  0 };
      enum { SPEECH_CHANNEL =  1 };

    AudioPlaybackCommand():
      command(0),
      entry_index(0),
      channel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      *(outbuffer + offset + 0) = (this->entry_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entry_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entry_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entry_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entry_index);
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      this->entry_index =  ((uint32_t) (*(inbuffer + offset)));
      this->entry_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->entry_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->entry_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->entry_index);
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioPlaybackCommand"; };
    virtual const char * getMD5() override { return "2c96077855cdbde02436c1bee893176e"; };

  };

}
#endif
