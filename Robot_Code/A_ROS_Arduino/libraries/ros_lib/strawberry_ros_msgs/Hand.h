#ifndef _ROS_strawberry_ros_msgs_Hand_h
#define _ROS_strawberry_ros_msgs_Hand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/BoundingBox.h"
#include "geometry_msgs/Point.h"
#include "strawberry_ros_msgs/Gesture.h"
#include "strawberry_ros_msgs/HandPart.h"

namespace strawberry_ros_msgs
{

  class Hand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _hand_id_type;
      _hand_id_type hand_id;
      typedef uint8_t _type_type;
      _type_type type;
      typedef strawberry_ros_msgs::BoundingBox _hand_at_img_type;
      _hand_at_img_type hand_at_img;
      typedef geometry_msgs::Point _direction_type;
      _direction_type direction;
      uint32_t gestures_length;
      typedef strawberry_ros_msgs::Gesture _gestures_type;
      _gestures_type st_gestures;
      _gestures_type * gestures;
      uint32_t hand_parts_length;
      typedef strawberry_ros_msgs::HandPart _hand_parts_type;
      _hand_parts_type st_hand_parts;
      _hand_parts_type * hand_parts;
      typedef float _confidence_type;
      _confidence_type confidence;
      enum { TYPE_LEFT = 0 };
      enum { TYPE_RIGHT = 1 };

    Hand():
      header(),
      hand_id(0),
      type(0),
      hand_at_img(),
      direction(),
      gestures_length(0), st_gestures(), gestures(nullptr),
      hand_parts_length(0), st_hand_parts(), hand_parts(nullptr),
      confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->hand_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hand_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hand_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hand_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hand_id);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      offset += this->hand_at_img.serialize(outbuffer + offset);
      offset += this->direction.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->gestures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gestures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gestures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gestures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gestures_length);
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->gestures[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->hand_parts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hand_parts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hand_parts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hand_parts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hand_parts_length);
      for( uint32_t i = 0; i < hand_parts_length; i++){
      offset += this->hand_parts[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->hand_id =  ((uint32_t) (*(inbuffer + offset)));
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hand_id);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      offset += this->hand_at_img.deserialize(inbuffer + offset);
      offset += this->direction.deserialize(inbuffer + offset);
      uint32_t gestures_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gestures_length);
      if(gestures_lengthT > gestures_length)
        this->gestures = (strawberry_ros_msgs::Gesture*)realloc(this->gestures, gestures_lengthT * sizeof(strawberry_ros_msgs::Gesture));
      gestures_length = gestures_lengthT;
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->st_gestures.deserialize(inbuffer + offset);
        memcpy( &(this->gestures[i]), &(this->st_gestures), sizeof(strawberry_ros_msgs::Gesture));
      }
      uint32_t hand_parts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hand_parts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hand_parts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hand_parts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hand_parts_length);
      if(hand_parts_lengthT > hand_parts_length)
        this->hand_parts = (strawberry_ros_msgs::HandPart*)realloc(this->hand_parts, hand_parts_lengthT * sizeof(strawberry_ros_msgs::HandPart));
      hand_parts_length = hand_parts_lengthT;
      for( uint32_t i = 0; i < hand_parts_length; i++){
      offset += this->st_hand_parts.deserialize(inbuffer + offset);
        memcpy( &(this->hand_parts[i]), &(this->st_hand_parts), sizeof(strawberry_ros_msgs::HandPart));
      }
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Hand"; };
    virtual const char * getMD5() override { return "ea7f978951e337dfa686d1bbd01d36ef"; };

  };

}
#endif
