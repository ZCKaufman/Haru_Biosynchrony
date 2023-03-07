#ifndef _ROS_idmind_tabletop_msgs_RoutineStatus_h
#define _ROS_idmind_tabletop_msgs_RoutineStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class RoutineStatus : public ros::Msg
  {
    public:
      typedef bool _playing_type;
      _playing_type playing;
      typedef uint32_t _id_type;
      _id_type id;
      typedef float _progress_type;
      _progress_type progress;

    RoutineStatus():
      playing(0),
      id(0),
      progress(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_playing;
      u_playing.real = this->playing;
      *(outbuffer + offset + 0) = (u_playing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->playing);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += serializeAvrFloat64(outbuffer + offset, this->progress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_playing;
      u_playing.base = 0;
      u_playing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->playing = u_playing.real;
      offset += sizeof(this->playing);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->progress));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/RoutineStatus"; };
    virtual const char * getMD5() override { return "8222af82fa8123ffb12752beb9f3657c"; };

  };

}
#endif
