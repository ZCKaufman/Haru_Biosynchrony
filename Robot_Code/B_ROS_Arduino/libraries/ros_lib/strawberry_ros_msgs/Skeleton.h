#ifndef _ROS_strawberry_ros_msgs_Skeleton_h
#define _ROS_strawberry_ros_msgs_Skeleton_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/BoundingBox.h"
#include "strawberry_ros_msgs/BodyPart.h"
#include "strawberry_ros_msgs/Gesture.h"

namespace strawberry_ros_msgs
{

  class Skeleton : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      uint32_t head_at_img_length;
      typedef strawberry_ros_msgs::BoundingBox _head_at_img_type;
      _head_at_img_type st_head_at_img;
      _head_at_img_type * head_at_img;
      uint32_t body_parts_length;
      typedef strawberry_ros_msgs::BodyPart _body_parts_type;
      _body_parts_type st_body_parts;
      _body_parts_type * body_parts;
      uint32_t gestures_length;
      typedef strawberry_ros_msgs::Gesture _gestures_type;
      _gestures_type st_gestures;
      _gestures_type * gestures;

    Skeleton():
      person_id(0),
      head_at_img_length(0), st_head_at_img(), head_at_img(nullptr),
      body_parts_length(0), st_body_parts(), body_parts(nullptr),
      gestures_length(0), st_gestures(), gestures(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      *(outbuffer + offset + 0) = (this->head_at_img_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->head_at_img_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->head_at_img_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->head_at_img_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->head_at_img_length);
      for( uint32_t i = 0; i < head_at_img_length; i++){
      offset += this->head_at_img[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->body_parts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_parts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_parts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_parts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_parts_length);
      for( uint32_t i = 0; i < body_parts_length; i++){
      offset += this->body_parts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->gestures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gestures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gestures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gestures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gestures_length);
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->gestures[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
      uint32_t head_at_img_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      head_at_img_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      head_at_img_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      head_at_img_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->head_at_img_length);
      if(head_at_img_lengthT > head_at_img_length)
        this->head_at_img = (strawberry_ros_msgs::BoundingBox*)realloc(this->head_at_img, head_at_img_lengthT * sizeof(strawberry_ros_msgs::BoundingBox));
      head_at_img_length = head_at_img_lengthT;
      for( uint32_t i = 0; i < head_at_img_length; i++){
      offset += this->st_head_at_img.deserialize(inbuffer + offset);
        memcpy( &(this->head_at_img[i]), &(this->st_head_at_img), sizeof(strawberry_ros_msgs::BoundingBox));
      }
      uint32_t body_parts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      body_parts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      body_parts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      body_parts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->body_parts_length);
      if(body_parts_lengthT > body_parts_length)
        this->body_parts = (strawberry_ros_msgs::BodyPart*)realloc(this->body_parts, body_parts_lengthT * sizeof(strawberry_ros_msgs::BodyPart));
      body_parts_length = body_parts_lengthT;
      for( uint32_t i = 0; i < body_parts_length; i++){
      offset += this->st_body_parts.deserialize(inbuffer + offset);
        memcpy( &(this->body_parts[i]), &(this->st_body_parts), sizeof(strawberry_ros_msgs::BodyPart));
      }
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
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Skeleton"; };
    virtual const char * getMD5() override { return "658251c1f8f30c881d46d719a18f18e0"; };

  };

}
#endif
