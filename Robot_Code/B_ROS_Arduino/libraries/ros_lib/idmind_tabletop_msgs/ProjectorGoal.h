#ifndef _ROS_idmind_tabletop_msgs_ProjectorGoal_h
#define _ROS_idmind_tabletop_msgs_ProjectorGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class ProjectorGoal : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef bool _loop_type;
      _loop_type loop;
      typedef uint32_t _start_time_type;
      _start_time_type start_time;
      typedef uint32_t _end_time_type;
      _end_time_type end_time;
      typedef bool _wait_to_finish_type;
      _wait_to_finish_type wait_to_finish;
      typedef bool _keep_last_frame_type;
      _keep_last_frame_type keep_last_frame;
      typedef uint8_t _scale_type_type;
      _scale_type_type scale_type;

    ProjectorGoal():
      file(""),
      loop(0),
      start_time(0),
      end_time(0),
      wait_to_finish(0),
      keep_last_frame(0),
      scale_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      *(outbuffer + offset + 0) = (this->start_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_time);
      *(outbuffer + offset + 0) = (this->end_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_time);
      union {
        bool real;
        uint8_t base;
      } u_wait_to_finish;
      u_wait_to_finish.real = this->wait_to_finish;
      *(outbuffer + offset + 0) = (u_wait_to_finish.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wait_to_finish);
      union {
        bool real;
        uint8_t base;
      } u_keep_last_frame;
      u_keep_last_frame.real = this->keep_last_frame;
      *(outbuffer + offset + 0) = (u_keep_last_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->keep_last_frame);
      *(outbuffer + offset + 0) = (this->scale_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->scale_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      this->start_time =  ((uint32_t) (*(inbuffer + offset)));
      this->start_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_time);
      this->end_time =  ((uint32_t) (*(inbuffer + offset)));
      this->end_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end_time);
      union {
        bool real;
        uint8_t base;
      } u_wait_to_finish;
      u_wait_to_finish.base = 0;
      u_wait_to_finish.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wait_to_finish = u_wait_to_finish.real;
      offset += sizeof(this->wait_to_finish);
      union {
        bool real;
        uint8_t base;
      } u_keep_last_frame;
      u_keep_last_frame.base = 0;
      u_keep_last_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->keep_last_frame = u_keep_last_frame.real;
      offset += sizeof(this->keep_last_frame);
      this->scale_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->scale_type);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ProjectorGoal"; };
    virtual const char * getMD5() override { return "db7a4df84552315893bd964f88b4f2fa"; };

  };

}
#endif
