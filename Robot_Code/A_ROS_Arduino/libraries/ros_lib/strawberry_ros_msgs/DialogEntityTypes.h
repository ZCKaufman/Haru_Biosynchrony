#ifndef _ROS_strawberry_ros_msgs_DialogEntityTypes_h
#define _ROS_strawberry_ros_msgs_DialogEntityTypes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/DialogEntityType.h"

namespace strawberry_ros_msgs
{

  class DialogEntityTypes : public ros::Msg
  {
    public:
      uint32_t entity_types_length;
      typedef strawberry_ros_msgs::DialogEntityType _entity_types_type;
      _entity_types_type st_entity_types;
      _entity_types_type * entity_types;

    DialogEntityTypes():
      entity_types_length(0), st_entity_types(), entity_types(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->entity_types_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entity_types_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entity_types_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entity_types_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entity_types_length);
      for( uint32_t i = 0; i < entity_types_length; i++){
      offset += this->entity_types[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t entity_types_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entity_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entity_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entity_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entity_types_length);
      if(entity_types_lengthT > entity_types_length)
        this->entity_types = (strawberry_ros_msgs::DialogEntityType*)realloc(this->entity_types, entity_types_lengthT * sizeof(strawberry_ros_msgs::DialogEntityType));
      entity_types_length = entity_types_lengthT;
      for( uint32_t i = 0; i < entity_types_length; i++){
      offset += this->st_entity_types.deserialize(inbuffer + offset);
        memcpy( &(this->entity_types[i]), &(this->st_entity_types), sizeof(strawberry_ros_msgs::DialogEntityType));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogEntityTypes"; };
    virtual const char * getMD5() override { return "17b875f0e487ee8d56361a51b1fd5e64"; };

  };

}
#endif
