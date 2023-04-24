#ifndef _ROS_strawberry_ros_msgs_Finger_h
#define _ROS_strawberry_ros_msgs_Finger_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/FingerPart.h"

namespace strawberry_ros_msgs
{

  class Finger : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _name_type;
      _name_type name;
      uint32_t fingerparts_length;
      typedef strawberry_ros_msgs::FingerPart _fingerparts_type;
      _fingerparts_type st_fingerparts;
      _fingerparts_type * fingerparts;
      enum { TYPE_THUMB = 0 };
      enum { TYPE_INDEX = 1 };
      enum { TYPE_MIDDLE = 2 };
      enum { TYPE_RING = 3 };
      enum { TYPE_PINKY = 4 };
      enum { THUMB = thumb };
      enum { INDEX = index };
      enum { MIDDLE = middle };
      enum { RING = ring };
      enum { PINKY = pinky };

    Finger():
      type(0),
      name(""),
      fingerparts_length(0), st_fingerparts(), fingerparts(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->fingerparts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fingerparts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fingerparts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fingerparts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fingerparts_length);
      for( uint32_t i = 0; i < fingerparts_length; i++){
      offset += this->fingerparts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t fingerparts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fingerparts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fingerparts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fingerparts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fingerparts_length);
      if(fingerparts_lengthT > fingerparts_length)
        this->fingerparts = (strawberry_ros_msgs::FingerPart*)realloc(this->fingerparts, fingerparts_lengthT * sizeof(strawberry_ros_msgs::FingerPart));
      fingerparts_length = fingerparts_lengthT;
      for( uint32_t i = 0; i < fingerparts_length; i++){
      offset += this->st_fingerparts.deserialize(inbuffer + offset);
        memcpy( &(this->fingerparts[i]), &(this->st_fingerparts), sizeof(strawberry_ros_msgs::FingerPart));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Finger"; };
    virtual const char * getMD5() override { return "dbe6976abb81d2a7dc9652ed4076e7f7"; };

  };

}
#endif
