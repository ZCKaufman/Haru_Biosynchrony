#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorShowDraw_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorShowDraw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorShowDraw : public ros::Msg
  {
    public:
      typedef const char* _ipad_id_local_type;
      _ipad_id_local_type ipad_id_local;
      typedef const char* _ipad_id_remote_type;
      _ipad_id_remote_type ipad_id_remote;
      typedef float _draw_delay_type;
      _draw_delay_type draw_delay;
      typedef bool _show_draw_canvas_type;
      _show_draw_canvas_type show_draw_canvas;
      typedef int32_t _show_mode_type;
      _show_mode_type show_mode;

    UnityProjectorShowDraw():
      ipad_id_local(""),
      ipad_id_remote(""),
      draw_delay(0),
      show_draw_canvas(0),
      show_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_ipad_id_local = strlen(this->ipad_id_local);
      varToArr(outbuffer + offset, length_ipad_id_local);
      offset += 4;
      memcpy(outbuffer + offset, this->ipad_id_local, length_ipad_id_local);
      offset += length_ipad_id_local;
      uint32_t length_ipad_id_remote = strlen(this->ipad_id_remote);
      varToArr(outbuffer + offset, length_ipad_id_remote);
      offset += 4;
      memcpy(outbuffer + offset, this->ipad_id_remote, length_ipad_id_remote);
      offset += length_ipad_id_remote;
      union {
        float real;
        uint32_t base;
      } u_draw_delay;
      u_draw_delay.real = this->draw_delay;
      *(outbuffer + offset + 0) = (u_draw_delay.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_draw_delay.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_draw_delay.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_draw_delay.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->draw_delay);
      union {
        bool real;
        uint8_t base;
      } u_show_draw_canvas;
      u_show_draw_canvas.real = this->show_draw_canvas;
      *(outbuffer + offset + 0) = (u_show_draw_canvas.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->show_draw_canvas);
      union {
        int32_t real;
        uint32_t base;
      } u_show_mode;
      u_show_mode.real = this->show_mode;
      *(outbuffer + offset + 0) = (u_show_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_show_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_show_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_show_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->show_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_ipad_id_local;
      arrToVar(length_ipad_id_local, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ipad_id_local; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ipad_id_local-1]=0;
      this->ipad_id_local = (char *)(inbuffer + offset-1);
      offset += length_ipad_id_local;
      uint32_t length_ipad_id_remote;
      arrToVar(length_ipad_id_remote, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ipad_id_remote; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ipad_id_remote-1]=0;
      this->ipad_id_remote = (char *)(inbuffer + offset-1);
      offset += length_ipad_id_remote;
      union {
        float real;
        uint32_t base;
      } u_draw_delay;
      u_draw_delay.base = 0;
      u_draw_delay.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_draw_delay.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_draw_delay.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_draw_delay.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->draw_delay = u_draw_delay.real;
      offset += sizeof(this->draw_delay);
      union {
        bool real;
        uint8_t base;
      } u_show_draw_canvas;
      u_show_draw_canvas.base = 0;
      u_show_draw_canvas.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->show_draw_canvas = u_show_draw_canvas.real;
      offset += sizeof(this->show_draw_canvas);
      union {
        int32_t real;
        uint32_t base;
      } u_show_mode;
      u_show_mode.base = 0;
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_show_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->show_mode = u_show_mode.real;
      offset += sizeof(this->show_mode);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorShowDraw"; };
    virtual const char * getMD5() override { return "f0a271589407a89ce2d5c7a12cac9d1d"; };

  };

}
#endif
