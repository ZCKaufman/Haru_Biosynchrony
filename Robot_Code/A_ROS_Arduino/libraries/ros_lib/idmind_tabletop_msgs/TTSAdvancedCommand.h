#ifndef _ROS_idmind_tabletop_msgs_TTSAdvancedCommand_h
#define _ROS_idmind_tabletop_msgs_TTSAdvancedCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "idmind_tabletop_msgs/TTSConfig.h"
#include "idmind_tabletop_msgs/TTSSpurt.h"

namespace idmind_tabletop_msgs
{

  class TTSAdvancedCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef idmind_tabletop_msgs::TTSConfig _global_config_type;
      _global_config_type global_config;
      uint32_t spurts_length;
      typedef idmind_tabletop_msgs::TTSSpurt _spurts_type;
      _spurts_type st_spurts;
      _spurts_type * spurts;
      typedef bool _disable_lipsync_type;
      _disable_lipsync_type disable_lipsync;

    TTSAdvancedCommand():
      header(),
      global_config(),
      spurts_length(0), st_spurts(), spurts(nullptr),
      disable_lipsync(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->global_config.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->spurts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->spurts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->spurts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->spurts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spurts_length);
      for( uint32_t i = 0; i < spurts_length; i++){
      offset += this->spurts[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_disable_lipsync;
      u_disable_lipsync.real = this->disable_lipsync;
      *(outbuffer + offset + 0) = (u_disable_lipsync.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_lipsync);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->global_config.deserialize(inbuffer + offset);
      uint32_t spurts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      spurts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      spurts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      spurts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->spurts_length);
      if(spurts_lengthT > spurts_length)
        this->spurts = (idmind_tabletop_msgs::TTSSpurt*)realloc(this->spurts, spurts_lengthT * sizeof(idmind_tabletop_msgs::TTSSpurt));
      spurts_length = spurts_lengthT;
      for( uint32_t i = 0; i < spurts_length; i++){
      offset += this->st_spurts.deserialize(inbuffer + offset);
        memcpy( &(this->spurts[i]), &(this->st_spurts), sizeof(idmind_tabletop_msgs::TTSSpurt));
      }
      union {
        bool real;
        uint8_t base;
      } u_disable_lipsync;
      u_disable_lipsync.base = 0;
      u_disable_lipsync.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_lipsync = u_disable_lipsync.real;
      offset += sizeof(this->disable_lipsync);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSAdvancedCommand"; };
    virtual const char * getMD5() override { return "a223a9b1a582fb4c812e84415cf89435"; };

  };

}
#endif
