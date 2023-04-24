#ifndef _ROS_SERVICE_GetLoadedPlugins_h
#define _ROS_SERVICE_GetLoadedPlugins_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

static const char GETLOADEDPLUGINS[] = "behavior_tree_ros/GetLoadedPlugins";

  class GetLoadedPluginsRequest : public ros::Msg
  {
    public:

    GetLoadedPluginsRequest()
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

    virtual const char * getType() override { return GETLOADEDPLUGINS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetLoadedPluginsResponse : public ros::Msg
  {
    public:
      uint32_t plugins_length;
      typedef char* _plugins_type;
      _plugins_type st_plugins;
      _plugins_type * plugins;

    GetLoadedPluginsResponse():
      plugins_length(0), st_plugins(), plugins(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->plugins_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plugins_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plugins_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plugins_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plugins_length);
      for( uint32_t i = 0; i < plugins_length; i++){
      uint32_t length_pluginsi = strlen(this->plugins[i]);
      varToArr(outbuffer + offset, length_pluginsi);
      offset += 4;
      memcpy(outbuffer + offset, this->plugins[i], length_pluginsi);
      offset += length_pluginsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t plugins_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plugins_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plugins_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plugins_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plugins_length);
      if(plugins_lengthT > plugins_length)
        this->plugins = (char**)realloc(this->plugins, plugins_lengthT * sizeof(char*));
      plugins_length = plugins_lengthT;
      for( uint32_t i = 0; i < plugins_length; i++){
      uint32_t length_st_plugins;
      arrToVar(length_st_plugins, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_plugins; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_plugins-1]=0;
      this->st_plugins = (char *)(inbuffer + offset-1);
      offset += length_st_plugins;
        memcpy( &(this->plugins[i]), &(this->st_plugins), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return GETLOADEDPLUGINS; };
    virtual const char * getMD5() override { return "a49965d3bd05595bb9d8d395bdf1e585"; };

  };

  class GetLoadedPlugins {
    public:
    typedef GetLoadedPluginsRequest Request;
    typedef GetLoadedPluginsResponse Response;
  };

}
#endif
