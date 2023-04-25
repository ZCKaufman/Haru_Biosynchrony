#ifndef _ROS_idmind_tabletop_msgs_RoutineResult_h
#define _ROS_idmind_tabletop_msgs_RoutineResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class RoutineResult : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _name_type;
      _name_type name;
      typedef bool _played_type;
      _played_type played;

    RoutineResult():
      id(0),
      name(""),
      played(0)
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
      union {
        bool real;
        uint8_t base;
      } u_played;
      u_played.real = this->played;
      *(outbuffer + offset + 0) = (u_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->played);
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
      union {
        bool real;
        uint8_t base;
      } u_played;
      u_played.base = 0;
      u_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->played = u_played.real;
      offset += sizeof(this->played);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/RoutineResult"; };
    virtual const char * getMD5() override { return "10d77fab4a10086e8e6472e71de67489"; };

  };

}
#endif
