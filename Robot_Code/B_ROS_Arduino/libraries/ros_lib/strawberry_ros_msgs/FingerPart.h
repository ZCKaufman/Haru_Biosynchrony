#ifndef _ROS_strawberry_ros_msgs_FingerPart_h
#define _ROS_strawberry_ros_msgs_FingerPart_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

  class FingerPart : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _name_type;
      _name_type name;
      float basis[9];
      typedef geometry_msgs::Point _direction_type;
      _direction_type direction;
      typedef float _length_type;
      _length_type length;
      enum { TYPE_METACARPAL = 0 };
      enum { TYPE_PROXIMAL = 1 };
      enum { TYPE_INTERMEDIATE = 2 };
      enum { TYPE_DISTAL = 3 };
      enum { TYPE_TIP = 4 };
      enum { METACARPAL = metacarpal };
      enum { PROXIMAL = proximal };
      enum { INTERMEDIATE = intermediate };
      enum { DISTAL = distal };
      enum { TIP = tip };

    FingerPart():
      type(0),
      name(""),
      basis(),
      direction(),
      length(0)
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
      for( uint32_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->basis[i]);
      }
      offset += this->direction.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->length);
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
      for( uint32_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->basis[i]));
      }
      offset += this->direction.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/FingerPart"; };
    virtual const char * getMD5() override { return "5ad5c43e4c462583a29849d715b1fb7d"; };

  };

}
#endif
