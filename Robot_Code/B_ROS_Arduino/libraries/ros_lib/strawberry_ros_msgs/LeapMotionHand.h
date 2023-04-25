#ifndef _ROS_strawberry_ros_msgs_LeapMotionHand_h
#define _ROS_strawberry_ros_msgs_LeapMotionHand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "strawberry_ros_msgs/Finger.h"

namespace strawberry_ros_msgs
{

  class LeapMotionHand : public ros::Msg
  {
    public:
      typedef uint32_t _hand_id_type;
      _hand_id_type hand_id;
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _name_type;
      _name_type name;
      float basis[9];
      typedef geometry_msgs::Point _direction_type;
      _direction_type direction;
      uint32_t fingers_length;
      typedef strawberry_ros_msgs::Finger _fingers_type;
      _fingers_type st_fingers;
      _fingers_type * fingers;
      enum { TYPE_LEFT = 0 };
      enum { TYPE_RIGHT = 1 };
      enum { LEFT = left };
      enum { RIGHT = right };

    LeapMotionHand():
      hand_id(0),
      type(0),
      name(""),
      basis(),
      direction(),
      fingers_length(0), st_fingers(), fingers(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->hand_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hand_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hand_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hand_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hand_id);
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
      *(outbuffer + offset + 0) = (this->fingers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fingers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fingers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fingers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fingers_length);
      for( uint32_t i = 0; i < fingers_length; i++){
      offset += this->fingers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->hand_id =  ((uint32_t) (*(inbuffer + offset)));
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hand_id);
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
      uint32_t fingers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fingers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fingers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fingers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fingers_length);
      if(fingers_lengthT > fingers_length)
        this->fingers = (strawberry_ros_msgs::Finger*)realloc(this->fingers, fingers_lengthT * sizeof(strawberry_ros_msgs::Finger));
      fingers_length = fingers_lengthT;
      for( uint32_t i = 0; i < fingers_length; i++){
      offset += this->st_fingers.deserialize(inbuffer + offset);
        memcpy( &(this->fingers[i]), &(this->st_fingers), sizeof(strawberry_ros_msgs::Finger));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/LeapMotionHand"; };
    virtual const char * getMD5() override { return "10f6e5d812ca8a840ea21dce0b977833"; };

  };

}
#endif
