#ifndef _ROS_SERVICE_LoadTree_h
#define _ROS_SERVICE_LoadTree_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

static const char LOADTREE[] = "behavior_tree_ros/LoadTree";

  class LoadTreeRequest : public ros::Msg
  {
    public:
      typedef const char* _tree_file_type;
      _tree_file_type tree_file;

    LoadTreeRequest():
      tree_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return LOADTREE; };
    virtual const char * getMD5() override { return "ac5d22e87d0f99385d9785f81c6a92ad"; };

  };

  class LoadTreeResponse : public ros::Msg
  {
    public:

    LoadTreeResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return LOADTREE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class LoadTree {
    public:
    typedef LoadTreeRequest Request;
    typedef LoadTreeResponse Response;
  };

}
#endif
