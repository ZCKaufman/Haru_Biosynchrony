#ifndef _ROS_strawberry_ros_msgs_GenericClassificationResult_h
#define _ROS_strawberry_ros_msgs_GenericClassificationResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/ClassificationResults.h"

namespace strawberry_ros_msgs
{

  class GenericClassificationResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      typedef strawberry_ros_msgs::ClassificationResults _results_type;
      _results_type results;

    GenericClassificationResult():
      header(),
      name(""),
      results()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->results.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->results.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/GenericClassificationResult"; };
    virtual const char * getMD5() override { return "86834f883f014e45fb87c911c2d67774"; };

  };

}
#endif
