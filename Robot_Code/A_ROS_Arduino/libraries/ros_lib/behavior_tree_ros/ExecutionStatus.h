#ifndef _ROS_behavior_tree_ros_ExecutionStatus_h
#define _ROS_behavior_tree_ros_ExecutionStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

  class ExecutionStatus : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      typedef const char* _tree_file_type;
      _tree_file_type tree_file;
      enum { IDLE =  0 };
      enum { RUNNING =  1 };
      enum { SUCCESS =  2 };
      enum { FAILURE =  3 };

    ExecutionStatus():
      status(0),
      tree_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      uint32_t length_tree_file = strlen(this->tree_file);
      varToArr(outbuffer + offset, length_tree_file);
      offset += 4;
      memcpy(outbuffer + offset, this->tree_file, length_tree_file);
      offset += length_tree_file;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      uint32_t length_tree_file;
      arrToVar(length_tree_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tree_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tree_file-1]=0;
      this->tree_file = (char *)(inbuffer + offset-1);
      offset += length_tree_file;
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/ExecutionStatus"; };
    virtual const char * getMD5() override { return "0d1768a785f6064a9129f8fe4e7e7820"; };

  };

}
#endif
