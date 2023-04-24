#ifndef _ROS_idmind_tabletop_msgs_TTSFeedback_h
#define _ROS_idmind_tabletop_msgs_TTSFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TTSFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;

    TTSFeedback():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSFeedback"; };
    virtual const char * getMD5() override { return "284aa12dd9e9e760802ac9f38036ea5e"; };

  };

}
#endif
