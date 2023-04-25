#ifndef _ROS_behavior_tree_ros_ExchangeInfoResult_h
#define _ROS_behavior_tree_ros_ExchangeInfoResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

  class ExchangeInfoResult : public ros::Msg
  {
    public:
      typedef const char* _info_data_type;
      _info_data_type info_data;
      typedef const char* _info_type_type;
      _info_type_type info_type;
      typedef bool _info_received_type;
      _info_received_type info_received;

    ExchangeInfoResult():
      info_data(""),
      info_type(""),
      info_received(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_info_data = strlen(this->info_data);
      varToArr(outbuffer + offset, length_info_data);
      offset += 4;
      memcpy(outbuffer + offset, this->info_data, length_info_data);
      offset += length_info_data;
      uint32_t length_info_type = strlen(this->info_type);
      varToArr(outbuffer + offset, length_info_type);
      offset += 4;
      memcpy(outbuffer + offset, this->info_type, length_info_type);
      offset += length_info_type;
      union {
        bool real;
        uint8_t base;
      } u_info_received;
      u_info_received.real = this->info_received;
      *(outbuffer + offset + 0) = (u_info_received.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->info_received);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_info_data;
      arrToVar(length_info_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_data-1]=0;
      this->info_data = (char *)(inbuffer + offset-1);
      offset += length_info_data;
      uint32_t length_info_type;
      arrToVar(length_info_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_type-1]=0;
      this->info_type = (char *)(inbuffer + offset-1);
      offset += length_info_type;
      union {
        bool real;
        uint8_t base;
      } u_info_received;
      u_info_received.base = 0;
      u_info_received.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->info_received = u_info_received.real;
      offset += sizeof(this->info_received);
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/ExchangeInfoResult"; };
    virtual const char * getMD5() override { return "bf68fd433a575adaa87962c0ea40aa78"; };

  };

}
#endif
