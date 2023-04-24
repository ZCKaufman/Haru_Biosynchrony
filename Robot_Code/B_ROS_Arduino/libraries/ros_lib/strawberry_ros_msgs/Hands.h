#ifndef _ROS_strawberry_ros_msgs_Hands_h
#define _ROS_strawberry_ros_msgs_Hands_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/Hand.h"

namespace strawberry_ros_msgs
{

  class Hands : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t hands_length;
      typedef strawberry_ros_msgs::Hand _hands_type;
      _hands_type st_hands;
      _hands_type * hands;

    Hands():
      header(),
      hands_length(0), st_hands(), hands(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->hands_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hands_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hands_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hands_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hands_length);
      for( uint32_t i = 0; i < hands_length; i++){
      offset += this->hands[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t hands_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hands_length);
      if(hands_lengthT > hands_length)
        this->hands = (strawberry_ros_msgs::Hand*)realloc(this->hands, hands_lengthT * sizeof(strawberry_ros_msgs::Hand));
      hands_length = hands_lengthT;
      for( uint32_t i = 0; i < hands_length; i++){
      offset += this->st_hands.deserialize(inbuffer + offset);
        memcpy( &(this->hands[i]), &(this->st_hands), sizeof(strawberry_ros_msgs::Hand));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Hands"; };
    virtual const char * getMD5() override { return "a3f112db460601fe73c1ded1da336d55"; };

  };

}
#endif
