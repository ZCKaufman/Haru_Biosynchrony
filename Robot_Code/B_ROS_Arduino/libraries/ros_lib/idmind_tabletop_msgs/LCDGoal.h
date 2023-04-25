#ifndef _ROS_idmind_tabletop_msgs_LCDGoal_h
#define _ROS_idmind_tabletop_msgs_LCDGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LCDGoal : public ros::Msg
  {
    public:
      typedef const char* _left_eye_file_type;
      _left_eye_file_type left_eye_file;
      typedef const char* _right_eye_file_type;
      _right_eye_file_type right_eye_file;
      typedef uint32_t _start_time_type;
      _start_time_type start_time;
      typedef uint32_t _end_time_type;
      _end_time_type end_time;
      typedef bool _loop_type;
      _loop_type loop;
      typedef bool _wait_to_finish_type;
      _wait_to_finish_type wait_to_finish;

    LCDGoal():
      left_eye_file(""),
      right_eye_file(""),
      start_time(0),
      end_time(0),
      loop(0),
      wait_to_finish(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_left_eye_file = strlen(this->left_eye_file);
      varToArr(outbuffer + offset, length_left_eye_file);
      offset += 4;
      memcpy(outbuffer + offset, this->left_eye_file, length_left_eye_file);
      offset += length_left_eye_file;
      uint32_t length_right_eye_file = strlen(this->right_eye_file);
      varToArr(outbuffer + offset, length_right_eye_file);
      offset += 4;
      memcpy(outbuffer + offset, this->right_eye_file, length_right_eye_file);
      offset += length_right_eye_file;
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
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      union {
        bool real;
        uint8_t base;
      } u_wait_to_finish;
      u_wait_to_finish.real = this->wait_to_finish;
      *(outbuffer + offset + 0) = (u_wait_to_finish.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wait_to_finish);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_left_eye_file;
      arrToVar(length_left_eye_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_left_eye_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_left_eye_file-1]=0;
      this->left_eye_file = (char *)(inbuffer + offset-1);
      offset += length_left_eye_file;
      uint32_t length_right_eye_file;
      arrToVar(length_right_eye_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_right_eye_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_right_eye_file-1]=0;
      this->right_eye_file = (char *)(inbuffer + offset-1);
      offset += length_right_eye_file;
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
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      union {
        bool real;
        uint8_t base;
      } u_wait_to_finish;
      u_wait_to_finish.base = 0;
      u_wait_to_finish.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wait_to_finish = u_wait_to_finish.real;
      offset += sizeof(this->wait_to_finish);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDGoal"; };
    virtual const char * getMD5() override { return "651415c9341035d7127b3fcee9044023"; };

  };

}
#endif
