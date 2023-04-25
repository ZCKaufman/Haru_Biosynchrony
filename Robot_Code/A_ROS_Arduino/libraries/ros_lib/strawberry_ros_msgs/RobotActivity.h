#ifndef _ROS_strawberry_ros_msgs_RobotActivity_h
#define _ROS_strawberry_ros_msgs_RobotActivity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

  class RobotActivity : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _name_type;
      _name_type name;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef const char* _current_animation_type;
      _current_animation_type current_animation;
      typedef geometry_msgs::Point _looking_direction_type;
      _looking_direction_type looking_direction;
      typedef const char* _looking_at_type;
      _looking_at_type looking_at;
      typedef int32_t _looking_at_id_type;
      _looking_at_id_type looking_at_id;

    RobotActivity():
      id(0),
      name(""),
      position(),
      current_animation(""),
      looking_direction(),
      looking_at(""),
      looking_at_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->position.serialize(outbuffer + offset);
      uint32_t length_current_animation = strlen(this->current_animation);
      varToArr(outbuffer + offset, length_current_animation);
      offset += 4;
      memcpy(outbuffer + offset, this->current_animation, length_current_animation);
      offset += length_current_animation;
      offset += this->looking_direction.serialize(outbuffer + offset);
      uint32_t length_looking_at = strlen(this->looking_at);
      varToArr(outbuffer + offset, length_looking_at);
      offset += 4;
      memcpy(outbuffer + offset, this->looking_at, length_looking_at);
      offset += length_looking_at;
      union {
        int32_t real;
        uint32_t base;
      } u_looking_at_id;
      u_looking_at_id.real = this->looking_at_id;
      *(outbuffer + offset + 0) = (u_looking_at_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_looking_at_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_looking_at_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_looking_at_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->looking_at_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->position.deserialize(inbuffer + offset);
      uint32_t length_current_animation;
      arrToVar(length_current_animation, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_animation; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_animation-1]=0;
      this->current_animation = (char *)(inbuffer + offset-1);
      offset += length_current_animation;
      offset += this->looking_direction.deserialize(inbuffer + offset);
      uint32_t length_looking_at;
      arrToVar(length_looking_at, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_looking_at; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_looking_at-1]=0;
      this->looking_at = (char *)(inbuffer + offset-1);
      offset += length_looking_at;
      union {
        int32_t real;
        uint32_t base;
      } u_looking_at_id;
      u_looking_at_id.base = 0;
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->looking_at_id = u_looking_at_id.real;
      offset += sizeof(this->looking_at_id);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/RobotActivity"; };
    virtual const char * getMD5() override { return "8eb5a8c6dc59b806a1afcdc6ce8f6ce1"; };

  };

}
#endif
