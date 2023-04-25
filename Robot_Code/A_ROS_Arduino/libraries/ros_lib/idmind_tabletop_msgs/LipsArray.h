#ifndef _ROS_idmind_tabletop_msgs_LipsArray_h
#define _ROS_idmind_tabletop_msgs_LipsArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/Lips.h"

namespace idmind_tabletop_msgs
{

  class LipsArray : public ros::Msg
  {
    public:
      typedef uint32_t _img_width_type;
      _img_width_type img_width;
      typedef uint32_t _img_height_type;
      _img_height_type img_height;
      uint32_t lips_length;
      typedef idmind_tabletop_msgs::Lips _lips_type;
      _lips_type st_lips;
      _lips_type * lips;

    LipsArray():
      img_width(0),
      img_height(0),
      lips_length(0), st_lips(), lips(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->img_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->img_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->img_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->img_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->img_width);
      *(outbuffer + offset + 0) = (this->img_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->img_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->img_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->img_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->img_height);
      *(outbuffer + offset + 0) = (this->lips_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lips_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lips_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lips_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lips_length);
      for( uint32_t i = 0; i < lips_length; i++){
      offset += this->lips[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->img_width =  ((uint32_t) (*(inbuffer + offset)));
      this->img_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->img_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->img_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->img_width);
      this->img_height =  ((uint32_t) (*(inbuffer + offset)));
      this->img_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->img_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->img_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->img_height);
      uint32_t lips_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lips_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lips_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lips_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lips_length);
      if(lips_lengthT > lips_length)
        this->lips = (idmind_tabletop_msgs::Lips*)realloc(this->lips, lips_lengthT * sizeof(idmind_tabletop_msgs::Lips));
      lips_length = lips_lengthT;
      for( uint32_t i = 0; i < lips_length; i++){
      offset += this->st_lips.deserialize(inbuffer + offset);
        memcpy( &(this->lips[i]), &(this->st_lips), sizeof(idmind_tabletop_msgs::Lips));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LipsArray"; };
    virtual const char * getMD5() override { return "19ab52198119a4d43888de79c9e79f56"; };

  };

}
#endif
