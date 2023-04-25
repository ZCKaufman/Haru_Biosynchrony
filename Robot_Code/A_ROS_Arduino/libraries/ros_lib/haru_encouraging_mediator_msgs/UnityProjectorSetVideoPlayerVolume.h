#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetVideoPlayerVolume_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetVideoPlayerVolume_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetVideoPlayerVolume : public ros::Msg
  {
    public:
      typedef uint16_t _track_type;
      _track_type track;
      typedef float _volume_type;
      _volume_type volume;

    UnityProjectorSetVideoPlayerVolume():
      track(0),
      volume(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->track >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->track >> (8 * 1)) & 0xFF;
      offset += sizeof(this->track);
      union {
        float real;
        uint32_t base;
      } u_volume;
      u_volume.real = this->volume;
      *(outbuffer + offset + 0) = (u_volume.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volume.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volume.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volume.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volume);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->track =  ((uint16_t) (*(inbuffer + offset)));
      this->track |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->track);
      union {
        float real;
        uint32_t base;
      } u_volume;
      u_volume.base = 0;
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volume = u_volume.real;
      offset += sizeof(this->volume);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetVideoPlayerVolume"; };
    virtual const char * getMD5() override { return "861338606c43661cf5bba274176e57f8"; };

  };

}
#endif
