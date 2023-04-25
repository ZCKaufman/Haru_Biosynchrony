#ifndef _ROS_strawberry_ros_msgs_Interactions_h
#define _ROS_strawberry_ros_msgs_Interactions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/PersonActivity.h"
#include "strawberry_ros_msgs/RobotActivity.h"
#include "strawberry_ros_msgs/Object.h"

namespace strawberry_ros_msgs
{

  class Interactions : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t people_length;
      typedef strawberry_ros_msgs::PersonActivity _people_type;
      _people_type st_people;
      _people_type * people;
      uint32_t robots_length;
      typedef strawberry_ros_msgs::RobotActivity _robots_type;
      _robots_type st_robots;
      _robots_type * robots;
      uint32_t objects_length;
      typedef strawberry_ros_msgs::Object _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    Interactions():
      header(),
      people_length(0), st_people(), people(nullptr),
      robots_length(0), st_robots(), robots(nullptr),
      objects_length(0), st_objects(), objects(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->people_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->people_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->people_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->people_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->people_length);
      for( uint32_t i = 0; i < people_length; i++){
      offset += this->people[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->robots_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robots_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robots_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robots_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robots_length);
      for( uint32_t i = 0; i < robots_length; i++){
      offset += this->robots[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objects_length);
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t people_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->people_length);
      if(people_lengthT > people_length)
        this->people = (strawberry_ros_msgs::PersonActivity*)realloc(this->people, people_lengthT * sizeof(strawberry_ros_msgs::PersonActivity));
      people_length = people_lengthT;
      for( uint32_t i = 0; i < people_length; i++){
      offset += this->st_people.deserialize(inbuffer + offset);
        memcpy( &(this->people[i]), &(this->st_people), sizeof(strawberry_ros_msgs::PersonActivity));
      }
      uint32_t robots_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robots_length);
      if(robots_lengthT > robots_length)
        this->robots = (strawberry_ros_msgs::RobotActivity*)realloc(this->robots, robots_lengthT * sizeof(strawberry_ros_msgs::RobotActivity));
      robots_length = robots_lengthT;
      for( uint32_t i = 0; i < robots_length; i++){
      offset += this->st_robots.deserialize(inbuffer + offset);
        memcpy( &(this->robots[i]), &(this->st_robots), sizeof(strawberry_ros_msgs::RobotActivity));
      }
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (strawberry_ros_msgs::Object*)realloc(this->objects, objects_lengthT * sizeof(strawberry_ros_msgs::Object));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(strawberry_ros_msgs::Object));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Interactions"; };
    virtual const char * getMD5() override { return "efec5a2a7f55e5b6221c13d9240c826c"; };

  };

}
#endif
