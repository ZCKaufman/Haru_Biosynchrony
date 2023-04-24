#ifndef _ROS_idmind_tabletop_msgs_TrackCommand_h
#define _ROS_idmind_tabletop_msgs_TrackCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TrackCommand : public ros::Msg
  {
    public:
      typedef uint8_t _command_type;
      _command_type command;
      typedef const char* _track_frame_type;
      _track_frame_type track_frame;
      enum { START_TRACKING =  0 };
      enum { START_VEL_TRACKING =  1 };
      enum { STOP_TRACKING =  2 };

    TrackCommand():
      command(0),
      track_frame("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      uint32_t length_track_frame = strlen(this->track_frame);
      varToArr(outbuffer + offset, length_track_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->track_frame, length_track_frame);
      offset += length_track_frame;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      uint32_t length_track_frame;
      arrToVar(length_track_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_track_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_track_frame-1]=0;
      this->track_frame = (char *)(inbuffer + offset-1);
      offset += length_track_frame;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TrackCommand"; };
    virtual const char * getMD5() override { return "232278f6de1178ab3dd8f7bc070444db"; };

  };

}
#endif
