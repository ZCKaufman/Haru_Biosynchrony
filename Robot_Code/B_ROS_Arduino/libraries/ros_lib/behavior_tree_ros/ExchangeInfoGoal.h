#ifndef _ROS_behavior_tree_ros_ExchangeInfoGoal_h
#define _ROS_behavior_tree_ros_ExchangeInfoGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

  class ExchangeInfoGoal : public ros::Msg
  {
    public:
      typedef const char* _bt_id_type;
      _bt_id_type bt_id;
      typedef const char* _info_type_type;
      _info_type_type info_type;
      typedef const char* _info_data_type;
      _info_data_type info_data;

    ExchangeInfoGoal():
      bt_id(""),
      info_type(""),
      info_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_bt_id = strlen(this->bt_id);
      varToArr(outbuffer + offset, length_bt_id);
      offset += 4;
      memcpy(outbuffer + offset, this->bt_id, length_bt_id);
      offset += length_bt_id;
      uint32_t length_info_type = strlen(this->info_type);
      varToArr(outbuffer + offset, length_info_type);
      offset += 4;
      memcpy(outbuffer + offset, this->info_type, length_info_type);
      offset += length_info_type;
      uint32_t length_info_data = strlen(this->info_data);
      varToArr(outbuffer + offset, length_info_data);
      offset += 4;
      memcpy(outbuffer + offset, this->info_data, length_info_data);
      offset += length_info_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_bt_id;
      arrToVar(length_bt_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_bt_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_bt_id-1]=0;
      this->bt_id = (char *)(inbuffer + offset-1);
      offset += length_bt_id;
      uint32_t length_info_type;
      arrToVar(length_info_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_type-1]=0;
      this->info_type = (char *)(inbuffer + offset-1);
      offset += length_info_type;
      uint32_t length_info_data;
      arrToVar(length_info_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_data-1]=0;
      this->info_data = (char *)(inbuffer + offset-1);
      offset += length_info_data;
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/ExchangeInfoGoal"; };
    virtual const char * getMD5() override { return "fcd6e1af0253ea897ed7a916f85f2db2"; };

  };

}
#endif
