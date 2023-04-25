#ifndef _ROS_strawberry_ros_msgs_HandPart_h
#define _ROS_strawberry_ros_msgs_HandPart_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

  class HandPart : public ros::Msg
  {
    public:
      typedef uint32_t _part_id_type;
      _part_id_type part_id;
      typedef const char* _name_type;
      _name_type name;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      enum { WRIST = wrist };
      enum { THUMB_CMC = thumb_cmc };
      enum { THUMB_MCP = thumb_mcp };
      enum { THUMB_IP = thumb_ip };
      enum { THUMB_TIP = thumb_tip };
      enum { INDEX_FINGER_MCP = index_finger_mcp };
      enum { INDEX_FINGER_PIP = index_finger_pip };
      enum { INDEX_FINGER_DIP = index_finger_dip };
      enum { INDEX_FINGER_TIP = index_finger_tip };
      enum { MIDDLE_FINGER_MCP = middle_finger_mcp };
      enum { MIDDLE_FINGER_PIP = middle_finger_pip };
      enum { MIDDLE_FINGER_DIP = middle_finger_dip };
      enum { MIDDLE_FINGER_TIP = middle_finger_tip };
      enum { RING_FINGER_MCP = ring_finger_mcp };
      enum { RING_FINGER_PIP = ring_finger_pip };
      enum { RING_FINGER_DIP = ring_finger_dip };
      enum { RING_FINGER_TIP = ring_finger_tip };
      enum { PINKY_MCP = pinky_mcp };
      enum { PINKY_PIP = pinky_pip };
      enum { PINKY_DIP = pinky_dip };
      enum { PINKY_TIP = pinky_tip };

    HandPart():
      part_id(0),
      name(""),
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->part_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->part_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->part_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->part_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->part_id);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->part_id =  ((uint32_t) (*(inbuffer + offset)));
      this->part_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->part_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->part_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->part_id);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/HandPart"; };
    virtual const char * getMD5() override { return "f94c64f1acc28c93cfe7e3b515f27a4f"; };

  };

}
#endif
