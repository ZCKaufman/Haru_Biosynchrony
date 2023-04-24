#ifndef _ROS_idmind_tabletop_msgs_LCDStatus_h
#define _ROS_idmind_tabletop_msgs_LCDStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LCDStatus : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      typedef uint32_t _current_time_type;
      _current_time_type current_time;
      typedef uint32_t _current_frame_type;
      _current_frame_type current_frame;
      typedef float _progress_type;
      _progress_type progress;
      enum { PLAYING =  0 };
      enum { PAUSED =  1 };
      enum { STOPPED =  2 };

    LCDStatus():
      status(0),
      current_time(0),
      current_frame(0),
      progress(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->current_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_time);
      *(outbuffer + offset + 0) = (this->current_frame >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_frame >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_frame >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_frame >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_frame);
      offset += serializeAvrFloat64(outbuffer + offset, this->progress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->current_time =  ((uint32_t) (*(inbuffer + offset)));
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_time);
      this->current_frame =  ((uint32_t) (*(inbuffer + offset)));
      this->current_frame |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_frame |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_frame |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_frame);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->progress));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDStatus"; };
    virtual const char * getMD5() override { return "8d9ef282ef82220a7e56082d2cbde6e1"; };

  };

}
#endif
