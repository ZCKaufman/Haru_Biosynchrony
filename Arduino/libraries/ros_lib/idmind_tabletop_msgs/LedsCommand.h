#ifndef _ROS_idmind_tabletop_msgs_LedsCommand_h
#define _ROS_idmind_tabletop_msgs_LedsCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LedsCommand : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _file_type;
      _file_type file;
      typedef uint8_t _action_type;
      _action_type action;
      typedef bool _loop_type;
      _loop_type loop;
      typedef float _fps_type;
      _fps_type fps;
      typedef uint8_t _jump_factor_type;
      _jump_factor_type jump_factor;
      typedef float _brightness_type;
      _brightness_type brightness;
      enum { MOUTH =  0 };
      enum { EYES =  1 };
      enum { SHOW =  0 };
      enum { PLAY =  1 };
      enum { STOP =  2 };
      enum { CLEAN =  2 };
      enum { MOUTH_WIDTH =  27 };
      enum { MOUTH_HEIGHT =  7 };
      enum { EYES_WIDTH =  20 };
      enum { EYES_HEIGHT =  10 };

    LedsCommand():
      type(0),
      file(""),
      action(0),
      loop(0),
      fps(0),
      jump_factor(0),
      brightness(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      offset += serializeAvrFloat64(outbuffer + offset, this->fps);
      *(outbuffer + offset + 0) = (this->jump_factor >> (8 * 0)) & 0xFF;
      offset += sizeof(this->jump_factor);
      offset += serializeAvrFloat64(outbuffer + offset, this->brightness);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fps));
      this->jump_factor =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->jump_factor);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->brightness));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LedsCommand"; };
    virtual const char * getMD5() override { return "111eb1e61813886fa996ffec52f8de83"; };

  };

}
#endif
