#ifndef _ROS_strawberry_ros_msgs_ASRCustomClass_h
#define _ROS_strawberry_ros_msgs_ASRCustomClass_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class ASRCustomClass : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _custom_class_id_type;
      _custom_class_id_type custom_class_id;
      uint32_t items_length;
      typedef char* _items_type;
      _items_type st_items;
      _items_type * items;

    ASRCustomClass():
      name(""),
      custom_class_id(""),
      items_length(0), st_items(), items(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_custom_class_id = strlen(this->custom_class_id);
      varToArr(outbuffer + offset, length_custom_class_id);
      offset += 4;
      memcpy(outbuffer + offset, this->custom_class_id, length_custom_class_id);
      offset += length_custom_class_id;
      *(outbuffer + offset + 0) = (this->items_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->items_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->items_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->items_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->items_length);
      for( uint32_t i = 0; i < items_length; i++){
      uint32_t length_itemsi = strlen(this->items[i]);
      varToArr(outbuffer + offset, length_itemsi);
      offset += 4;
      memcpy(outbuffer + offset, this->items[i], length_itemsi);
      offset += length_itemsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_custom_class_id;
      arrToVar(length_custom_class_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_custom_class_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_custom_class_id-1]=0;
      this->custom_class_id = (char *)(inbuffer + offset-1);
      offset += length_custom_class_id;
      uint32_t items_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      items_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      items_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      items_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->items_length);
      if(items_lengthT > items_length)
        this->items = (char**)realloc(this->items, items_lengthT * sizeof(char*));
      items_length = items_lengthT;
      for( uint32_t i = 0; i < items_length; i++){
      uint32_t length_st_items;
      arrToVar(length_st_items, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_items; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_items-1]=0;
      this->st_items = (char *)(inbuffer + offset-1);
      offset += length_st_items;
        memcpy( &(this->items[i]), &(this->st_items), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/ASRCustomClass"; };
    virtual const char * getMD5() override { return "59e94f4f4d155062dafb3d7a0f7f85b7"; };

  };

}
#endif
