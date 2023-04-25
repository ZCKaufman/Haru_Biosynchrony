#ifndef _ROS_strawberry_ros_msgs_DialogEntity_h
#define _ROS_strawberry_ros_msgs_DialogEntity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class DialogEntity : public ros::Msg
  {
    public:
      typedef const char* _value_type;
      _value_type value;
      uint32_t synonyms_length;
      typedef char* _synonyms_type;
      _synonyms_type st_synonyms;
      _synonyms_type * synonyms;

    DialogEntity():
      value(""),
      synonyms_length(0), st_synonyms(), synonyms(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      *(outbuffer + offset + 0) = (this->synonyms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->synonyms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->synonyms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->synonyms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->synonyms_length);
      for( uint32_t i = 0; i < synonyms_length; i++){
      uint32_t length_synonymsi = strlen(this->synonyms[i]);
      varToArr(outbuffer + offset, length_synonymsi);
      offset += 4;
      memcpy(outbuffer + offset, this->synonyms[i], length_synonymsi);
      offset += length_synonymsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
      uint32_t synonyms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      synonyms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      synonyms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      synonyms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->synonyms_length);
      if(synonyms_lengthT > synonyms_length)
        this->synonyms = (char**)realloc(this->synonyms, synonyms_lengthT * sizeof(char*));
      synonyms_length = synonyms_lengthT;
      for( uint32_t i = 0; i < synonyms_length; i++){
      uint32_t length_st_synonyms;
      arrToVar(length_st_synonyms, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_synonyms; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_synonyms-1]=0;
      this->st_synonyms = (char *)(inbuffer + offset-1);
      offset += length_st_synonyms;
        memcpy( &(this->synonyms[i]), &(this->st_synonyms), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogEntity"; };
    virtual const char * getMD5() override { return "7356aefd8aa45c308eac5e9c0d9854a8"; };

  };

}
#endif
