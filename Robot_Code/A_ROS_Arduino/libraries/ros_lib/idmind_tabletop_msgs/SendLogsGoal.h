#ifndef _ROS_idmind_tabletop_msgs_SendLogsGoal_h
#define _ROS_idmind_tabletop_msgs_SendLogsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class SendLogsGoal : public ros::Msg
  {
    public:
      typedef const char* _identifier_type;
      _identifier_type identifier;

    SendLogsGoal():
      identifier("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_identifier = strlen(this->identifier);
      varToArr(outbuffer + offset, length_identifier);
      offset += 4;
      memcpy(outbuffer + offset, this->identifier, length_identifier);
      offset += length_identifier;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_identifier;
      arrToVar(length_identifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_identifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_identifier-1]=0;
      this->identifier = (char *)(inbuffer + offset-1);
      offset += length_identifier;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/SendLogsGoal"; };
    virtual const char * getMD5() override { return "9c4b0f781baa7fd49cc9e186f2f56898"; };

  };

}
#endif
