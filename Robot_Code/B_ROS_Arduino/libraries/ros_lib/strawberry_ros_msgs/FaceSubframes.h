#ifndef _ROS_strawberry_ros_msgs_FaceSubframes_h
#define _ROS_strawberry_ros_msgs_FaceSubframes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/FaceSubframe.h"

namespace strawberry_ros_msgs
{

  class FaceSubframes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t face_subframes_length;
      typedef strawberry_ros_msgs::FaceSubframe _face_subframes_type;
      _face_subframes_type st_face_subframes;
      _face_subframes_type * face_subframes;

    FaceSubframes():
      header(),
      face_subframes_length(0), st_face_subframes(), face_subframes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->face_subframes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->face_subframes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->face_subframes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->face_subframes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->face_subframes_length);
      for( uint32_t i = 0; i < face_subframes_length; i++){
      offset += this->face_subframes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t face_subframes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      face_subframes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      face_subframes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      face_subframes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->face_subframes_length);
      if(face_subframes_lengthT > face_subframes_length)
        this->face_subframes = (strawberry_ros_msgs::FaceSubframe*)realloc(this->face_subframes, face_subframes_lengthT * sizeof(strawberry_ros_msgs::FaceSubframe));
      face_subframes_length = face_subframes_lengthT;
      for( uint32_t i = 0; i < face_subframes_length; i++){
      offset += this->st_face_subframes.deserialize(inbuffer + offset);
        memcpy( &(this->face_subframes[i]), &(this->st_face_subframes), sizeof(strawberry_ros_msgs::FaceSubframe));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/FaceSubframes"; };
    virtual const char * getMD5() override { return "6537a2afad6ec1a399ad8a14c3f23233"; };

  };

}
#endif
