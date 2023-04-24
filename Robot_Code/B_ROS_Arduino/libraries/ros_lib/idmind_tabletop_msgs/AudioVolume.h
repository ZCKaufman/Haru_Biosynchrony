#ifndef _ROS_idmind_tabletop_msgs_AudioVolume_h
#define _ROS_idmind_tabletop_msgs_AudioVolume_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class AudioVolume : public ros::Msg
  {
    public:
      typedef uint8_t _volume_type;
      _volume_type volume;

    AudioVolume():
      volume(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->volume >> (8 * 0)) & 0xFF;
      offset += sizeof(this->volume);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->volume =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->volume);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/AudioVolume"; };
    virtual const char * getMD5() override { return "0a86acf73473ef36a9dea539b67321f7"; };

  };

}
#endif
