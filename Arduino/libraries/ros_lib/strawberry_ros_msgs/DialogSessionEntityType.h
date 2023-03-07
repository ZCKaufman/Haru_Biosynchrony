#ifndef _ROS_strawberry_ros_msgs_DialogSessionEntityType_h
#define _ROS_strawberry_ros_msgs_DialogSessionEntityType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/DialogEntity.h"

namespace strawberry_ros_msgs
{

  class DialogSessionEntityType : public ros::Msg
  {
    public:
      typedef const char* _display_name_type;
      _display_name_type display_name;
      typedef int8_t _entity_override_mode_type;
      _entity_override_mode_type entity_override_mode;
      uint32_t entities_length;
      typedef strawberry_ros_msgs::DialogEntity _entities_type;
      _entities_type st_entities;
      _entities_type * entities;
      enum { ENTITY_OVERRIDE_MODE_UNSPECIFIED =  0    };
      enum { ENTITY_OVERRIDE_MODE_OVERRIDE =  1       };
      enum { ENTITY_OVERRIDE_MODE_SUPPLEMENT =  2     };

    DialogSessionEntityType():
      display_name(""),
      entity_override_mode(0),
      entities_length(0), st_entities(), entities(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_display_name = strlen(this->display_name);
      varToArr(outbuffer + offset, length_display_name);
      offset += 4;
      memcpy(outbuffer + offset, this->display_name, length_display_name);
      offset += length_display_name;
      union {
        int8_t real;
        uint8_t base;
      } u_entity_override_mode;
      u_entity_override_mode.real = this->entity_override_mode;
      *(outbuffer + offset + 0) = (u_entity_override_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->entity_override_mode);
      *(outbuffer + offset + 0) = (this->entities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entities_length);
      for( uint32_t i = 0; i < entities_length; i++){
      offset += this->entities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_display_name;
      arrToVar(length_display_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_display_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_display_name-1]=0;
      this->display_name = (char *)(inbuffer + offset-1);
      offset += length_display_name;
      union {
        int8_t real;
        uint8_t base;
      } u_entity_override_mode;
      u_entity_override_mode.base = 0;
      u_entity_override_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->entity_override_mode = u_entity_override_mode.real;
      offset += sizeof(this->entity_override_mode);
      uint32_t entities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entities_length);
      if(entities_lengthT > entities_length)
        this->entities = (strawberry_ros_msgs::DialogEntity*)realloc(this->entities, entities_lengthT * sizeof(strawberry_ros_msgs::DialogEntity));
      entities_length = entities_lengthT;
      for( uint32_t i = 0; i < entities_length; i++){
      offset += this->st_entities.deserialize(inbuffer + offset);
        memcpy( &(this->entities[i]), &(this->st_entities), sizeof(strawberry_ros_msgs::DialogEntity));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogSessionEntityType"; };
    virtual const char * getMD5() override { return "eafd662b4c07c33fee99bf407492c3ac"; };

  };

}
#endif
