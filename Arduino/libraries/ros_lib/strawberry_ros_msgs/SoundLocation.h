#ifndef _ROS_strawberry_ros_msgs_SoundLocation_h
#define _ROS_strawberry_ros_msgs_SoundLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"

namespace strawberry_ros_msgs
{

  class SoundLocation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t orientation_length;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type st_orientation;
      _orientation_type * orientation;

    SoundLocation():
      header(),
      orientation_length(0), st_orientation(), orientation(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->orientation_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientation_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->orientation_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->orientation_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation_length);
      for( uint32_t i = 0; i < orientation_length; i++){
      offset += this->orientation[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t orientation_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->orientation_length);
      if(orientation_lengthT > orientation_length)
        this->orientation = (geometry_msgs::Quaternion*)realloc(this->orientation, orientation_lengthT * sizeof(geometry_msgs::Quaternion));
      orientation_length = orientation_lengthT;
      for( uint32_t i = 0; i < orientation_length; i++){
      offset += this->st_orientation.deserialize(inbuffer + offset);
        memcpy( &(this->orientation[i]), &(this->st_orientation), sizeof(geometry_msgs::Quaternion));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/SoundLocation"; };
    virtual const char * getMD5() override { return "1d6099487ad91df0521eab1e92146a95"; };

  };

}
#endif
