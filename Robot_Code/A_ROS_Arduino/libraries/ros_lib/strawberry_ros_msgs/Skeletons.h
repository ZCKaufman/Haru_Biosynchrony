#ifndef _ROS_strawberry_ros_msgs_Skeletons_h
#define _ROS_strawberry_ros_msgs_Skeletons_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/Skeleton.h"

namespace strawberry_ros_msgs
{

  class Skeletons : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t skeletons_length;
      typedef strawberry_ros_msgs::Skeleton _skeletons_type;
      _skeletons_type st_skeletons;
      _skeletons_type * skeletons;

    Skeletons():
      header(),
      skeletons_length(0), st_skeletons(), skeletons(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->skeletons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->skeletons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->skeletons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->skeletons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->skeletons_length);
      for( uint32_t i = 0; i < skeletons_length; i++){
      offset += this->skeletons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t skeletons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      skeletons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      skeletons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      skeletons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->skeletons_length);
      if(skeletons_lengthT > skeletons_length)
        this->skeletons = (strawberry_ros_msgs::Skeleton*)realloc(this->skeletons, skeletons_lengthT * sizeof(strawberry_ros_msgs::Skeleton));
      skeletons_length = skeletons_lengthT;
      for( uint32_t i = 0; i < skeletons_length; i++){
      offset += this->st_skeletons.deserialize(inbuffer + offset);
        memcpy( &(this->skeletons[i]), &(this->st_skeletons), sizeof(strawberry_ros_msgs::Skeleton));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Skeletons"; };
    virtual const char * getMD5() override { return "e4898f0ba89b289f00bb0026b74b93ae"; };

  };

}
#endif
