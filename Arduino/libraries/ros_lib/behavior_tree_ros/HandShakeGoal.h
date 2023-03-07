#ifndef _ROS_behavior_tree_ros_HandShakeGoal_h
#define _ROS_behavior_tree_ros_HandShakeGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace behavior_tree_ros
{

  class HandShakeGoal : public ros::Msg
  {
    public:
      typedef const char* _bt_id_type;
      _bt_id_type bt_id;
      typedef const char* _message_type;
      _message_type message;

    HandShakeGoal():
      bt_id(""),
      message("")
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
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
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
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return "behavior_tree_ros/HandShakeGoal"; };
    virtual const char * getMD5() override { return "d5de2c2f4bdc22967899ccae9d88b986"; };

  };

}
#endif
