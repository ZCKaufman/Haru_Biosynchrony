#ifndef _ROS_idmind_tabletop_msgs_MultiRoutineResult_h
#define _ROS_idmind_tabletop_msgs_MultiRoutineResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MultiRoutineResult : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef bool _played_type;
      _played_type played;
      typedef const char* _routine_command_type;
      _routine_command_type routine_command;
      typedef const char* _routine_list_type;
      _routine_list_type routine_list;

    MultiRoutineResult():
      id(0),
      played(0),
      routine_command(""),
      routine_list("")
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
      union {
        bool real;
        uint8_t base;
      } u_played;
      u_played.real = this->played;
      *(outbuffer + offset + 0) = (u_played.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->played);
      uint32_t length_routine_command = strlen(this->routine_command);
      varToArr(outbuffer + offset, length_routine_command);
      offset += 4;
      memcpy(outbuffer + offset, this->routine_command, length_routine_command);
      offset += length_routine_command;
      uint32_t length_routine_list = strlen(this->routine_list);
      varToArr(outbuffer + offset, length_routine_list);
      offset += 4;
      memcpy(outbuffer + offset, this->routine_list, length_routine_list);
      offset += length_routine_list;
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
      union {
        bool real;
        uint8_t base;
      } u_played;
      u_played.base = 0;
      u_played.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->played = u_played.real;
      offset += sizeof(this->played);
      uint32_t length_routine_command;
      arrToVar(length_routine_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routine_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routine_command-1]=0;
      this->routine_command = (char *)(inbuffer + offset-1);
      offset += length_routine_command;
      uint32_t length_routine_list;
      arrToVar(length_routine_list, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routine_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routine_list-1]=0;
      this->routine_list = (char *)(inbuffer + offset-1);
      offset += length_routine_list;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MultiRoutineResult"; };
    virtual const char * getMD5() override { return "6e4e8450f5cc11eff0045fe4470306f2"; };

  };

}
#endif
